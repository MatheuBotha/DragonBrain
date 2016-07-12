#include "optimizersettingspackage.h"

OptimizerSettingsPackage::OptimizerSettingsPackage()
{

}

OptimizerSettingsPackage::OptimizerSettingsPackage(std::string* particles, double inertia, double cogn, double social)
{
    particlePlacement = particles;
    inertiaWeight = inertia;
    cognitiveCoefficient = cogn;
    socialCoefficient = social;

}

std::string *OptimizerSettingsPackage::getParticlePlacementString()
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

void OptimizerSettingsPackage::setParticlePlacementString(std::string* particleString)
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
