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
    std::string algorithm2;
    std::string algorithm3;
    std::string algorithm4;
    double cognitiveCoefficient;
    double socialCoefficient;
    double inertiaWeight;

    double maxVelocity;
    int successCount;
    int failCount;
    int neighbourhoodSize;
    int maxIterations;
public:
    /**
     * @brief The default constructor for an OptimizerSettingsPackage
     */
    OptimizerSettingsPackage();

    /**
     * @brief
     * @return Returns the string containing the (i'th) algorithm name
     */
    std::string getAlgorithm(int i);
    /**
     * @brief
     * @return Returns a double containing the inertia weight
     */
    double getCognitiveCoefficient();
    /**
     * @brief
     * @return Returns a double containing the social coefficient
     */
    double getSocialCoefficient();


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
     * @brief Sets the Particle Placement
     * @param ParticlePlacement (string pointer)
     */
    void setAlgorithms(std::string, std::string, std::string, std::string);

    /**
     * @brief Sets the Particle Placement
     * @param ParticlePlacement (string pointer)
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

    void setInertiaWeight(double d);

    double getInertiaWeight();
};

#endif // OPTIMIZERSETTINGSPACKAGE_H
