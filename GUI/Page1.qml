import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.0

Page1Form {
    scale: 1
    property int sWid: Screen.desktopAvailableWidth
    property int sHei: Screen.desktopAvailableHeight
    property int fontSize: (sWid > 1440) ? 15 : 6


    Label {  wrapMode: Text.WordWrap
        id: genConfigLabel
        anchors.left:  genConfig.left
        y: sHei * 0.04
        color: "#ffffff"
        text: qsTr("General Configuration")
        font.bold: true
        font.pixelSize: 20
        font.family: "Helvetica"

    }
    GroupBox
    {
        id: genConfig
        x: sWid * 0.02
        y: sHei * 0.03
        width: sWid * 0.46
        height: sHei * 0.43

        font.bold: true
        font.pixelSize: 20
//        font.pointSize: 20
        ComboBox {
                id: algorithmChoice
                x: sWid * 0.02
                y: sHei * 0.1
                opacity: 0.8
                width: sWid * 0.42
                clip: true
                model: [ "Hill Climbing", "Random Search", "Conical Particle Swarm Optimization", "Guaranteed Convergence PSO",
                "Fully Informed PSO"]
                currentIndex: 0

            }




            Label {  wrapMode: Text.WordWrap
                id: algorithmLabel
                x: sWid * 0.02
                y: sHei * 0.08
                color: "#ffffff"
                text: qsTr("Optimization Algorithm")
                font.bold: true
                font.pixelSize: 15
            }







            TextField {
                id: cognitiveCoeff
                validator: DoubleValidator {
                    locale: "English"
                    decimals: 4
                }
                x: sWid * 0.02
                y: sHei * 0.18
                width: parent.width * 0.25
                height: sHei * 0.038
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
                x: sWid * 0.02 + (parent.width * 0.35)
                y: sHei * 0.18
                width: parent.width * 0.25
                height: sHei * 0.038
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
                anchors.right: algorithmChoice.right
                y: sHei * 0.18
                width: parent.width * 0.25
                height: sHei * 0.038
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

            Label {  wrapMode: Text.WordWrap
                id: cognitiveLabel
                x: sWid * 0.02
                y: sHei * 0.15
                color: "#ffffff"
                visible: (algorithmChoice.displayText == "Fully Informed PSO" || algorithmChoice.displayText == "Conical Particle Swarm Optimization" ||
                          algorithmChoice.displayText == "Guaranteed Convergence PSO") ? true : false
                text: qsTr("Cognitive Coefficient")
                font.pixelSize: 15
                font.bold: true
            }

            Label {  wrapMode: Text.WordWrap
                id: inertiaLabel
                anchors.left: inertia.left
                y: sHei * 0.15
                color: "#ffffff"
                text: qsTr("Inertia")
                visible: (algorithmChoice.displayText == "Fully Informed PSO" || algorithmChoice.displayText == "Conical Particle Swarm Optimization" ||
                          algorithmChoice.displayText == "Guaranteed Convergence PSO") ? true : false
                font.pixelSize: 15
                font.bold: true
            }

            Label {  wrapMode: Text.WordWrap
                id: socialLabel1
                x: sWid * 0.02 + (parent.width * 0.35)
                y: sHei * 0.15
                color: "#ffffff"
                text: qsTr("Social Coefficient")
                visible: (algorithmChoice.displayText == "Fully Informed PSO" || algorithmChoice.displayText == "Conical Particle Swarm Optimization" ||
                          algorithmChoice.displayText == "Guaranteed Convergence PSO") ? true : false
                font.pixelSize: 15
                font.bold: true
            }



        CheckBox {
            id: showLinks
            anchors.left: targetAcc.left
            y: 0.37 * sHei
            text: qsTr("")
            scale: 1.3
            visible: (algorithmChoice.displayText == "Fully Informed PSO") ? true : false
        }

            Label {  wrapMode: Text.WordWrap
                id: showLinksLabel
            anchors.left: showLinks.right
    //x: 0.25 * sWid
            y: 0.37 * sHei
            width: 0.094 * sWid
            color: "#ffffff"
            text: qsTr("Show Links")
            font.pixelSize: 15
            horizontalAlignment: Text.AlignLeft
            font.bold: true
            visible: (algorithmChoice.displayText == "Fully Informed PSO") ? true : false
        }

        CheckBox {
            id: showPaths
            x: 0.02 * sWid
            y: 0.37 * sHei
            text: qsTr("")
            scale: 1.3
        }

            Label {  wrapMode: Text.WordWrap
                id: showPathLabel
                 anchors.left: showPaths.right
                 y: 0.37 * sHei
                 width: 0.094 * sWid
                color: "#ffffff"
                text: qsTr("Show Paths")
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 15
            font.bold: true
        }

        SpinBox {
            id: maxIterations
            anchors.left: cognitiveCoeff.left
            y: sHei * 0.25
            width: algorithmChoice.width * 0.45
            height: sHei * 0.075
            opacity: 0.7
            from: 1
            value: 1
            editable: true
            to: 2147483647
        }

        SpinBox {
            id: targetAcc
            anchors.right: inertia.right
            y: sHei * 0.25
            width: algorithmChoice.width * 0.45
            height: sHei * 0.075
            opacity: 0.7
            from: 1
            value: 1
            editable: true
            to: 100
        }

        Label {  wrapMode: Text.WordWrap
            id: iterationLabel
            anchors.left: cognitiveCoeff.left
            y: sHei * 0.23
            color: "#ffffff"
            text: qsTr("Max Iterations")
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 15
            font.bold: true
         }

        Label {  wrapMode: Text.WordWrap
            id: accuracyLabel
            anchors.left: targetAcc.left
            y: sHei * 0.23
            color: "#ffffff"
            text: qsTr("Accuracy cutoff (%)")
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 15
            font.bold: true
        }
}

Label {  wrapMode: Text.WordWrap
    id: envConfigLabel
    anchors.left:  envConfig.left
    y: sHei * 0.04
    color: "#ffffff"
    text: qsTr("Environmental Configuration")
    font.bold: true
    font.pixelSize: 20
    font.family: "Helvetica"
}


GroupBox
{
    id: envConfig
    x: sWid * 0.52
    y: sHei * 0.03
    width: sWid * 0.46
    height: sHei * 0.43

    font.bold: true
    font.pixelSize: 20



SpinBox {
    id: swarmSize
    x: sWid * 0.02
    y: sHei * 0.1
    width: parent.width * 0.3
    height: sHei * 0.05
    opacity: 0.7
    editable: true
    from: 1
    to: 2147483647
    value: 1
}

Label {  wrapMode: Text.WordWrap
    id: sizeLabrel
    anchors.left: swarmSize.left
    y: sHei * 0.08
    color: "#ffffff"
    text: qsTr("Swarm Size")
    font.pixelSize: 15
    font.bold: true
}

 GroupBox{
        id: dimBox
        x: parent.width * 0.52
        y: sHei * 0.03
        width: parent.width * 0.46
        height: parent.height * 0.80

    Label {  wrapMode: Text.WordWrap
        id: dimensionsLabel
        anchors.centerIn: parent.Center
        text: qsTr("Number of dimensions")
        color: "#ffffff"
        font.bold: true
        font.pixelSize: 15
    }

        RadioButton {
            id: oneD_button
            anchors.left: parent.left
            y: 0.15 * parent.height
            width: 0.5 * parent.width

            Text {
                x: 0.6* parent.width
                y: 11
                text: qsTr("One")
                color: "#ffffff"
                font.bold: true
                font.pixelSize: 15
            }
        }

        RadioButton {
            id: twoD_button
            anchors.right: x1_max.horizontalCenter
            y: 0.15 * parent.height
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



        TextField {
            id: x1_min
            anchors.left: parent.left
            y: parent.height * 0.35
            validator: IntValidator {
                locale: "English"
            }
            width: parent.width * 0.43
            height: parent.height * 0.15
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
            anchors.right: parent.right
            y: parent.height * 0.35
            validator: IntValidator {
                locale: "English"
            }
            width: parent.width * 0.43
            height: parent.height * 0.15
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
            anchors.left: x1_max.left
            y: parent.height * 0.65
            validator: IntValidator {
                locale: "English"
            }
                width: parent.width * 0.43
                height: parent.height * 0.15
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
            anchors.left: x1_min.left
            y: parent.height * 0.65
            validator: IntValidator {
                locale: "English"
            }
                width: parent.width * 0.43
                height: parent.height * 0.15
            clip: true
            color: "#000"
            background: Rectangle
            {
                color: "#DDD"
            }
            text: "0"
            visible: twoD_button.checked
        }

        Label {  wrapMode: Text.WordWrap
            id: x1_maxlabel
            anchors.left: x1_max.left
            anchors.bottom: x1_max.top
            text: qsTr("Max of dimension 1")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 14
        }


        Label {  wrapMode: Text.WordWrap
            id: x2_maxlabel
            anchors.left: x2_max.left
            anchors.bottom: x2_max.top

            text: qsTr("Max of dimension 2")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 14
            visible: twoD_button.checked
        }

        Label {  wrapMode: Text.WordWrap
            id: x2_minlabel
            anchors.left: x2_min.left
            anchors.bottom: x2_min.top
            text: qsTr("Min of dimension 2")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 14
            visible: twoD_button.checked
        }



        Label {  wrapMode: Text.WordWrap
            id: x1_minlabel
            anchors.left: x1_min.left
            anchors.bottom: x1_min.top
            text: qsTr("Min of dimension 1")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 14
        }
    }




    GroupBox {
        id: posBox
        anchors.left: swarmSize.left
        anchors.right: swarmSize.right
//        anchors.bottom: dimBox.bottom
        y: sHei * 0.18
        height: sHei * 0.175

        Label {  wrapMode: Text.WordWrap
            id: startPosLabel
            x: 0
            y: 0
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


}




Label {  wrapMode: Text.WordWrap
    id: transLabel
    anchors.left:  transformations.left
    y: sHei * 0.52
    color: "#ffffff"
    text: qsTr("Transformations")
    font.bold: true
    font.pixelSize: 20
    font.family: "Helvetica"
}

GroupBox
{
    id: transformations
    x: sWid * 0.02
    y: sHei * 0.5
    width: sWid * 0.36
    height: sHei * 0.43

    font.bold: true
    font.pixelSize: 20


    TextField {
            id: transformationA
            validator: DoubleValidator {
                locale: "English"
                decimals: 4
            }
            x: 0.2 * parent.width
            y: 0.2 * parent.height
            width: 0.6 * parent.width
            height: 0.1 * parent.height
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
            x: 0.2 * parent.width
            y: 0.45 * parent.height
            width: 0.6 * parent.width
            height: 0.1 * parent.height
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

            x: 0.2 * parent.width
            y: 0.7 * parent.height
            width: 0.6 * parent.width
            height: 0.1 * parent.height
            clip: true
            color: "#000"
            background: Rectangle
            {
                color: "#DDD"
            }
            text: "0.0"
        }

        Label {  wrapMode: Text.WordWrap
            id: transALabel
            anchors.left: transformationA.left
            y: transformationA.height + (0.01*sWid)
            color: "#ffffff"
            text: qsTr("Growth/Shrink rate (default:1)")
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 15
            font.bold: true



        }

        Label {  wrapMode: Text.WordWrap
            id: transBLabel
            anchors.left: transformationB.left
            y: transformationB.height + (0.065*sWid)
            color: "#ffffff"
            text: qsTr("Horizontal Shift (default:0)")
            font.pixelSize: 15
            font.bold: true
        }

        Label {  wrapMode: Text.WordWrap
            id: transCLabel
        anchors.left: transformationC.left
        y: transformationC.height + (0.12*sWid)
        color: "#ffffff"
        text: qsTr("Vertical Shift    (default:0)")
        font.pixelSize: 15
        font.bold: true
    }


}



Label {  wrapMode: Text.WordWrap
    id: sysconfLabel
    anchors.left: systemConfig.left
    y: sHei * 0.52
    color: "#ffffff"
    text: qsTr("System Configuration")
    font.bold: true
    font.pixelSize: 20
    font.family: "Helvetica"
}
GroupBox{
    id: systemConfig

    anchors.right: envConfig.right
    anchors.bottom: transformations.bottom
    anchors.top: transformations.top
    width: transformations.width

    font.bold: true
    font.pixelSize: 20

    Label {  wrapMode: Text.WordWrap
        id: resolutionLabel
        anchors.left: resolutionChoice.left
        y: parent.height * 0.2
        color: "#ffffff"
        text: qsTr("Resolution")
        font.bold: true
        font.pixelSize: 15
    }

    Label {  wrapMode: Text.WordWrap
        id: instancesLabel
        anchors.left: numInstances.left
        y: parent.height * 0.2
        color: "#ffffff"
        text: qsTr("Number of simultaneous instances")
        font.bold: true
        font.pixelSize: 15
    }

    ComboBox {
        id: resolutionChoice
        x: parent.width * 0.1
        y: parent.height * 0.25
        width: 0.12 * sWid
        height: 0.037 * sHei
        transformOrigin: Item.Left
        opacity: 0.8
        clip: true
        model: [ "640x480", "1024x789", "1920x1080" ]
        currentIndex: 0
    }



    SpinBox {
        id: numInstances
        x: parent.width * 0.5
        y: parent.height * 0.25
        width: 0.12 * sWid
        height: 0.037 * sHei
        opacity: 0.7
        editable: true
        from: 1
        to: 4
        value: 1

    }

    Slider {
        id: renderSlider
        x: 0.1 * parent.width
        y: 0.48 * parent.height
        width: 0.75 * parent.width
        height: 0.2 * parent.height
        anchors.top: renderValLabel.top
        spacing: 3
        stepSize: 1
        to: 120
        from: 0
        snapMode: Slider.SnapAlways
        value: 60
    }

    Label {  wrapMode: Text.WordWrap
        id: renderLabel
        anchors.horizontalCenter: renderSlider.horizontalCenter
        y: 180
        color: "#ffffff"
        text: qsTr("Render Speed - ")
        font.pixelSize: 15
        font.bold: true
    }

    Label {  wrapMode: Text.WordWrap
        id: ramLabel
        anchors.horizontalCenter: ramSlider.horizontalCenter
        y: 274
        color: "#ffffff"
        text: qsTr("Max Ram Use - ")
        font.pixelSize: 15
        font.bold: true
    }

    Slider {
        id: ramSlider
        x: 0.1 * parent.width
        y: 0.68 * parent.height
        anchors.top: ramValLabel.bottom
        width: 0.75 * parent.width
        height: 0.2 * parent.height
        stepSize: 1
        snapMode: Slider.SnapAlways
        to: 2048
        from: 0
        value: 512

    }

    Label {  wrapMode: Text.WordWrap
        id: renderValLabel
        anchors.horizontalCenter: renderSlider.horizontalCenter
        anchors.top: renderLabel.bottom
        color: "#ffffff"
        text: qsTr(renderSlider.value.toString())
        font.pixelSize: 15
        font.bold: true

    }

    Label {  wrapMode: Text.WordWrap
        id: ramValLabel
        anchors.horizontalCenter: ramSlider.horizontalCenter
        anchors.top: ramLabel.bottom
        color: "#ffffff"
        text: qsTr(ramSlider.value.toString())
        font.pixelSize: 15
        font.bold: true

    }
}

/*
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
}*/




    ToggleButton {
        id: toggleRunning
        x: sWid * 0.40
        y: sHei * 0.6
        width: sWid * 0.20
        height: sHei * 0.20
        text: qsTr("Optimizer On")

        onClicked: {
          /*           setPkg.lock(true);
                     setPkg.change(true);
                     setPkg.generateSettingsGeneral(page2.swarmSize.value);
                     setPkg.generateSettingsDomain(page4.objectiveChoice.currentText, (page2.oneD_button.checked ? 1 : 2), parseInt(page2.x1_min.text), parseInt(page2.x1_max.text), parseInt(page2.x2_min.text),
                                           parseInt(page2.x2_max.text), parseFloat(page4.transformationA.text), parseFloat(page4.transformationB.text), parseFloat(page4.transformationC.text));
                     setPkg.generateSettingsGraphics(page3.resolutionChoice.currentText, page3.renderSlider.value, showLinks.checked,
                                           showPaths.checked, page3.ramSlider.value);
                     setPkg.generateSettingsOptimizer(algorithmChoice.currentText, page2.userPosbutton.checked, "Placeholder", parseFloat(inertia.text), parseFloat(cognitiveCoeff.text), parseFloat(socialCoeff.text), maxIterations.value, targetAcc.value);
                     setPkg.lock(false);
        */}

    }


    Button {
        id: updateButton
        x: sWid * 0.40
        y: sHei * 0.85
        width: sWid * 0.20
        height: sHei * 0.05
        text: qsTr("Update Parameters")

        font.family: "Garamond"
        font.pixelSize: 20
        onClicked: {
          /*           setPkg.lock(true);
                     setPkg.change(true);
                     setPkg.generateSettingsGeneral(page2.swarmSize.value);
                     setPkg.generateSettingsDomain(page4.objectiveChoice.currentText, (page2.oneD_button.checked ? 1 : 2), parseInt(page2.x1_min.text), parseInt(page2.x1_max.text), parseInt(page2.x2_min.text),
                                           parseInt(page2.x2_max.text), parseFloat(page4.transformationA.text), parseFloat(page4.transformationB.text), parseFloat(page4.transformationC.text));
                     setPkg.generateSettingsGraphics(page3.resolutionChoice.currentText, page3.renderSlider.value, showLinks.checked,
                                           showPaths.checked, page3.ramSlider.value);
                     setPkg.generateSettingsOptimizer(algorithmChoice.currentText, page2.userPosbutton.checked, "Placeholder", parseFloat(inertia.text), parseFloat(cognitiveCoeff.text), parseFloat(socialCoeff.text), maxIterations.value, targetAcc.value);
                     setPkg.lock(false);

            */        }
        opacity: 0.7
    }

}

