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

#include <config.h>

#include <QGLWidget>
#include <QGraphicsGridLayout>
#include <QGraphicsDropShadowEffect>
#include <QFutureWatcher>
#include <QSharedPointer>
#include <QDir>
#include <QtDebug>
#include <QPropertyAnimation>

#include <plexywindow.h>
#include <desktopwidget.h>

#include "abstractdesktopview.h"

namespace PlexyDesk
{

void AbstractDesktopView::enableOpenGL(bool state)
{
    if (state) {
        setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers |
                        QGL::StencilBuffer |
                        QGL::DoubleBuffer |
                        QGL::AlphaChannel)));
        setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
        setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing);
    } else {
        setViewport(new QWidget);
        setCacheMode(QGraphicsView::CacheBackground);
        setOptimizationFlags(QGraphicsView::DontSavePainterState);
        setOptimizationFlag(QGraphicsView::DontClipPainter);
        setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    }
}

void AbstractDesktopView::showLayer(const QString &layer)
{
    Q_UNUSED(layer);
}

/*
   \brief Adds an Widget Extension to Plexy Desktop, give the widget
   name in string i.e "clock" or "radio", the internals will
   take care of the loading the widget plugin name is correct

   \param name String name of the widget as specified by the desktop file

   \param layerName Name of the layer you want add the widget to
 */
}
