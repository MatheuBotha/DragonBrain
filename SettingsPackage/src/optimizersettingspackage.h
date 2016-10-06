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
    std::string algorithm;
    std::string particlePlacement;
    double inertiaWeight;
    double cognitiveCoefficient;
    double socialCoefficient;
    double constrictionCoefficient;
    double maxVelocity;
    int successCount;
    int failCount;
    int neighbourhoodSize;
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
     * @return Returns the string containing the algorithm name
     */
    std::string getAlgorithm();
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
     * @return Returns a double containing the constriction coefficient
     */
    double getConstrictionCoefficient();


    /**
    * @brief
    * @return Returns a double containing the maximum velocity (CPSO)
    */
    double getMaxVelocity();

    /**
     * @brief
     * @return Returns an int containing the failure count (GCPSO)
     */
    int getFailCount();


    /**
     * @brief
     * @return Returns an int containing the success count (GCPSO)
     */
    int getSuccessCount();

        /**
     * @brief
     * @return Returns an int containing the neighbourhood size (FIPS)
     */
    int getNeighbourhoodSize();

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
    void setAlgorithm(std::string);

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


    /**
    * @brief Sets the constriction coefficient
    * @param constrictionCoefficient (double)
     */
    void setConstrictionCoefficient(double);


    /**
    * @brief Sets the maximum velocity (CPSO)
    * @param maxVelocity (double)
     */
    void setMaxVelocity(double);

    /**
    * @brief Sets the fail count (GCPSO)
    * @param failCount(int)
     */
    void setFailCount(int);

    /**
    * @brief Sets the success count (GCPSO)
    * @param successCount (int)
     */
    void setSuccessCount(int);

    /**
    * @brief Sets the neighbourhood size (FIPS)
    * @param neighbourhoodSize (int)
     */
    void setNeighbourhoodSize(int);

    void setMaxIterations(int);
    /**
     * @brief Sets the accuracy level at which to halt the optimizer
     * @param cutoffAcc (int)
     */
    void setCutoffAcc(int);
    
    
    
    
    
};

#endif // OPTIMIZERSETTINGSPACKAGE_H
