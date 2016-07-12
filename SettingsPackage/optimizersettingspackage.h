#ifndef OPTIMIZERSETTINGSPACKAGE_H
#define OPTIMIZERSETTINGSPACKAGE_H

#include <string>

class OptimizerSettingsPackage
{
private:
    std::string* particlePlacement;
    double inertiaWeight;
    double cognitiveCoefficient;
    double socialCoefficient;
public:
    OptimizerSettingsPackage();
    OptimizerSettingsPackage(std::string*, double, double, double);
    std::string* getParticlePlacementString();
    double getInertiaWeight();
    double getCognitiveCoefficient();
    double getSocialCoefficient();

    void setParticlePlacementString(std::string*);
    void setInertiaWeight(double);
    void setCognitiveCoefficient(double);
    void setSocialCoefficient(double);
};

#endif // OPTIMIZERSETTINGSPACKAGE_H
