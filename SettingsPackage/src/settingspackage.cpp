#include "settingspackage.h"

SettingsPackage::SettingsPackage()
{
    changed = false;
    locked = true;
    gpPkg = new GraphicsSettingsPackage();
    optPkg = new OptimizerSettingsPackage();
    probPkg = new ProblemDomainSettingsPackage();
}

int SettingsPackage::getSwarmSize()
{
    return swarmSize;
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
    std::string res = resolution.toStdString();
    int resW = atof(res.substr(0,res.find('x')).c_str());
    int resH = atof(res.substr(res.find('x')+1, res.length()).c_str());
    gpPkg->setMaxRam(maxRam);
    gpPkg->setRenderSpeed(renderSpeed);
    gpPkg->setShowLinks(showLinks);
    gpPkg->setShowPath(showPath);
    gpPkg->setResolutionH(resH);
    gpPkg->setResolutionW(resW);
}

void SettingsPackage::generateSettingsOptimizer(bool userInitialParticles,QString particlePlacement, double InertiaWeight, double cognitiveCoefficient, double socialCoefficient, int maxIterations, int cutoffAcc)
{
    if(userInitialParticles)
        optPkg->setParticlePlacementString(particlePlacement.toStdString());
    else optPkg->setParticlePlacementString("");
    optPkg->setInertiaWeight(InertiaWeight);
    optPkg->setCognitiveCoefficient(cognitiveCoefficient);
    optPkg->setSocialCoefficient(socialCoefficient);
    optPkg->setMaxIterations(maxIterations);
    optPkg->setCutoffAcc(cutoffAcc);
}


void SettingsPackage::generateSettingsDomain(QString objFunction, int dimensions, int x1_min, int x1_max, int x2_min, int x2_max, double TransformationA, double TransformationB, double TransformationC)
{
    probPkg->setObjectiveFunction(objFunction.toStdString());
    probPkg->setDimensions(dimensions);
    int boundaries[4] = {x1_min, x1_max, x2_min, x2_max};
    probPkg->setBoundaries(boundaries);
    double transformations[3] = {TransformationA, TransformationB, TransformationC};
    probPkg->setTransformations(transformations);
}

SettingsPackage::~SettingsPackage() {
    delete optPkg;
    delete probPkg;
    delete gpPkg;
}

void SettingsPackage::change(bool status) {
    changed = status;
}

bool SettingsPackage::hasChanged() {
    return changed;
}

void SettingsPackage::lock(bool status) {
    locked = status;
}

bool SettingsPackage::isLocked() {
    return locked;
}

