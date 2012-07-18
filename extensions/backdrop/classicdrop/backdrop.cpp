/*******************************************************************************
* This file is part of PlexyDesk.
*  Maintained by : Siraj Razick <siraj@kde.org>
*  Authored By  :
*
*  PlexyDesk is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  PlexyDesk is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with PlexyDesk. If not, see <http://www.gnu.org/licenses/lgpl.html>
*******************************************************************************/

#include <QDir>
#include <QPixmapCache>
#include <QDeclarativeContext>

#include <QtDebug>

#include "backdrop.h"
#include <desktopwidget.h>
#include <plexyconfig.h>


BgPlugin::BgPlugin(QObject *object)
    : BackgroundSource(object)
{
    // TODO: bug#112
    // read the theme name from settings

    mThemePack = new PlexyDesk::ThemepackLoader("default", this);
    mBackgroundPixmap =
      new QPixmap(QDir::toNativeSeparators(PlexyDesk::Config::getInstance()->wallpaper()));
    mBackgroundItem = NULL;
}

BgPlugin::~BgPlugin()
{
    if (mBackgroundItem) {
        delete mBackgroundItem;
    }

    if (mBackgroundPixmap) {
        delete mBackgroundPixmap;
    }

    if (mBlurAnimation) {
        delete mBlurAnimation;
    }

    if (mBlurEffect) {
        delete mBlurEffect;
    }
}

void  BgPlugin::setRect(const QRect &rect)
{
  mDesktopScreenRect = rect;
}

void BgPlugin::changeWallpaperItem()
{
    /*
     if (PlexyDesk::Config::getInstance()->isOpenGL()) {

          QDeclarativeContext *context = mBackgroundItem->engine()->rootContext();

          // TODO: Make use of the PlexyDesk::Config::getInstance()->wallpaperMode() option
          // to set the context backgroundImage fillMode
          context->setContextProperty("backgroundImage",
                 QDir::toNativeSeparators(PlexyDesk::Config::getInstance()->wallpaper()));

          mBackgroundItem->setSourceUrl(QUrl(mThemePack->qmlBackdropFromTheme()));
     }
     */

    QSize desktopSize = mDesktopScreenRect.size();
#ifdef Q_WS_WIN
    // A 1px hack to make the widget fullscreen and not covering the toolbar on Win
    desktopSize.setHeight(desktopSize.height()-1);
#endif

    if (mBackgroundPixmap) {
        delete mBackgroundPixmap;
    }

    mBackgroundPixmap = new QPixmap(PlexyDesk::Config::getInstance()->wallpaper());

    if (mBackgroundPixmap->isNull()) {
        return;
    }

    // TODO: Make use of the PlexyDesk::Config::getInstance()->wallpaperMode() option
    mBackgroundCache = mBackgroundPixmap->scaled(desktopSize.width(), desktopSize.height(),
                                                 Qt::IgnoreAspectRatio,
                                                 Qt::SmoothTransformation);
    mBackgroundItemPixmap->setPixmap(mBackgroundCache);

    if (mBackgroundPixmap)
       delete mBackgroundPixmap;

    mBackgroundPixmap = 0;
}

void BgPlugin::data(QVariant &data)
{
    QImage wall = data.value<QImage>();
    if (wall.isNull()) {
        wall = QImage::fromData(data.toByteArray());
	return;
    }

    emit dataChange();
}

QGraphicsItem *BgPlugin::item()
{
    if (mBackgroundItem == NULL) {
        QSize desktopSize;

        desktopSize = mDesktopScreenRect.size();
#ifdef Q_WS_WIN
        // A 1px hack to make the widget fullscreen and not covering the toolbar on Win
        desktopSize.setHeight(desktopSize.height()-1);
#endif


        //QPixmapCache::setCacheLimit((desktopSize.height()* desktopSize.width() * 32)/8);

        // TODO: Make use of the PlexyDesk::Config::getInstance()->wallpaperMode() option
        mBackgroundCache = mBackgroundPixmap->scaled(desktopSize.width(), desktopSize.height(),
               Qt::IgnoreAspectRatio,
               Qt::SmoothTransformation);


        //mBlurEffect = new QGraphicsBlurEffect();
        //mBlurEffect->setBlurHints(QGraphicsBlurEffect::AnimationHint);
        //mBlurAnimation = new QPropertyAnimation(mBlurEffect, "blurRadius");
        //mBlurAnimation->setDuration(100);
        //mBlurAnimation->setStartValue(5.0);
        //mBlurAnimation->setEndValue(0.0);

        connect(PlexyDesk::Config::getInstance(), SIGNAL(wallpaperChanged()),
                this, SLOT(changeWallpaperItem()));


        /*
        if (PlexyDesk::Config::getInstance()->isOpenGL()) {
                       mBackgroundItem = new PlexyDesk::QmlDesktopWidget(QRectF(0.0, 0.0, desktopSize.width(),
                    desktopSize.height()));

            QDeclarativeContext *context = mBackgroundItem->engine()->rootContext();
            context->setContextProperty("backgroundSize", desktopSize);
            context->setContextProperty("backgroundImage",
                QDir::toNativeSeparators(PlexyDesk::Config::getInstance()->wallpaper()));

            mBackgroundItem->setSourceUrl(QUrl(mThemePack->qmlBackdropFromTheme()));
            mBackgroundItem->setFlag(QGraphicsItem::ItemIsMovable, false);

            mBackgroundItem->setGraphicsEffect(mBlurEffect);
            mBackgroundItem->setCacheMode(QGraphicsItem::ItemCoordinateCache);
            mBlurAnimation->start();
            return mBackgroundItem;
        } */
        mBackgroundItemPixmap = new QGraphicsPixmapItem(mBackgroundCache);
        //mBackgroundItemPixmap->setGraphicsEffect(mBlurEffect);
        //mBackgroundItemPixmap->setCacheMode(QGraphicsItem::ItemCoordinateCache);
        //disable blur animatino to speed up
        //mBlurAnimation->start();
        delete mBackgroundPixmap;
        mBackgroundPixmap = 0;
        return mBackgroundItemPixmap;
    }
    
    return NULL;
}
