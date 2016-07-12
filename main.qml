import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.0
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    color: "#222222"
    property alias swipeView: swipeView
    property alias page1: page1
    property alias page2: page2
    property alias page3: page3
    flags: Qt.FramelessWindowHint | Qt.Window



    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
            id: page1
            x: 0
            y: 0
            clip: true
            rotation: 0
        }

        Page2 {
            id: page2
            x: 0
            y: 0
            clip: true
            rotation: 0
        }

        Page3 {
            id: page3
            x: 0
            y: 0
            clip: true
            rotation: 0
        }

    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("General Config")
        }
        TabButton {
            text: qsTr("Environmental Config")
        }
        TabButton {
            text: qsTr("System Config")
        }
    }


    Rectangle {
        id: titlebar
        color: "#444"
        anchors.top: parent.top
        width: parent.width
        height: 20
        MouseArea {
            anchors.fill: parent
            property real lastMouseX: 0
            property real lastMouseY: 0
            onPressed: {
                lastMouseX = mouseX
                lastMouseY = mouseY
            }
            onMouseXChanged: window.x += (mouseX - lastMouseX)
            onMouseYChanged: window.y += (mouseY - lastMouseY)
        }

        Rectangle {
            id: exitButton
            height: 20
            width: 40
            color: "#777"
            x: parent.width-width
            y: 0
            Text {
                text: qsTr("X")
                width: parent.width
                height: parent.height
                font.bold: false
                style: Text.Outline
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter


            }
            MouseArea {
                height: parent.height
                width: parent.width
                onClicked: window.close()
            }
        }
    }
}
