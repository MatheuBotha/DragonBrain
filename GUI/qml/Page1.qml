import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.0

Page1Form {
    scale: 1
    property int sWid: Screen.width
    property int sHei: Screen.desktopAvailableHeight
    property int fontSize: (sWid > 1440) ? 15 : 12


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
                model: [ "Hill Climbing", "Random Search", "Elitist Hill Climbing", "Genetic Algorithm", "Particle Swarm Optimization", "Conical PSO", "Guaranteed Convergence PSO",
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
                font.pixelSize: fontSize
            }











    Label {  wrapMode: Text.WordWrap
                    id: secAlgoLabel
                    anchors.left: algorithmChoice.left
                    anchors.top: algorithmChoice.bottom
                    y: sHei * 0.08
                    color: "#ffffff"
                    text: qsTr("Second Algorithm")
                    font.bold: true
                    font.pixelSize: fontSize
                    visible: (numInstances.displayText == "2" || numInstances.displayText == "4")
                }


    ComboBox {
                    id: secondAlgo
                    anchors.left: algorithmChoice.left
                    anchors.top: secAlgoLabel.bottom
                    opacity: 0.8
                    width: algorithmChoice.width * 0.3
                    clip: true
                model: [ "Hill Climbing", "Random Search", "Elitist Hill Climbing", "Genetic Algorithm", "Particle Swarm Optimization", "Conical PSO", "Guaranteed Convergence PSO",
                "Fully Informed PSO"]
                    currentIndex: 0
                    visible: (numInstances.displayText == "2" || numInstances.displayText == "4")
                }

    Label {  wrapMode: Text.WordWrap
                    id: thirdAlgoLabel
                    anchors.horizontalCenter: algorithmChoice.horizontalCenter
                    anchors.top: secAlgoLabel.top
                    width: algorithmChoice.width * 0.3
                    color: "#ffffff"
                    text: qsTr("Third Algorithm")
                    font.bold: true
                    font.pixelSize: fontSize
                      visible: (numInstances.displayText == "4")
                }


    ComboBox {
                    id: thirdAlgo
                    anchors.horizontalCenter: algorithmChoice.horizontalCenter
                    anchors.top: thirdAlgoLabel.bottom
                    opacity: 0.8
                    width: algorithmChoice.width * 0.3
                    clip: true
                model: [ "Hill Climbing", "Random Search", "Elitist Hill Climbing", "Genetic Algorithm", "Particle Swarm Optimization", "Conical PSO", "Guaranteed Convergence PSO",
                "Fully Informed PSO"]
                    currentIndex: 0
                    visible: (numInstances.displayText == "4")
                }
    Label {  wrapMode: Text.WordWrap
                    id: fourthAlgoLabel
                    anchors.right: algorithmChoice.right
                    anchors.top: algorithmChoice.bottom
                    width: algorithmChoice.width * 0.3
                    y: sHei * 0.08
                    color: "#ffffff"
                    text: qsTr("Fourth Algorithm")
                    font.bold: true
                    font.pixelSize: fontSize
                    visible: (numInstances.displayText == "4")
                }


    ComboBox {
                    id: fourthAlgo
                    anchors.right: fourthAlgoLabel.right
                    anchors.top: thirdAlgo.top
                    opacity: 0.8
                    width: algorithmChoice.width * 0.3
                    clip: true
                model: [ "Hill Climbing", "Random Search", "Elitist Hill Climbing", "Genetic Algorithm", "Particle Swarm Optimization", "Conical PSO", "Guaranteed Convergence PSO",
                "Fully Informed PSO"]
                    currentIndex: 0
                    visible: (numInstances.displayText == "4")
                }









        SpinBox {
            id: maxIterations
            anchors.left: algorithmLabel.left
            anchors.top: iterationLabel.bottom
            width: algorithmChoice.width
            height: sHei * 0.05
            opacity: 0.7
            from: 1
            value: 1
            editable: true
            to: 2147483647
        }


        Label {  wrapMode: Text.WordWrap
            id: iterationLabel
            anchors.left: maxIterations.left
            y: sHei * 0.28
            color: "#ffffff"
            text: qsTr("Max Iterations")
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: fontSize
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
    font.pixelSize: fontSize
    font.bold: true
}

 GroupBox{
        id: dimBox
        x: parent.width * 0.49
        y: sHei * 0.03
        width: parent.width * 0.52
        height: parent.height * 0.80

    Label {  wrapMode: Text.WordWrap
        id: dimensionsLabel
        anchors.centerIn: parent.Center
        text: qsTr("Number of dimensions")
        color: "#ffffff"
        font.bold: true
        font.pixelSize: fontSize
    }

        RadioButton {
            id: oneD_button
            anchors.left: parent.left
            y: 0.10 * parent.height
            width: 0.5 * parent.width

            Text {
                x: 0.6* parent.width
                y: 11
                text: qsTr("One")
                color: "#ffffff"
                font.bold: true
                font.pixelSize: fontSize
            }
        }

        RadioButton {
            id: twoD_button
            anchors.right: x1_max.horizontalCenter
            y: 0.10 * parent.height
            checked: true
            Text {
                x: 48
                y: 11
                text: qsTr("Two")
                color: "#ffffff"
                font.bold: true
                font.pixelSize: fontSize
            }
        }



        TextField { font.pixelSize: fontSize
            id: x1_min
            anchors.left: parent.left
            y: parent.height * 0.48
            validator: DoubleValidator {
                            locale: "English"
                            decimals: 2
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

        TextField { font.pixelSize: fontSize
            id: x1_max
            anchors.right: parent.right
            y: parent.height * 0.48
            validator: DoubleValidator {
                            locale: "English"
                            decimals: 2
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

        TextField { font.pixelSize: fontSize
            id: x2_max
            anchors.left: x1_max.left
            y: parent.height * 0.79
            validator: DoubleValidator {
                            locale: "English"
                            decimals: 2
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


        TextField { font.pixelSize: fontSize
            id: x2_min
            anchors.left: x1_min.left
            y: parent.height * 0.79
            validator: DoubleValidator {
                            locale: "English"
                            decimals: 2
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
                    id: boundsLabel
                    anchors.left: x1_min.left
                    anchors.bottom: x1_maxlabel.top
                    width: parent.width;
                    text: qsTr("Boundaries (set all to 0 for objective defaults)")
                    color: "#ffffff"
                    font.bold: true
                    font.pixelSize: fontSize +2
                }

        Label {  wrapMode: Text.WordWrap
            id: x1_maxlabel
            anchors.left: x1_max.left
            anchors.bottom: x1_max.top
            text: qsTr("Max of dimension 1")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: fontSize
        }


        Label {  wrapMode: Text.WordWrap
            id: x2_maxlabel
            anchors.left: x2_max.left
            anchors.bottom: x2_max.top

            text: qsTr("Max of dimension 2")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: fontSize
            visible: twoD_button.checked
        }

        Label {  wrapMode: Text.WordWrap
            id: x2_minlabel
            anchors.left: x2_min.left
            anchors.bottom: x2_min.top
            text: qsTr("Min of dimension 2")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: fontSize
            visible: twoD_button.checked
        }



        Label {  wrapMode: Text.WordWrap
            id: x1_minlabel
            anchors.left: x1_min.left
            anchors.bottom: x1_min.top
            text: qsTr("Min of dimension 1")
            color: "#ffffff"
            font.bold: true
            font.pixelSize: fontSize
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
            id: instancesLabel
            x: 0
            y: 20
            color: "#ffffff"
            text: qsTr("Num. Optimizers")
            font.pixelSize: fontSize
            font.bold: true
        }


    ComboBox {
        id: numInstances
        anchors.top: instancesLabel.bottom
        anchors.left: instancesLabel.left

        model: [ 1, 2, 4 ]

        width: objectiveChoice.width /3
        height: objectiveChoice.height
        opacity: 0.7

        font.pixelSize: fontSize+2  

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


    TextField { font.pixelSize: fontSize
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

        TextField { font.pixelSize: fontSize
            id: transformationB
            validator: DoubleValidator {
                locale: "English"
                decimals: 4
            }
            x: 0.2 * parent.width
            y: 0.43 * parent.height
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

        TextField { font.pixelSize: fontSize
            id: transformationC
            validator: DoubleValidator {
                locale: "English"
                decimals: 4
            }
            visible: twoD_button.checked

            x: 0.2 * parent.width
            y: 0.66 * parent.height
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

            TextField { font.pixelSize: fontSize
                    id: transformationD
                    validator: DoubleValidator {
                        locale: "English"
                        decimals: 4
                    }
                    x: 0.2 * parent.width
                    y: 0.89 * parent.height
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
            font.pixelSize: fontSize
            font.bold: true

        }

        Label {  wrapMode: Text.WordWrap
            id: transBLabel
            anchors.left: transformationB.left
            anchors.bottom: transformationB.top
            y: transformationB.height + (0.01*sWid)
            color: "#ffffff"
            text: qsTr("X Shift (default:0)")
            font.pixelSize: fontSize
            font.bold: true
        }

        Label {  wrapMode: Text.WordWrap
            id: transCLabel
        anchors.left: transformationC.left
        anchors.bottom: transformationC.top
        y: transformationC.height + (0.01*sWid)
        color: "#ffffff"
        text: qsTr("Y Shift (default:0)")
            visible: twoD_button.checked
        font.pixelSize: fontSize
        font.bold: true
    }

        Label {  wrapMode: Text.WordWrap
            id: transDLabel
        anchors.left: transformationD.left
        anchors.bottom: transformationD.top
        y: transformationD.height + (0.01*sWid)
        color: "#ffffff"
        text: qsTr("Vertical Shift (default:0)")
        font.pixelSize: fontSize
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
        anchors.top: objectiveChoice.bottom
        color: "#ffffff"
        text: qsTr("Resolution")
        font.bold: true
        font.pixelSize: fontSize+2
    }

    ComboBox {
        id: resolutionChoice
        x: parent.width * 0.05
        anchors.top: resolutionLabel.bottom

        width: objectiveChoice.width
        height: objectiveChoice.height
        transformOrigin: Item.Left
        opacity: 0.8
        clip: true
        model: [ "640x480", "1024x789", "1366x768", "1920x1080" ]
        currentIndex: 0
        font.pixelSize: fontSize
    }






   Label {
        id: objectiveLabel
        anchors.left: objectiveChoice.left
        y: 0.05 * Screen.desktopAvailableHeight
        color: "#ffffff"
        text: qsTr("Objective Function")
        font.bold: true
        font.pixelSize: 15
    }


ComboBox {
        id: objectiveChoice
        anchors.top: objectiveLabel.bottom
        anchors.left: resolutionChoice.left
        width: 0.9 * parent.width
        height: 0.1 * Screen.desktopAvailablHeight

        transformOrigin: Item.Left
        opacity: 0.8
        clip: true
        model: [ "Ackley", "Alpine", "Beale", "Bohachevsky", "EggHolder", "GoldSteinPrice", "Griewank", "Levy13",
        "Michalewicz", "Pathological", "Quadric", "Quartic", "Rana", "Rastrigin", "Rosenbrock", "Saddle", "Salomon", "Schwefel22",
         "Schwefel26", "Sin", "SixHumpCamelBack", "SkewRastrigin", "Spherical", "Step", "Weierstrass", "Zakharov"]
        currentIndex: 0
        font.pixelSize: 20
        font.bold: true
        font.family: "Helvetica"

    }




                TextField { font.pixelSize: fontSize
                    id: cognitiveCoeff
                    validator: DoubleValidator {
                        locale: "English"
                        decimals: 4
                    }
                    anchors.left: resolutionChoice.left
                    anchors.top: cognitiveLabel.bottom
                    width: parent.width * 0.25
                    height: sHei * 0.038
                    clip: true
                    color: "#000"
                    background: Rectangle
                    {
                        color: "#DDD"
                    }
                    visible: (algorithmChoice.displayText == "Conical PSO" ||
                              algorithmChoice.displayText == "Guaranteed Convergence PSO" ||
                              algorithmChoice.displayText == "Particle Swarm Optimization" ||
                              secondAlgo.displayText == "Conical PSO" ||
                              secondAlgo.displayText == "Guaranteed Convergence PSO" ||
                              secondAlgo.displayText == "Particle Swarm Optimization" ||
                              thirdAlgo.displayText == "Conical PSO" ||
                              thirdAlgo.displayText == "Guaranteed Convergence PSO" ||
                              thirdAlgo.displayText == "Particle Swarm Optimization" ||
                              fourthAlgo.displayText == "Conical PSO" ||
                              fourthAlgo.displayText == "Guaranteed Convergence PSO" ||
                              fourthAlgo.displayText == "Particle Swarm Optimization"
                                                ) ? true : false

                    text: "2.5"
                }

                TextField { font.pixelSize: fontSize
                    id: socialCoeff
                    validator: DoubleValidator {
                        locale: "English"
                        decimals: 4
                    }
                    anchors.top: socialLabel.bottom
                    anchors.right: resolutionChoice.right
                    width: parent.width * 0.25
                    height: sHei * 0.038
                    clip: true
                    color: "#000"
                    background: Rectangle
                    {
                        color: "#DDD"
                    }
                    visible: (algorithmChoice.displayText == "Conical PSO" ||
                              algorithmChoice.displayText == "Guaranteed Convergence PSO" ||
                              algorithmChoice.displayText == "Particle Swarm Optimization" ||
                              secondAlgo.displayText == "Conical PSO" ||
                              secondAlgo.displayText == "Guaranteed Convergence PSO" ||
                              secondAlgo.displayText == "Particle Swarm Optimization" ||
                              thirdAlgo.displayText == "Conical PSO" ||
                              thirdAlgo.displayText == "Guaranteed Convergence PSO" ||
                              thirdAlgo.displayText == "Particle Swarm Optimization" ||
                              fourthAlgo.displayText == "Conical PSO" ||
                              fourthAlgo.displayText == "Guaranteed Convergence PSO" ||
                              fourthAlgo.displayText == "Particle Swarm Optimization"
                                                ) ? true : false
                    text: "2.5"
                }


                Label {  wrapMode: Text.WordWrap
                    id: cognitiveLabel
                    anchors.left: resolutionChoice.left
                    anchors.top: resolutionChoice.bottom
                    color: "#ffffff"
                    visible: (algorithmChoice.displayText == "Conical PSO" ||
                              algorithmChoice.displayText == "Guaranteed Convergence PSO" ||
                              algorithmChoice.displayText == "Particle Swarm Optimization" ||
                              secondAlgo.displayText == "Conical PSO" ||
                              secondAlgo.displayText == "Guaranteed Convergence PSO" ||
                              secondAlgo.displayText == "Particle Swarm Optimization" ||
                              thirdAlgo.displayText == "Conical PSO" ||
                              thirdAlgo.displayText == "Guaranteed Convergence PSO" ||
                              thirdAlgo.displayText == "Particle Swarm Optimization" ||
                              fourthAlgo.displayText == "Conical PSO" ||
                              fourthAlgo.displayText == "Guaranteed Convergence PSO" ||
                              fourthAlgo.displayText == "Particle Swarm Optimization"
                                                ) ? true : false
                    text: qsTr("Cognitive Coefficient")
                    font.pixelSize: fontSize
                    font.bold: true
                }

                Label {  wrapMode: Text.WordWrap
                    id: socialLabel
                    anchors.right: resolutionChoice.right
                    anchors.top: resolutionChoice.bottom
                    color: "#ffffff"

                    text: qsTr("Social Coefficient")
                      visible: (algorithmChoice.displayText == "Conical PSO" ||
                                algorithmChoice.displayText == "Guaranteed Convergence PSO" ||
                                algorithmChoice.displayText == "Particle Swarm Optimization" ||
                                secondAlgo.displayText == "Conical PSO" ||
                                secondAlgo.displayText == "Guaranteed Convergence PSO" ||
                                secondAlgo.displayText == "Particle Swarm Optimization" ||
                                thirdAlgo.displayText == "Conical PSO" ||
                                thirdAlgo.displayText == "Guaranteed Convergence PSO" ||
                                thirdAlgo.displayText == "Particle Swarm Optimization" ||
                                fourthAlgo.displayText == "Conical PSO" ||
                                fourthAlgo.displayText == "Guaranteed Convergence PSO" ||
                                fourthAlgo.displayText == "Particle Swarm Optimization"
                                                  ) ? true : false
                   font.pixelSize: fontSize
                    font.bold: true
                }
                //
                //
                //
                //BEGIN PSO SPECIFIC SECTION
                //
                Label {  wrapMode: Text.WordWrap
                    id: inertiaLabel
                    anchors.left: cognitiveCoeff.left
                    anchors.top: socialCoeff.bottom
                    color: "#ffffff"
                    text: qsTr("Inertia Weight")
                                visible: (algorithmChoice.displayText == "Conical PSO" ||
                                          algorithmChoice.displayText == "Guaranteed Convergence PSO" ||
                                          algorithmChoice.displayText == "Particle Swarm Optimization" ||
                                          secondAlgo.displayText == "Conical PSO" ||
                                          secondAlgo.displayText == "Guaranteed Convergence PSO" ||
                                          secondAlgo.displayText == "Particle Swarm Optimization" ||
                                          thirdAlgo.displayText == "Conical PSO" ||
                                          thirdAlgo.displayText == "Guaranteed Convergence PSO" ||
                                          thirdAlgo.displayText == "Particle Swarm Optimization" ||
                                          fourthAlgo.displayText == "Conical PSO" ||
                                          fourthAlgo.displayText == "Guaranteed Convergence PSO" ||
                                          fourthAlgo.displayText == "Particle Swarm Optimization"
                                                            ) ? true : false
                                                                   font.pixelSize: fontSize
                    font.bold: true
                }

                TextField { font.pixelSize: fontSize
                    id: inertiaWeight
                    validator: DoubleValidator {
                        locale: "English"
                        decimals: 4
                    }
                    anchors.left: inertiaLabel.left
                    anchors.top: inertiaLabel.bottom
                    width: parent.width * 0.25
                    clip: true
                    color: "#000"
                    background: Rectangle
                    {
                        color: "#DDD"
                    }
                    visible: (algorithmChoice.displayText == "Conical PSO" ||
                              algorithmChoice.displayText == "Guaranteed Convergence PSO" ||
                              algorithmChoice.displayText == "Particle Swarm Optimization" ||
                              (secondAlgo.visible && (secondAlgo.displayText == "Conical PSO" ||
                              secondAlgo.displayText == "Guaranteed Convergence PSO" ||
                              secondAlgo.displayText == "Particle Swarm Optimization")) ||
                              (thirdAlgo.visible && (
                              thirdAlgo.displayText == "Conical PSO" ||
                              thirdAlgo.displayText == "Guaranteed Convergence PSO" ||
                              thirdAlgo.displayText == "Particle Swarm Optimization")) ||
                              (fourthAlgo.visible && (
                              fourthAlgo.displayText == "Conical PSO" ||
                              fourthAlgo.displayText == "Guaranteed Convergence PSO" ||
                              fourthAlgo.displayText == "Particle Swarm Optimization"
                                                ))) ? true : false
                    text: "0.9"
                }








    //FIPS PLS
    Label {  wrapMode: Text.WordWrap
                    id: constrictLabel
                    anchors.left: cognitiveCoeff.left
                    anchors.top: neighbourLabel.top
                    color: "#ffffff"
                    text: qsTr("Constriction Coefficient")
                    visible: (algorithmChoice.displayText == "Fully Informed PSO" ||
                               (secondAlgo.displayText == "Fully Informed PSO" && secondAlgo.visible) ||
                               (thirdAlgo.displayText == "Fully Informed PSO" && thirdAlgo.visible) ||
                               (fourthAlgo.displayText == "Fully Informed PSO" && fourthAlgo.visible)) ? true : false

                   font.pixelSize: fontSize
                    font.bold: true
                }

                TextField { font.pixelSize: fontSize
                    id: constrictCoeff
                    validator: DoubleValidator {
                        locale: "English"
                        decimals: 4
                    }
                    anchors.left: inertiaLabel.left
                    anchors.top: constrictLabel.bottom
                    width: parent.width * 0.25
                    clip: true
                    color: "#000"
                    background: Rectangle
                    {
                        color: "#DDD"
                    }
                    visible: (algorithmChoice.displayText == "Fully Informed PSO" ||
                               (secondAlgo.displayText == "Fully Informed PSO" && secondAlgo.visible) ||
                               (thirdAlgo.displayText == "Fully Informed PSO" && thirdAlgo.visible) ||
                               (fourthAlgo.displayText == "Fully Informed PSO" && fourthAlgo.visible)) ? true : false


                    text: "0.9"
                }
                ///

                //CPSO
                            Label {  wrapMode: Text.WordWrap
                                id: veloLabel
                                x: sWid * 0.02 + (parent.width * 0.6)
                                anchors.top: socialLabel.top
                                anchors.left: maxVelocity.left
                                color: "#ffffff"
                                text: qsTr("Maximum Velocity")
                    visible: (algorithmChoice.displayText == "Conical PSO" ||
                               (secondAlgo.displayText == "Conical PSO" && secondAlgo.visible) ||
                               (thirdAlgo.displayText == "Conical PSO" && thirdAlgo.visible) ||
                               (fourthAlgo.displayText == "Conical PSO" && fourthAlgo.visible)) ? true : false
                               font.pixelSize: fontSize
                                font.bold: true
                }
                TextField { font.pixelSize: fontSize
                                id: maxVelocity
                                validator: DoubleValidator {
                                    locale: "English"
                                    decimals: 4
                                }
                                anchors.horizontalCenter: resolutionChoice.horizontalCenter

                                anchors.top: veloLabel.bottom
                                width: parent.width * 0.25
                                clip: true
                                color: "#000"
                                background: Rectangle
                                {
                                    color: "#DDD"
                                }
                    visible: (algorithmChoice.displayText == "Conical PSO" ||
                               (secondAlgo.displayText == "Conical PSO" && secondAlgo.visible) ||
                               (thirdAlgo.displayText == "Conical PSO" && thirdAlgo.visible) ||
                               (fourthAlgo.displayText == "Conical PSO" && fourthAlgo.visible)) ? true : false
                                text: "50.0"
                            }



                            Label {  wrapMode: Text.WordWrap
                                id: successLabel
                                anchors.top: socialCoeff.bottom
                                anchors.left: socialCoeff.left
                                color: "#ffffff"
                                text: qsTr("Success Count")
                    visible: (algorithmChoice.displayText == "Guaranteed Convergence PSO" ||
                               (secondAlgo.displayText == "Guaranteed Convergence PSO" && secondAlgo.visible) ||
                               (thirdAlgo.displayText == "Guaranteed Convergence PSO" && thirdAlgo.visible) ||
                               (fourthAlgo.displayText == "Guaranteed Convergence PSO" && fourthAlgo.visible)) ? true : false
                               font.pixelSize: fontSize
                                font.bold: true
                }
                TextField { font.pixelSize: fontSize
                                id: successCount
                                validator: IntValidator{
                                    locale: "English"
                                }
                                anchors.left: successLabel.left
                                anchors.top: successLabel.bottom
                                width: parent.width * 0.25
                                clip: true
                                color: "#000"
                                background: Rectangle
                                {
                                    color: "#DDD"
                                }
                    visible: (algorithmChoice.displayText == "Guaranteed Convergence PSO" ||
                               (secondAlgo.displayText == "Guaranteed Convergence PSO" && secondAlgo.visible) ||
                               (thirdAlgo.displayText == "Guaranteed Convergence PSO" && thirdAlgo.visible) ||
                               (fourthAlgo.displayText == "Guaranteed Convergence PSO" && fourthAlgo.visible)) ? true : false
                                text: "15"
                            }




                            Label {  wrapMode: Text.WordWrap
                                id: failLabel
                                anchors.top: socialCoeff.bottom
                                anchors.left: failCount.left
                                color: "#ffffff"
                                text: qsTr("Fail Count")
                    visible: (algorithmChoice.displayText == "Guaranteed Convergence PSO" ||
                               (secondAlgo.displayText == "Guaranteed Convergence PSO" && secondAlgo.visible) ||
                               (thirdAlgo.displayText == "Guaranteed Convergence PSO" && thirdAlgo.visible) ||
                               (fourthAlgo.displayText == "Guaranteed Convergence PSO" && fourthAlgo.visible)) ? true : false
                               font.pixelSize: fontSize
                                font.bold: true
                }
                TextField { font.pixelSize: fontSize
                                id: failCount
                                validator: IntValidator {
                                    locale: "English"
                                }
                                anchors.horizontalCenter: resolutionChoice.horizontalCenter
                                anchors.top: failLabel.bottom
                                width: parent.width * 0.25
                                clip: true
                                color: "#000"
                                background: Rectangle
                                {
                                    color: "#DDD"
                                }
                    visible: (algorithmChoice.displayText == "Guaranteed Convergence PSO" ||
                               (secondAlgo.displayText == "Guaranteed Convergence PSO" && secondAlgo.visible) ||
                               (thirdAlgo.displayText == "Guaranteed Convergence PSO" && thirdAlgo.visible) ||
                               (fourthAlgo.displayText == "Guaranteed Convergence PSO" && fourthAlgo.visible)) ? true : false
                                text: "5"
                            }


            //ENDGCPSO
                //FIPS

                            Label {  wrapMode: Text.WordWrap
                                id: neighbourLabel
                                anchors.top: failCount.bottom
                                anchors.left: socialCoeff.left
                                color: "#ffffff"
                                text: qsTr("Neighbourhood Size")
                    visible: (algorithmChoice.displayText == "Fully Informed PSO" ||
                               (secondAlgo.displayText == "Fully Informed PSO" && secondAlgo.visible) ||
                               (thirdAlgo.displayText == "Fully Informed PSO" && thirdAlgo.visible) ||
                               (fourthAlgo.displayText == "Fully Informed PSO" && fourthAlgo.visible)) ? true : false
                               font.pixelSize: fontSize
                                font.bold: true
                }
                TextField { font.pixelSize: fontSize
                                id: neighbourSize
                                validator: IntValidator{
                                    locale: "English"
                                }
                                anchors.left: neighbourLabel.left
                                anchors.top: neighbourLabel.bottom
                                width: parent.width * 0.25
                                clip: true
                                color: "#000"
                                background: Rectangle
                                {
                                    color: "#DDD"
                                }
                    visible: (algorithmChoice.displayText == "Fully Informed PSO" ||
                               (secondAlgo.displayText == "Fully Informed PSO" && secondAlgo.visible) ||
                               (thirdAlgo.displayText == "Fully Informed PSO" && thirdAlgo.visible) ||
                               (fourthAlgo.displayText == "Fully Informed PSO" && fourthAlgo.visible)) ? true : false
                                text: "2"
                            }


            //ENDFIPS
            //END PSO SPECIFIC SECTION

}









    ToggleButton {
        id: toggleRunning
        x: sWid * 0.40
        y: sHei * 0.6
        width: sWid * 0.20
        height: sHei * 0.20
        text: qsTr("Optimizer On")

        onClicked: {
            if(setPkg.readyForNext())
            {

                     setPkg.lock(true);
                     setPkg.readyNext(false);
                     setPkg.change(true);
                     setPkg.generateSettingsGeneral(swarmSize.value, parseInt(numInstances.displayText));
                     setPkg.generateSettingsDomain( objectiveChoice.currentText, (oneD_button.checked ? 1 : 2), parseFloat( x1_min.text), parseFloat( x1_max.text), parseFloat( x2_min.text),
                                           parseFloat( x2_max.text), parseFloat( transformationA.text), parseFloat( transformationB.text), parseFloat( transformationC.text), parseFloat( transformationD.text ));
                     setPkg.generateSettingsGraphics( resolutionChoice.currentText,  renderSlider.value);
                     setPkg.generateSettingsOptimizer(algorithmChoice.currentText,  secondAlgo.currentText, thirdAlgo.currentText, fourthAlgo.currentText, maxIterations.value, parseFloat(cognitiveCoeff.text), parseFloat(socialCoeff.text),
                                            parseFloat(constrictCoeff.text), parseFloat(inertiaWeight.text), parseFloat(maxVelocity.text), parseInt(successCount.text), parseInt(failCount.text), parseInt(neighbourSize.text));
                     setPkg.lock(false);
             }
        }

    }


    Slider {
        id: renderSlider
        x: sWid * 0.40
        y: sHei * 0.85
        width: sWid * 0.20
        spacing: 3
        stepSize: 1
        to: 300
        from: 0
        snapMode: Slider.SnapAlways
        value: 60
    }

    Label {  wrapMode: Text.WordWrap
            id: renderValLabel
            anchors.horizontalCenter: renderSlider.horizontalCenter
            anchors.bottom: renderSlider.top
            color: "#ffffff"
            text: qsTr(renderSlider.value.toString())
            font.pixelSize: 15
            font.bold: true

        }


    Label {  wrapMode: Text.WordWrap
            id: renderLabel
            anchors.horizontalCenter: renderSlider.horizontalCenter
            anchors.bottom: renderValLabel.top
            color: "#ffffff"
            text: qsTr("Render Speed - ")
            font.pixelSize: 15
            font.bold: true
        }
}
