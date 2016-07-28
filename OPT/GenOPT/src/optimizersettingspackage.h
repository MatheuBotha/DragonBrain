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
    std::string particlePlacement;
    double inertiaWeight;
    double cognitiveCoefficient;
    double socialCoefficient;
    int maxIterations;
    int cutoffAcc;
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
     * @param maxIterations (int)
     * @param cutoffAcc (int)
     */
    OptimizerSettingsPackage(std::string, double, double, double, int, int);

    /**
     * @brief
     * @return Returns the string containing the user specified particle placement (or null)
     */
    std::string getParticlePlacementString();
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
     * @brief
     * @return Returns an int containing the maximum number of iterations
     */
    int getMaxIterations();
    /**
     * @brief
     * @return Returns an int containing the accuracy at which to halt the optimizer
     */
    int getCutoffAcc();
    
    
    /**
     * @brief Sets the Particle Placement
     * @param ParticlePlacement (string pointer)
     */
    void setParticlePlacementString(std::string);
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
    /**
     * @brief Sets the maximum number of iterations for the optimizer
     * @param maxIterations (int)
     */
    void setMaxIterations(int);
    /**
     * @brief Sets the accuracy level at which to halt the optimizer
     * @param cutoffAcc (int)
     */
    void setCutoffAcc(int);
    
    
    
    
    
};

#endif // OPTIMIZERSETTINGSPACKAGE_H
