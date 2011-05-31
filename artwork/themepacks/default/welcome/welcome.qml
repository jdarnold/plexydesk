/*******************************************************************************
* This file is part of PlexyDesk.
*  Maintained by : Siraj Razick <siraj@kde.org>
*  Authored By  : Varuna Lekamwasam <vrlekamwasam@gmail.com>
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
import Qt 4.7
import "scripts/Scripts.js" as Scripts
import "images"


Rectangle {

    id: rectangle1
    width: 400
    height: 200
    color: "#00000000"

    Text {
        id: gettingstarted
        x: 19
        y: 6
        color: "#ffffff"
        text: "Getting Started"
        style: Text.Raised
        anchors.left: parent.left
        anchors.leftMargin: 19
        anchors.top: parent.top
        anchors.topMargin: 6
        font.family: "Bitstream Charter"
        font.pixelSize: 40
        Behavior on opacity {
            NumberAnimation{duration : 100}
        }
    }

    Text {
        id: plexydesk
        color: "#ffffff"
        text: "PlexyDesk"
        style: Text.Raised
        anchors.top: gettingstarted.bottom
        anchors.topMargin: 10
        anchors.left: gettingstarted.right
        anchors.leftMargin: -50
        font.pixelSize: 30
        Behavior on opacity {
            NumberAnimation{duration : 100}
        }
    }

    Rectangle {
        id: item1
        x: 35
        y: 109
        width: 160
        height: 20
        color: "#7c7c7c"
        radius: 2
        Text {
            id: entry
            color: "#ffffff"
            text: "Desktop"
            style: Text.Sunken
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 12
        }

        MouseArea {
            id: itemclick
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color = "#b1b0b0"
            onExited: parent.color = "#7c7c7c"
            onClicked: Scripts.buttonClicked(rectangle1,"State1","Desktop",info_topic,info_desc)
        }
        Behavior on opacity {
            NumberAnimation{duration : 100}
        }
    }

    Rectangle {
        id: item2
        width: 160
        height: 20
        color: "#7c7c7c"
        radius: 2
        anchors.left: item1.left
        anchors.top: item1.bottom
        anchors.topMargin: 10
        Text {
            id: entry1
            color: "#ffffff"
            text: "Adding widgets"
            style: Text.Sunken
            font.pixelSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        MouseArea {
            id: itemclick1
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color = "#b1b0b0"
            onExited: parent.color = "#7c7c7c"
            onClicked: Scripts.buttonClicked(rectangle1,"State1","Adding Widgets",info_topic,info_desc)
        }
        Behavior on opacity {
            NumberAnimation{duration : 100}
        }
    }

    Rectangle {
        id: item3
        width: 160
        height: 20
        color: "#7c7c7c"
        radius: 2
        anchors.left: item2.left
        anchors.top: item2.bottom
        anchors.topMargin: 10
        Text {
            id: entry2
            color: "#ffffff"
            text: "Removing Widgets"
            style: Text.Sunken
            font.pixelSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        MouseArea {
            id: itemclick2
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color = "#b1b0b0"
            onExited: parent.color = "#7c7c7c"
            onClicked: Scripts.buttonClicked(rectangle1,"State1","Removing Widgets",info_topic,info_desc)
        }
        Behavior on opacity {
            NumberAnimation{duration : 100}
        }
    }

    Rectangle {
        id: item4
        width: 160
        height: 20
        color: "#7c7c7c"
        radius: 2
        anchors.leftMargin: 10
        anchors.left: item1.right
        anchors.verticalCenter: item1.verticalCenter
        Text {
            id: entry3
            color: "#ffffff"
            text: "Changing Wallpaper"
            style: Text.Sunken
            font.pixelSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        MouseArea {
            id: itemclick3
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color = "#b1b0b0"
            onExited: parent.color = "#7c7c7c"
            onClicked: Scripts.buttonClicked(rectangle1,"State1","Changing Wallpaper",info_topic,info_desc)
        }
        Behavior on opacity {
            NumberAnimation{duration : 100}
        }
    }

    Rectangle {
        id: item5
        width: 160
        height: 20
        color: "#7c7c7c"
        radius: 2
        anchors.left: item4.left
        anchors.top: item4.bottom
        anchors.topMargin: 10
        Text {
            id: entry4
            color: "#ffffff"
            text: "Development"
            style: Text.Sunken
            font.pixelSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        MouseArea {
            id: itemclick4
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color = "#b1b0b0"
            onExited: parent.color = "#7c7c7c"
            onClicked: Scripts.buttonClicked(rectangle1,"State1","Development",info_topic,info_desc)
        }
        Behavior on opacity {
            NumberAnimation{duration : 100}
        }
    }

    Rectangle {
        id: item6
        width: 160
        height: 20
        color: "#7c7c7c"
        radius: 2
        anchors.left: item5.left
        anchors.top: item5.bottom
        anchors.topMargin: 10
        Text {
            id: entry5
            color: "#ffffff"
            text: "Wiki"
            style: Text.Sunken
            font.pixelSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        MouseArea {
            id: itemclick5
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color = "#b1b0b0"
            onExited: parent.color = "#7c7c7c"
            onClicked: Scripts.buttonClicked(rectangle1,"State1","Wiki",info_topic,info_desc)
        }
        Behavior on opacity {
            NumberAnimation{duration : 100}
        }
    }

    Image {
        id: image1
        opacity: 0.8
        anchors.fill: parent
        z: -10
        source: "images/background.png"
    }

    Rectangle {
        id: information
        x: 0
        y: 0
        color: "#00000000"
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Rectangle {
            id: info_back
            width: 200
            height: 200
            color: "#ffffff"
            radius: 10
            opacity: 0
            anchors.fill: information
            anchors.margins: 15
            Behavior on opacity {
                NumberAnimation{duration: 200}
            }
        }

        Text {
            id: info_topic
            x: 31
            y: 20
            width: 94
            height: 23
            color: "#ffffff"
            text: "info_topic"
            style: Text.Raised
            font.pixelSize: 20
            opacity: 0
            Behavior on opacity {
                NumberAnimation{duration: 200}
            }
        }
        Text {
            id: info_desc
            x: 30
            y: 50
            width: 350
            color: "#ffffff"
            text: "info_desc"
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.pixelSize: 12
            opacity: 0
            Behavior on opacity {
                NumberAnimation{duration: 200}
            }
        }

        Image {
            id: backtohome
            x: 362
            y: 10
            width: 30
            height: 25
            source: "images/back.png"
            opacity: 0
            Behavior on opacity {
                NumberAnimation{duration: 200}
            }

            MouseArea {
                id: backClick
                anchors.fill: parent
                opacity: 0
                onClicked: Scripts.buttonClicked(rectangle1,"",info_topic.text,info_topic,info_desc)
            }
        }
    }
    states: [
        State {
            name: "State1"
            PropertyChanges {
                target: gettingstarted
                opacity: "0"
            }

            PropertyChanges {
                target: plexydesk
                opacity: "0"
            }

            PropertyChanges {
                target: item1
                opacity: "0"
            }

            PropertyChanges {
                target: item4
                opacity: "0"
            }

            PropertyChanges {
                target: itemclick1
            }

            PropertyChanges {
                target: item2
                opacity: 0
            }

            PropertyChanges {
                target: item3
                opacity: 0
            }

            PropertyChanges {
                target: item5
                opacity: 0
            }

            PropertyChanges {
                target: item6
                opacity: 0
            }

            PropertyChanges {
                target: info_back
                opacity: 0.2
            }

            PropertyChanges {
                target: info_desc
                x: 30
                y: 50
                width: 350
                color: "#ffffff"
                text: "info_desc"
                wrapMode: "WrapAtWordBoundaryOrAnywhere"
                font.underline: false
                style: "Normal"
                opacity: 1
            }

            PropertyChanges {
                target: info_topic
                x: 31
                y: 20
                color: "#ffffff"
                style: "Raised"
                font.underline: false
                font.pixelSize: 20
                opacity: 1
            }

            PropertyChanges {
                target: information
                x: 0
                y: 0
                anchors.topMargin: 0
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
            }

            PropertyChanges {
                target: backtohome
                x: 362
                y: 10
                width: 30
                height: 25
                fillMode: "PreserveAspectFit"
                source: "images/back.png"
                opacity: 1
            }

            PropertyChanges {
                target: backClick
                opacity: 1
            }
        }
    ]
    transitions:[ Transition {
        from: ""
        to: "State1"
        SequentialAnimation{
            ParallelAnimation
            {
                NumberAnimation { targets: [gettingstarted,plexydesk]; properties: "opacity"; duration: 500 }
            }
            NumberAnimation { targets: [item1,item4]; properties: "opacity"; duration: 200 }
            NumberAnimation { targets: [item2,item5]; properties: "opacity"; duration: 200 }
            NumberAnimation { targets: [item3,item6]; properties: "opacity"; duration: 200 }
            NumberAnimation { target: info_back; property: "opacity"; to: 0.2; duration: 200 }
            NumberAnimation { target: info_topic; property: "opacity"; to: 1; duration: 200 }
            ParallelAnimation{
            NumberAnimation { target: info_desc; property: "opacity"; to: 1; duration: 200 }
            NumberAnimation { target: backtohome; property: "opacity"; to: 1; duration: 200 }
            }
        }
    },
        Transition {
                from: "State1"
                to: ""
                SequentialAnimation{
                    ParallelAnimation{
                    NumberAnimation { target: info_desc; property: "opacity"; to: 0; duration: 200 }
                    NumberAnimation { target: backtohome; property: "opacity"; to: 0; duration: 200 }
                    }
                    NumberAnimation { target: info_topic; property: "opacity"; to: 0; duration: 200 }
                    NumberAnimation { target: info_back; property: "opacity"; to: 0; duration: 200 }
                    ParallelAnimation
                    {
                        NumberAnimation { targets: [gettingstarted,plexydesk]; properties: "opacity"; duration: 500 }
                    }
                    NumberAnimation { targets: [item1,item4]; properties: "opacity"; duration: 200 }
                    NumberAnimation { targets: [item2,item5]; properties: "opacity"; duration: 200 }
                    NumberAnimation { targets: [item3,item6]; properties: "opacity"; duration: 200 }
                }
            }
    ]
}
