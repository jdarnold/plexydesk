/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

import Qt 4.7
import QtWebKit 1.0

import "content"

Rectangle {

    id: webBrowserParent
    width: 820; height: 620
    color: "transparent"

    Header {
        id: header
        editUrl: webBrowser.urlString
        width: headerSpace.width; height: headerSpace.height
        anchors.horizontalCenterOffset: 0
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        z: 100
    }


    Rectangle{
        property string urlString : "http://www.plexyplanet.org/"
        id: webBrowser
        width: 800
        height: 600
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        clip: true
        FlickableWebView {
            id: webView
            url: webBrowser.urlString
            onProgressChanged: header.urlChanged = false
            anchors { top: headerSpace.bottom; left: parent.left; right: parent.right; bottom: parent.bottom }
        }

        Item { id: headerSpace; width: parent.width; height: 62 }

        ScrollBar {
            scrollArea: webView; width: 8
            anchors { right: parent.right; top: header.bottom; bottom: parent.bottom }
        }

        ScrollBar {
            scrollArea: webView; height: 8; orientation: Qt.Horizontal
            anchors { right: parent.right; rightMargin: 8; left: parent.left; bottom: parent.bottom }
        }
    }
    Image {
        id: image1
        opacity: 0.5
        anchors.fill: parent
        asynchronous : true
        z: -10
        source: "image://plexydesk/qml_widget_background"
    }
}
