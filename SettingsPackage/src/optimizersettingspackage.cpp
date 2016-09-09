#include "optimizersettingspackage.h"

OptimizerSettingsPackage::OptimizerSettingsPackage()
{

}

OptimizerSettingsPackage::OptimizerSettingsPackage(std::string particles, double inertia, double cogn, double social, int max, int acc)
{
    particlePlacement = particles;
    inertiaWeight = inertia;
    cognitiveCoefficient = cogn;
    socialCoefficient = social;
    maxIterations = max;
    cutoffAcc = acc;

}

std::string OptimizerSettingsPackage::getParticlePlacementString()
{
    return particlePlacement;
}

double OptimizerSettingsPackage::getInertiaWeight()
{
    return inertiaWeight;
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

int OptimizerSettingsPackage::getCutoffAcc()
{
    return cutoffAcc;
}

void OptimizerSettingsPackage::setParticlePlacementString(std::string particleString)
{
    particlePlacement = particleString;
}

void OptimizerSettingsPackage::setInertiaWeight(double inertia)
{
    inertiaWeight = inertia;
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

void OptimizerSettingsPackage::setCutoffAcc(int acc)
{
    cutoffAcc = acc;
}

void OptimizerSettingsPackage::setAlgorithm(std::string aly) {
    algorithm = aly;
}

std::string OptimizerSettingsPackage::getAlgorithm() {
    return algorithm;
}
