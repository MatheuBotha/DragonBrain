#include "optimizersettingspackage.h"

OptimizerSettingsPackage::OptimizerSettingsPackage()
{

}



double OptimizerSettingsPackage::getCognitiveCoefficient()
{
    return cognitiveCoefficient;
}

double OptimizerSettingsPackage::getSocialCoefficient()
{
    return socialCoefficient;
}

int OptimizerSettingsPackage::getMaxIterations()
{
    return maxIterations;
}


void OptimizerSettingsPackage::setCognitiveCoefficient(double cogn)
{
    cognitiveCoefficient = cogn;
}

void OptimizerSettingsPackage::setSocialCoefficient(double social)
{
    socialCoefficient = social;
}

void OptimizerSettingsPackage::setMaxIterations(int max)
{
    maxIterations = max;
}


void OptimizerSettingsPackage::setAlgorithms(std::string aly, std::string aly2, std::string aly3, std::string aly4) {
    algorithm = aly;
    algorithm2 = aly2;
    algorithm3 = aly3;
    algorithm4 = aly4;
}

std::string OptimizerSettingsPackage::getAlgorithm(int i) {
    if(i == 1)
        return algorithm;
    else if(i == 2) return algorithm2;
    else if (i == 3) return algorithm3;
    else return algorithm4;
}

void OptimizerSettingsPackage::setConstrictionCoefficient(double constrict) {
    constrictionCoefficient = constrict;
}

void OptimizerSettingsPackage::setMaxVelocity(double velo) {
    maxVelocity = velo;
}

void OptimizerSettingsPackage::setFailCount(int fails) {
    failCount = fails;
}

void OptimizerSettingsPackage::setSuccessCount(int successes) {
    successCount = successes;
}

void OptimizerSettingsPackage::setNeighbourhoodSize(int nSize) {
    neighbourhoodSize = nSize;
}

double OptimizerSettingsPackage::getConstrictionCoefficient() {
    return constrictionCoefficient;
}

double OptimizerSettingsPackage::getMaxVelocity() {
    return maxVelocity;
}

int OptimizerSettingsPackage::getFailCount() {
    return failCount;
}

int OptimizerSettingsPackage::getSuccessCount() {
    return successCount;
}

int OptimizerSettingsPackage::getNeighbourhoodSize() {
    return neighbourhoodSize;
}
