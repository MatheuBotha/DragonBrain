import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.0
import QtQuick.Dialogs 1.2

Page4Form {

    property alias transformationA: transformationA
    property alias transformationB: transformationB
    property alias transformationC: transformationC
    property alias objectiveChoice: objectiveChoice

ComboBox {
        id: objectiveChoice
        x: 31
        y: 64
        width: 230

        transformOrigin: Item.Left
        opacity: 0.8
        clip: true
        model: [ "Sin", "Saddle" ]
        currentIndex: 0

    }

   Label {
        id: objectiveLabel
        x: 31
        y: 40
        color: "#ffffff"
        text: qsTr("Objective Function")
        font.bold: true
        font.pixelSize: 15
    }

        TextField {
            id: transformationA
            validator: DoubleValidator {
                locale: "English"
                decimals: 4
            }
            x: 44
            y: 184

            width: 169
            clip: true

            color: "#000"
            background: Rectangle
            {
                color: "#DDD"
            }
            text: "1.0"
        }

        TextField {
            id: transformationB
            validator: DoubleValidator {
                locale: "English"
                decimals: 4
            }
            x: 244
            y: 184
            width: 169
            clip: true
            color: "#000"
            background: Rectangle
            {
                color: "#DDD"
            }
            text: "0.0"
        }

        TextField {
            id: transformationC
            validator: DoubleValidator {
                locale: "English"
                decimals: 4
            }

            x: 444
            y: 184
            width: 169
            clip: true
            color: "#000"
            background: Rectangle
            {
                color: "#DDD"
            }
            text: "0.0"
        }


        Label {
            id: transALabel
            x: 44
            y: 142
            width: 180
            color: "#ffffff"
            text: qsTr("Growth/Shrink rate (default:1)")
            horizontalAlignment: Text.AlignLeft
            wrapMode: Text.WordWrap
            font.pixelSize: 15
            font.bold: true



        }

        Label {
            id: transBLabel
            x: 244
            y: 142
            width: 180
            color: "#ffffff"
            text: qsTr("Horizontal Shift (default:0)")
            wrapMode: Text.WordWrap
            font.pixelSize: 15
            font.bold: true
        }

        Label {
            id: transCLabel
        x: 446
        y: 142
        width: 180
        color: "#ffffff"
        text: qsTr("Vertical Shift    (default:0)")
        wrapMode: Text.WordWrap
        font.pixelSize: 15
        font.bold: true
    }
}
