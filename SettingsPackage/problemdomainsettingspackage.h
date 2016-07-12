#ifndef PROBLEMDOMAINSETTINGSPACKAGE_H
#define PROBLEMDOMAINSETTINGSPACKAGE_H

#include <string>

class ProblemDomainSettingsPackage
{
private:
    //This will become an ObjectiveFunction type once possible
    std::string objectiveFunction;
    int dimensions;
    int boundaries[4];
    int transformations[3];
public:
    ProblemDomainSettingsPackage();
    ProblemDomainSettingsPackage(std::string, int, int[4], int[3]);
    std::string getObjectiveFunction();
    int getDimensions();
    void getBoundaries(int inArray[4]);
    void getTransformations(int inArray[3]);

    void setObjectiveFunction(std::string inObjF);
    void setDimensions(int);
    void setBoundaries(int[4]);
    void setTransformations(int[3]);

};

#endif // PROBLEMDOMAINSETTINGSPACKAGE_H
