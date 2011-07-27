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
#include "backdrop.h"
#include <desktopwidget.h>
#include <plexyconfig.h>
#include <QDir>
#include <QPixmapCache>
#include <QDeclarativeContext>

BgPlugin::BgPlugin(QObject *object)
    : BackdropPlugin(object)
{
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


void BgPlugin::changeWallpaperItem()
{
     if (PlexyDesk::Config::getInstance()->isOpenGL()) {

          QDeclarativeContext *context = PlexyDesk::Config::qmlEngine()->rootContext();

          context->setContextProperty("backgroundImage",
                 QDir::toNativeSeparators(PlexyDesk::Config::getInstance()->wallpaper()));

          mBackgroundItem->qmlFromUrl(QUrl(mThemePack->qmlBackdropFromTheme()));
     } else {
         QSize desktopSize = QDesktopWidget().screenGeometry().size();

         if (mBackgroundPixmap) {
             delete mBackgroundPixmap;
         }

         mBackgroundPixmap = new QPixmap(PlexyDesk::Config::getInstance()->wallpaper());

         if (mBackgroundPixmap->isNull()) {
             return;
         }

         mBackgroundCache = mBackgroundPixmap->scaled(desktopSize.width(), desktopSize.height(),
                 Qt::KeepAspectRatioByExpanding,
                 Qt::SmoothTransformation);
         mBackgroundItemPixmap->setPixmap(mBackgroundCache);
    }

    mBlurAnimation->start();
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

        QDeclarativeContext *context = PlexyDesk::Config::qmlEngine()->rootContext();
        desktopSize = QDesktopWidget().screenGeometry().size();

        context->setContextProperty("backgroundSize", desktopSize);

        QPixmapCache::setCacheLimit((desktopSize.height()* desktopSize.width() * 32)/8);

        mBackgroundCache = mBackgroundPixmap->scaled(desktopSize.width(), desktopSize.height(),
                Qt::KeepAspectRatioByExpanding,
                Qt::SmoothTransformation);

        mBlurEffect = new QGraphicsBlurEffect();
        mBlurEffect->setBlurHints(QGraphicsBlurEffect::AnimationHint);
        mBlurAnimation = new QPropertyAnimation(mBlurEffect, "blurRadius");
        mBlurAnimation->setDuration(100);
        mBlurAnimation->setStartValue(5.0);
        mBlurAnimation->setEndValue(0.0);

        connect(PlexyDesk::Config::getInstance(), SIGNAL(wallpaperChanged()), 
                this, SLOT(changeWallpaperItem()));



        if (PlexyDesk::Config::getInstance()->isOpenGL()) {
            context->setContextProperty("backgroundImage",
                QDir::toNativeSeparators(PlexyDesk::Config::getInstance()->wallpaper()));

            mBackgroundItem = new PlexyDesk::DesktopWidget(QRectF(0.0, 0.0, desktopSize.width(),
                    desktopSize.height()));
            mBackgroundItem->qmlFromUrl(QUrl(mThemePack->qmlBackdropFromTheme()));
            mBackgroundItem->setFlag(QGraphicsItem::ItemIsMovable, false);

            mBackgroundItem->setGraphicsEffect(mBlurEffect);
            mBackgroundItem->setCacheMode(QGraphicsItem::ItemCoordinateCache);
            mBlurAnimation->start();
            return mBackgroundItem;
        } else {
            mBackgroundItemPixmap = new QGraphicsPixmapItem(mBackgroundCache);
            mBackgroundItemPixmap->setGraphicsEffect(mBlurEffect);
            mBackgroundItemPixmap->setCacheMode(QGraphicsItem::ItemCoordinateCache);
            mBlurAnimation->start();
            return mBackgroundItemPixmap;
        }

      }
}
