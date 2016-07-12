import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.0
import QtQuick.Dialogs 1.2

Page3Form {

    Label {
        id: resolutionLabel
        x: 31
        y: 93
        color: "#ffffff"
        text: qsTr("Resolution")
        font.bold: true
        font.pixelSize: 15
    }

    Label {
        id: instancesLabel
        x: 368
        y: 74
        width: 230
        height: 37
        color: "#ffffff"
        text: qsTr("Number of simultaneous instances")
        wrapMode: Text.Wrap
        font.bold: true
        font.pixelSize: 15
    }

    ComboBox {
        id: resolutionChoice
        x: 31
        y: 117
        width: 230
        height: 40
        transformOrigin: Item.Left
        opacity: 0.8
        clip: true
        model: [ "640x480", "1024x789", "1920x1080" ]
        currentIndex: 0
    }



    SpinBox {
        id: numInstances
        x: 368
        y: 117
        width: 230
        height: 40
        opacity: 0.7
        editable: true
        from: 1
        to: 4
        value: 1

    }

    Slider {
        id: renderSlider
        x: 31
        y: 204
        width: 567
        height: 40
        spacing: 3
        stepSize: 1
        to: 120
        from: 0
        snapMode: Slider.SnapAlways
        value: 60
    }

    Label {
        id: renderLabel
        x: 35
        y: 180
        color: "#ffffff"
        text: qsTr("Render Speed - ")
        font.pixelSize: 15
        font.bold: true
    }

    Label {
        id: ramLabel
        x: 35
        y: 274
        color: "#ffffff"
        text: qsTr("Max Ram Use - ")
        font.pixelSize: 15
        font.bold: true
    }

    Slider {
        id: ramSlider
        x: 31
        y: 298
        width: 567
        height: 40
        stepSize: 1
        snapMode: Slider.SnapAlways
        to: 2048
        from: 0
        value: 512

    }

    Label {
        id: renderValLabel
        x: 305
        y: 180
        color: "#ffffff"
        text: qsTr(renderSlider.value.toString())
        font.pixelSize: 15
        font.bold: true

    }

    Label {
        id: ramValLabel
        x: 300
        y: 274
        color: "#ffffff"
        text: qsTr(ramSlider.value.toString())
        font.pixelSize: 15
        font.bold: true

    }
}
