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

#include "imageplugin.h"
#include <pluginloader.h>
#include <desktopwidget.h>
#include <QDeclarativeContext>

ImagePlugin::ImagePlugin(QObject * /*object*/) :
    mFrameParentitem(0)
{
}

ImagePlugin::~ImagePlugin()
{
    if (mFrameParentitem)
        delete mFrameParentitem;
}

void ImagePlugin::searchImage()
{
}

void ImagePlugin::onDataReady()
{
}

void ImagePlugin::setData(const QVariantMap &data)
{
    QString photo_path = data["photo_path"].toString();
    if (! photo_path.isEmpty() || ! photo_path.isNull()) {
        mImageSource = photo_path;
        emit imageSourceChanged();
    }
}

QGraphicsItem *ImagePlugin::item()
{
   if (mFrameParentitem == NULL) {
       mFrameParentitem = new PhotoWidget(QRectF(0.0, 0.0, 400.0, 400.0));
       mFrameParentitem->enableDefaultBackground(true);
   }

   return mFrameParentitem;
}
