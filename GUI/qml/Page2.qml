import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.0
import QtQuick.Dialogs 1.2

Page2Form {

    property alias swarmSize: swarmSize
    property alias x1_min: x1_min
    property alias x1_max: x1_max
    property alias x2_min: x2_min
    property alias x2_max: x2_max
    property alias oneD_button: oneD_button
    property alias twoD_button: twoD_button
    property alias randomPosbutton: randomPosbutton
    property alias userPosbutton: userPosbutton



    SpinBox {
        id: swarmSize
        x: 44
        y: 134
        width: 157
        height: 40
        opacity: 0.7
        editable: true
        from: 1
        to: 2147483647
        value: 1
    }

    Label {
        id: sizeLabrel
        x: 44
        y: 110
        color: "#ffffff"
        text: qsTr("Swarm Size")
        font.pixelSize: 15
        font.bold: true
    }


    GroupBox {
        id: groupBox1
        x: 217
        y: 110
        width: 398
        height: 231
        clip: false
        visible: true


        TextField {
            id: x1_min
            x: -3
            y: 88
            validator: IntValidator {
                locale: "English"
            }
            width: 169
            height: 40
            clip: true
            color: "#000"
            background: Rectangle
            {
                color: "#DDD"
            }
            text: "0"
        }

        TextField {
            id: x1_max
            x: 192
            y: 88
            validator: IntValidator {
                locale: "English"
            }
            width: 169
            height: 40
            clip: true
            color: "#000"
            background: Rectangle
            {
                color: "#DDD"
            }
            text: "0"
        }



        TextField {
            id: x2_max
            x: 192
            y: 158
            validator: IntValidator {
                locale: "English"
            }
            width: 169
            height: 40
            clip: true
            color: "#000"
            background: Rectangle
            {
                color: "#DDD"
            }
            text: "0"
            visible: twoD_button.checked
        }


        TextField {
            id: x2_min
            x: -3
            y: 158
            validator: IntValidator {
                locale: "English"
            }
            width: 169
            height: 40
            clip: true
            color: "#000"
            background: Rectangle
            {
                color: "#DDD"
            }
            text: "0"
            visible: twoD_button.checked
        }



        Label {
            id: dimensionsLabel
            x: 54
            y: -5
            text: qsTr("Number of dimensions")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 15
        }

        Label {
            id: x1_maxlabel
            x: 192
            y: 64
            text: qsTr("Max of dimension 1 (x1)")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 14
        }


        Label {
            id: x2_maxlabel
            x: 192
            y: 134
            text: qsTr("Max of dimension 2 (x2)")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 14
            visible: twoD_button.checked
        }

        Label {
            id: x2_minlabel
            x: -2
            y: 134
            text: qsTr("Min of dimension 2 (x2)")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 14
            visible: twoD_button.checked
        }



        Label {
            id: x1_minlabel
            x: -2
            y: 65
            text: qsTr("Min of dimension 1 (x1)")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 14
        }

        RadioButton {
            id: oneD_button
            x: 34
            y: 19
            Text {
                x: 48
                y: 11
                text: qsTr("One")
                color: "#ffffff"
                font.bold: true
                font.pixelSize: 15
            }
        }

        RadioButton {
            id: twoD_button
            x: 192
            y: 19
            checked: true
            Text {
                x: 48
                y: 11
                text: qsTr("Two")
                color: "#ffffff"
                font.bold: true
                font.pixelSize: 15
            }
        }


    }



    GroupBox {
        id: groupBox2
        x: 44
        y: 180
        width: 157
        height: 161

        Label {
            id: startPosLabel
            x: 0
            y: 0
            width: 106
            height: 18
            color: "#ffffff"
            text: qsTr("Initialization")
            font.pixelSize: 15
            font.bold: true
        }

        RadioButton {
            id: randomPosbutton
            x: 0
            y: 33

            checked: true
            Text {
                x: 48
                y: 11
                color: "#ffffff"
                text: qsTr("Random")
                font.pixelSize: 15
                font.bold: true
            }
        }

        RadioButton {
            id: userPosbutton
            x: 0
            y: 92
            Text {
                x: 48
                y: 11
                color: "#ffffff"
                text: qsTr("Specified")
                font.pixelSize: 15
                font.bold: true
            }
        }


    }




    Button {
        id: positionFile
        x: 44
        y: 395
        width: 157
        height: 40
        text: qsTr("Positions Text File")
        opacity: 0.7
        onClicked: fileChooser.visible = true;
        visible: userPosbutton.checked
    }

    TextField {
        id: positionText
        x: 217
        y: 395
        width: 398
        height: 40
        color: "#ffffff"
        font.pixelSize: 15
        font.bold: true
        visible: userPosbutton.checked
    }

    FileDialog {
       id: fileChooser
       title: "Please choose a file"
       folder: shortcuts.home
       onAccepted: {
           positionText.text = ""+fileChooser.fileUrls;
       }
       visible: false
    }

}
