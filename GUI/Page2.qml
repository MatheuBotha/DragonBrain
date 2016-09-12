import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.0
import QtQuick.Dialogs 1.2

Page2Form {

    property alias objectiveChoice: objectiveChoice

ComboBox {
        id: objectiveChoice
        x: 0.1 * Screen.desktopAvailableWidth
        y: 0.15 * Screen.desktopAvailableHeight
        width: 0.8 * Screen.desktopAvailableWidth
        height: 0.1 * Screen.desktopAvailablHeight

        transformOrigin: Item.Left
        opacity: 0.8
        clip: true
        model: [ "Sin", "Saddle" ]
        currentIndex: 0
        font.pixelSize: 20
        font.bold: true
        font.family: "Helvetica"

    }

   Label {
        id: objectiveLabel
        anchors.left: objectiveChoice.left
        y: 0.1 * Screen.desktopAvailableHeight
        color: "#ffffff"
        text: qsTr("Objective Function")
        font.bold: true
        font.pixelSize: 15
    }


}
