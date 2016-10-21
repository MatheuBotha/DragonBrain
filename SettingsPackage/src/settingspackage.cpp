#include "settingspackage.h"
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

SettingsPackage::SettingsPackage()
{
    changed = false;
    locked = true;
    closing = false;
    ready = true;
    gpPkg = new GraphicsSettingsPackage();
    optPkg = new OptimizerSettingsPackage();
    probPkg = new ProblemDomainSettingsPackage();
}

int SettingsPackage::getSwarmSize()
{
    return swarmSize;
}


void SettingsPackage::generateSettingsGeneral(int sSize, int instances)
{
    swarmSize = sSize;
    numInstances = instances;

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
void SettingsPackage::generateSettingsGraphics(QString resolution, bool showLinks, bool showPath)
{
    std::string res = resolution.toStdString();
    int resW = atoi(res.substr(0,res.find('x')).c_str());
    int resH = atoi(res.substr(res.find('x')+1, res.length()).c_str());
    gpPkg->setShowLinks(showLinks);
    gpPkg->setShowPath(showPath);
    gpPkg->setResolutionH(resH);
    gpPkg->setResolutionW(resW);
}

void SettingsPackage::generateSettingsOptimizer(QString algorithm, QString algo2, QString algo3, QString algo4, int maxIterations, double cog, double soc,
                                                double constrictionCoeff, double maxVelo, int success, int fail, int neighbourSize)
{
    optPkg->setAlgorithms(algorithm.toStdString(), algo2.toStdString(), algo3.toStdString(), algo4.toStdString());
    optPkg->setMaxIterations(maxIterations);
    optPkg->setConstrictionCoefficient(constrictionCoeff);
    optPkg->setMaxVelocity(maxVelo);
    optPkg->setSuccessCount(success);
    optPkg->setFailCount(fail);
    optPkg->setNeighbourhoodSize(neighbourSize);
    optPkg->setSocialCoefficient(soc);
    optPkg->setCognitiveCoefficient(cog);
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


void SettingsPackage::updateSettings(double transA, double transB, double transC, double transD, double maxVelocity,
                                     int succ, int fail)
{
    double transformations[4] = {transA, transB, transC, transD};
    probPkg->setTransformations(transformations);
    optPkg->setMaxVelocity(maxVelocity);
    optPkg->setSuccessCount(succ);
    optPkg->setFailCount(fail);
}

int SettingsPackage::getNumInstances() {
    return numInstances;
}
