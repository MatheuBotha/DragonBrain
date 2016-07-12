#ifndef OPTIMIZERSETTINGSPACKAGE_H
#define OPTIMIZERSETTINGSPACKAGE_H

#include <string>

/**
 * @class OptimizerSettingsPackage
 *
 * This class is a wrapper for all the settings related to the Optimizer
 * The contents are rather simplistic, only getters and setters.
 * */

class OptimizerSettingsPackage
{
private:
    std::string* particlePlacement;
    double inertiaWeight;
    double cognitiveCoefficient;
    double socialCoefficient;
public:
    /**
     * @brief The default constructor for an OptimizerSettingsPackage
     */
    OptimizerSettingsPackage();
    /**
     * @brief Creates a  OptimizerSettingsPackage with specified settings (currently unused)
     * @param particlePlacement (string pointer)
     * @param inertiaWeight (double)
     * @param cognitiveCoefficient (double)
     * @param socialCoefficient (double)
     */
    OptimizerSettingsPackage(std::string*, double, double, double);

    /**
     * @brief
     * @return Returns the string containing the user specified particle placement (or null)
     */
    std::string* getParticlePlacementString();
    /**
     * @brief
     * @return Returns a double containing the inertia weight
     */
    double getInertiaWeight();
    /**
     * @brief
     * @return Returns a double containing the cognitive coefficient
     */
    double getCognitiveCoefficient();
    /**
     * @brief
     * @return Returns a double containing the social coefficient
     */
    double getSocialCoefficient();

    /**
     * @brief Sets the Particle Placement
     * @param ParticlePlacement (string pointer)
     */
    void setParticlePlacementString(std::string*);
    /**
     * @brief Sets the Inertia Weight
     * @param InertiaWeight (double)
     */
    void setInertiaWeight(double);
    /**
     * @brief Sets the Cognitive Coefficient
     * @param cognitiveCoefficient (double)
     */
    void setCognitiveCoefficient(double);
    /**
     * @brief Sets the Social Coefficient
     * @param socialCoefficient (double)
     */
    void setSocialCoefficient(double);
};

#endif // OPTIMIZERSETTINGSPACKAGE_H
