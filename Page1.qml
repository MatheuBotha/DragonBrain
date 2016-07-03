import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.0

Page1Form {
    id: modeSlider

    ComboBox {
        id: algorithmChoice
        x: 31
        y: 64
        opacity: 0.8
        width: 230
        clip: true
        model: [ "Random Search", "Hill Climbing", "Conical Particle Swarm Optimization", "Guaranteed Convergence PSO",
        "Fully Informed PSO"]
        currentIndex: 0

    }
    ComboBox {
        id: objectiveChoice
        x: 368
        y: 64
        width: 230

        transformOrigin: Item.Left
        opacity: 0.8
        clip: true
        model: [ "Opt1", "Opt2", "Opt3", "Opt4", "Opt5", "Opt6", "Opt7", "Opt8", "Opt9", "Opt10" ]
        currentIndex: 0
    }

    ComboBox {
        id: resolutionChoice
        x: 31
        y: 238
        width: 230
        height: 40
        transformOrigin: Item.Left
        opacity: 0.8
        clip: true
        model: [ "640x480", "1024x789", "1920x1080" ]
        currentIndex: 0
    }



    Label {
        id: modeLabel
        x: 368
        y: 195
        width: 230
        height: 37
        color: "#ffffff"
        text: qsTr("Number of simultaneous visualizations")
        wrapMode: Text.Wrap
        font.bold: true
        font.pixelSize: 15
    }

    Label {
        id: algorithmLabel
        x: 31
        y: 40
        color: "#ffffff"
        text: qsTr("Optimization Algorithm")
        font.bold: true
        font.pixelSize: 15
    }

    Label {
        id: objectiveLabel
        x: 368
        y: 40
        color: "#ffffff"
        text: qsTr("Objective Function")
        font.bold: true
        font.pixelSize: 15
    }

    Label {
        id: resolutionLabel
        x: 31
        y: 214
        color: "#ffffff"
        text: qsTr("Resolution")
        font.bold: true
        font.pixelSize: 15
    }

    ToggleButton {
        id: toggleRunning
        x: 232
        y: 284
        width: 169
        height: 147
        text: qsTr("Optimizer On/Off")
    }


    SpinBox {
        id: numInstances
        x: 368
        y: 238
        width: 230
        height: 40
        opacity: 0.7
        editable: true
        from: 1
        to: 4
        value: 1

    }

    ComboBox {
        id: psoMode
        x: 31
        y: 143
        width: 230
        opacity: 0.8
        visible: (algorithmChoice.displayText == "Fully Informed PSO" || algorithmChoice.displayText == "Conical Particle Swarm Optimization" ||
                  algorithmChoice.displayText == "Guaranteed Convergence PSO") ? true : false
        clip: true
        currentIndex: 0
        model: [ "Social", "Cognitive", "Balanced" ]

    }

    Label {
        id: psoModeLabel
        x: 31
        y: 119
        color: "#ffffff"
        visible: (algorithmChoice.displayText == "Fully Informed PSO" || algorithmChoice.displayText == "Conical Particle Swarm optimization" ||
                  algorithmChoice.displayText == "Guaranteed Convergence PSO") ? true : false
        text: qsTr("PSO Mode")
        font.pixelSize: 15
        font.bold: true
    }




}
