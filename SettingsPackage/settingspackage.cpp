#include "settingspackage.h"
#include <iostream>


SettingsPackage::SettingsPackage()
{
    gpPkg = new GraphicsSettingsPackage();
    optPkg = new OptimizerSettingsPackage();
    probPkg = new ProblemDomainSettingsPackage();
}



void SettingsPackage::generateSettingsGeneral(int sSize)
{
    swarmSize = sSize;
}

GraphicsSettingsPackage* SettingsPackage::getGraphicsSettingsPackage()
{
    return gpPkg;
}

OptimizerSettingsPackage* SettingsPackage::getOptimizerSettingsPackage()
{
    return optPkg;
}

ProblemDomainSettingsPackage* SettingsPackage::getProblemDomainSettingsPackage()
{
    return probPkg;
}


// Some manual labour to be done here, nothing special at all
void SettingsPackage::generateSettingsGraphics(QString resolution, int renderSpeed, bool showLinks, bool showPath, int maxRam)
{
}

void SettingsPackage::generateSettingsOptimizer(QString* particlePlacement, double InertiaWeight, double cognitiveCoefficient, double socialCoefficient)
{

}

void SettingsPackage::generateSettingsDomain(QString objFunction, int dimensions, int x1_min, int x1_max, int x2_min, int x2_max, double TransformationA, double TransformationB, double TransformationC)
{
}
