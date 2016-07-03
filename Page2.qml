import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.0
import QtQuick.Dialogs 1.2

Page2Form {
    SpinBox {
        id: swarmSize
        x: 44
        y: 64
        width: 157
        height: 40
        opacity: 0.7
        editable: true
        from: -2147483647
        to: 2147483647
    }

    Label {
        id: sizeLabel
        x: 44
        y: 40
        color: "#ffffff"
        text: qsTr("Swarm Size")
        font.pixelSize: 15
        font.bold: true
    }


    GroupBox {
        id: groupBox1
        x: 234
        y: 35
        width: 398
        height: 278
        clip: false
        visible: true
        font.bold: true
        font.pixelSize: 15

        SpinBox {
            id: x1_min
            x: -3
            y: 88
            opacity: 0.7
            editable: true
            from: -2147483647
            to: 2147483647
        }

        SpinBox {
            id: x1_max
            x: 192
            y: 88
            opacity: 0.7
            editable: true
            from: -2147483647
            to: 2147483647
        }



        SpinBox {
            id: x2_max
            x: 192
            y: 210
            opacity: 0.7
            editable: true
            from: -2147483647
            to: 2147483647
            visible: twoD_button.checked
        }





        Label {
            id: x1_min2
            x: 54
            y: -5
            text: qsTr("Number of dimensions")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 15
        }

        Label {
            id: x1_maxlabel
            x: 194
            y: 63
            text: qsTr("Max of dimension 1 (x1)")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 15
        }


        Label {
            id: x2_maxlabel
            x: 192
            y: 186
            text: qsTr("Max of dimension 2 (x2)")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 15
            visible: twoD_button.checked
        }

        Label {
            id: x2_minlabel
            x: -5
            y: 186
            text: qsTr("Min of dimension 2 (x2)")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 15
            visible: twoD_button.checked
        }



        Label {
            id: x1_minlabel
            x: -2
            y: 63
            text: qsTr("Min of dimension 1 (x1)")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 15
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

        SpinBox {
            id: x2_min
            x: -3
            y: 210
            to: 2147483647
            opacity: 0.7
            editable: true
            visible: twoD_button.checked
            from: -2147483647
        }
    }



    GroupBox {
        id: groupBox2
        x: 44
        y: 113
        width: 157
        height: 200

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
        y: 340
        width: 157
        height: 40
        text: qsTr("Positions Text File")
        opacity: 0.7
        onClicked: fileChooser.visible = true;
        visible: userPosbutton.checked
    }

    TextField {
        id: positionText
        x: 234
        y: 340
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
