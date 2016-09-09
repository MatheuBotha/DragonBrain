import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.0

Page1Form {
    scale: 1



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
        x: 381
        y: 64
        width: 230

        transformOrigin: Item.Left
        opacity: 0.8
        clip: true
        model: [ "Sin", "Saddle" ]
        currentIndex: 0

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
        x: 381
        y: 40
        color: "#ffffff"
        text: qsTr("Objective Function")
        font.bold: true
        font.pixelSize: 15
    }



    ToggleButton {
        id: toggleRunning
        x: 252
        y: 266
        width: 138
        height: 119
        text: qsTr("Optimizer On")
        onClicked: {
                     setPkg.lock(true);
                     setPkg.change(true);
                     setPkg.generateSettingsGeneral(page2.swarmSize.value);
                     setPkg.generateSettingsDomain(objectiveChoice.currentText, (page2.oneD_button.checked ? 1 : 2), parseInt(page2.x1_min.text), parseInt(page2.x1_max.text), parseInt(page2.x2_min.text),
                                           parseInt(page2.x2_max.text), parseFloat(page2.transformationA.text), parseFloat(page2.transformationB.text), parseFloat(page2.transformationC.text));
                     setPkg.generateSettingsGraphics(page3.resolutionChoice.currentText, page3.renderSlider.value, showLinks.checked,
                                           showPaths.checked, page3.ramSlider.value);
                     setPkg.generateSettingsOptimizer(algorithmChoice.currentText, page2.userPosbutton.checked, "Placeholder", parseFloat(inertia.text), parseFloat(cognitiveCoeff.text), parseFloat(socialCoeff.text), maxIterations.value, targetAcc.value);
                     setPkg.lock(false);
        }

    }


    Button {
        id: updateButton
        x: 242
        y: 391
        width: 157
        height: 40
        text: qsTr("Update Parameters")
        onClicked: {
                     setPkg.lock(true);
                     setPkg.change(true);
                     setPkg.generateSettingsGeneral(page2.swarmSize.value);
                     setPkg.generateSettingsDomain(objectiveChoice.currentText, (page2.oneD_button.checked ? 1 : 2), parseInt(page2.x1_min.text), parseInt(page2.x1_max.text), parseInt(page2.x2_min.text),
                                           parseInt(page2.x2_max.text), parseFloat(page2.transformationA.text), parseFloat(page2.transformationB.text), parseFloat(page2.transformationC.text));
                     setPkg.generateSettingsGraphics(page3.resolutionChoice.currentText, page3.renderSlider.value, showLinks.checked,
                                           showPaths.checked, page3.ramSlider.value);
                     setPkg.generateSettingsOptimizer(algorithmChoice.currentText, page2.userPosbutton.checked, "Placeholder", parseFloat(inertia.text), parseFloat(cognitiveCoeff.text), parseFloat(socialCoeff.text), maxIterations.value, targetAcc.value);
                     setPkg.lock(false);
                    }
        opacity: 0.7
    }



    TextField {
        id: cognitiveCoeff
        validator: DoubleValidator {
            locale: "English"
            decimals: 4
        }
        x: 31
        y: 143
        width: 180
        height: 40
        clip: true
        color: "#000"
        background: Rectangle
        {
            color: "#DDD"
        }
        visible: (algorithmChoice.displayText == "Fully Informed PSO" || algorithmChoice.displayText == "Conical Particle Swarm Optimization" ||
                  algorithmChoice.displayText == "Guaranteed Convergence PSO") ? true : false

        text: "1.0"
    }

    TextField {
        id: socialCoeff
        validator: DoubleValidator {
            locale: "English"
            decimals: 4
        }
        x: 231
        y: 143
        width: 180
        height: 40
        clip: true
        color: "#000"
        background: Rectangle
        {
            color: "#DDD"
        }
        visible: (algorithmChoice.displayText == "Fully Informed PSO" || algorithmChoice.displayText == "Conical Particle Swarm Optimization" ||
                  algorithmChoice.displayText == "Guaranteed Convergence PSO") ? true : false
        text: "1.0"
    }

    TextField {
        id: inertia

        validator: DoubleValidator {
            locale: "English"
            decimals: 4
        }
        x: 431
    y: 143
    width: 180
        height: 40
        clip: true
        color: "#000"
        background: Rectangle
        {
            color: "#DDD"
        }
        visible: (algorithmChoice.displayText == "Fully Informed PSO" || algorithmChoice.displayText == "Conical Particle Swarm Optimization" ||
                  algorithmChoice.displayText == "Guaranteed Convergence PSO") ? true : false
        text: "1.0"

    }

    Label {
        id: cognitiveLabel
        x: 31
        y: 119
        color: "#ffffff"
        visible: (algorithmChoice.displayText == "Fully Informed PSO" || algorithmChoice.displayText == "Conical Particle Swarm Optimization" ||
                  algorithmChoice.displayText == "Guaranteed Convergence PSO") ? true : false
        text: qsTr("Cognitive Coefficient")
        font.pixelSize: 15
        font.bold: true
    }

    Label {
        id: inertiaLabel
        x: 431
        y: 120
        color: "#ffffff"
        text: qsTr("Inertia")
        visible: (algorithmChoice.displayText == "Fully Informed PSO" || algorithmChoice.displayText == "Conical Particle Swarm Optimization" ||
                  algorithmChoice.displayText == "Guaranteed Convergence PSO") ? true : false
        font.pixelSize: 15
        font.bold: true
    }

    Label {
        id: socialLabel1
        x: 231
        y: 119
        color: "#ffffff"
        text: qsTr("Social Coefficient")
        visible: (algorithmChoice.displayText == "Fully Informed PSO" || algorithmChoice.displayText == "Conical Particle Swarm Optimization" ||
                  algorithmChoice.displayText == "Guaranteed Convergence PSO") ? true : false
        font.pixelSize: 15
        font.bold: true
    }



CheckBox {
    id: showLinks
    x: 38
    y: 339
    text: qsTr("")
    scale: 1.3
}

    Label {
        id: showLinksLabel
        x: 97
    y: 350
    width: 180
    color: "#ffffff"
    text: qsTr("Show Links")
    font.pixelSize: 15
    horizontalAlignment: Text.AlignLeft
    font.bold: true
    wrapMode: Text.WordWrap
}

CheckBox {
    id: showPaths
    x: 422
    y: 339
    text: qsTr("")
    scale: 1.3
}

    Label {
        id: showPathLabel
        x: 481
    y: 350
        width: 180
        color: "#ffffff"
        text: qsTr("Show Paths")
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 15
    font.bold: true
    wrapMode: Text.WordWrap
}

SpinBox {
    id: maxIterations
    x: 31
    y: 220
    width: 230
    height: 40
    opacity: 0.7
    from: 1
    value: 1
    editable: true
    to: 2147483647
}

SpinBox {
    id: targetAcc
    x: 381
    y: 220
    width: 230
    height: 40
    opacity: 0.7
    from: 1
    value: 1
    editable: true
    to: 100
}

Label {
    id: iterationLabel
    x: 31
    y: 196
    width: 180
    color: "#ffffff"
    text: qsTr("Max Iterations")
    horizontalAlignment: Text.AlignLeft
    font.pixelSize: 15
    font.bold: true
    wrapMode: Text.WordWrap
}

Label {
    id: accuracyLabel
    x: 381
    y: 196
    width: 180
    color: "#ffffff"
    text: qsTr("Accuracy cutoff (%)")
    horizontalAlignment: Text.AlignLeft
    font.pixelSize: 15
    font.bold: true
    wrapMode: Text.WordWrap
}



}

