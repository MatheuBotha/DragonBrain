#include "settingspackage.h"
#include <cstdlib>
#include <stdlib.h>

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
    int resW = atoi(res.substr(0,res.find('x')).c_str());
    int resH = atoi(res.substr(res.find('x')+1, res.length()).c_str());
    gpPkg->setMaxRam(maxRam);
    gpPkg->setRenderSpeed(renderSpeed);
    gpPkg->setShowLinks(showLinks);
    gpPkg->setShowPath(showPath);
    gpPkg->setResolutionH(resH);
    gpPkg->setResolutionW(resW);
}

void SettingsPackage::generateSettingsOptimizer(QString algorithm, bool userInitialParticles,QString particlePlacement, double InertiaWeight, double cognitiveCoefficient, double socialCoefficient, int maxIterations, int cutoffAcc,
                                                double constrictionCoeff, double maxVelo, int success, int fail, int neighbourSize)
{
    optPkg->setAlgorithm(algorithm.toStdString());
    if(userInitialParticles)
        optPkg->setParticlePlacementString(particlePlacement.toStdString());
    else optPkg->setParticlePlacementString("");
    optPkg->setInertiaWeight(InertiaWeight);
    optPkg->setCognitiveCoefficient(cognitiveCoefficient);
    optPkg->setSocialCoefficient(socialCoefficient);
    optPkg->setMaxIterations(maxIterations);
    optPkg->setCutoffAcc(cutoffAcc);
    optPkg->setConstrictionCoefficient(constrictionCoeff);
    optPkg->setMaxVelocity(maxVelo);
    optPkg->setSuccessCount(success);
    optPkg->setFailCount(fail);
    optPkg->setNeighbourhoodSize(neighbourSize);
}


void SettingsPackage::generateSettingsDomain(QString objFunction, int dimensions, double x1_min, double x1_max, double x2_min, double x2_max, double TransformationA, double TransformationB, double TransformationC, double TransformationD)
{
    probPkg->setObjectiveFunction(objFunction.toStdString());
    probPkg->setDimensions(dimensions);
    double boundaries[4] = {x1_min, x1_max, x2_min, x2_max};
    probPkg->setBoundaries(boundaries);
    double transformations[4] = {TransformationA, TransformationB, TransformationC, TransformationD};
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

