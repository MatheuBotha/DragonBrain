#ifndef PROBLEMDOMAINSETTINGSPACKAGE_H
#define PROBLEMDOMAINSETTINGSPACKAGE_H

#include <string>

/**
 * @class ProblemDomainSettingsPackage
 *
 * This class is a wrapper for all the settings related to the problem Domain
 * The contents are rather simplistic, only getters and setters.
 * */


class ProblemDomainSettingsPackage
{
private:
    //This will become an ObjectiveFunction type once possible
    std::string objectiveFunction;
    int dimensions;
    int boundaries[4];
    int transformations[3];
public:
    /**
     * @brief The default constructor for a ProblemDomainSettingsPackage
     */
    ProblemDomainSettingsPackage();
    /**
     * @brief Creates a ProblemDomainSettingsPackage with specified settings (currently unused)
     * @param ObjectiveFunction (string)
     * @param Dimensions (int)
     * @param Boundaries (int[4])
     * @param Transformations (int[3])
     */
    ProblemDomainSettingsPackage(std::string, int, int[4], int[3]);
    /**
     * @brief
     * @return Returns the objective function (currently as a string)
     */
    std::string getObjectiveFunction();
    /**
     * @brief
     * @return Returns an integer containing the number of dimensions for the problem (1 or 2)
     */
    int getDimensions();
    /**
     * @brief Takes an array in and copies the boundary array into it
     * @param copyArray
     */
    void getBoundaries(int inArray[4]);
    /**
     * @brief Takes an array in and copies the transformations array into it
     * @param inArray
     */
    void getTransformations(int inArray[3]);

    /**
     * @brief Sets the objective function
     * @param inObjF (string)
     */
    void setObjectiveFunction(std::string inObjF);
    /**
     * @brief Sets the number of dimensions for the problem
     * @param dimensions (int)
     */
    void setDimensions(int);
    /**
     * @brief Sets the boundary values for the dimensions
     * @param An integer array of size 4, where if dimensions are 2, then arr[2] and arr[3] will be ignored
     */
    void setBoundaries(int[4]);
    /**
     * @brief Sets the transformation values for the problem
     * @param An integer array of size 3.
     */
    void setTransformations(int[3]);

};

#endif // PROBLEMDOMAINSETTINGSPACKAGE_H
