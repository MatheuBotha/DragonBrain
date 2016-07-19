#include "problemdomainsettingspackage.h"

ProblemDomainSettingsPackage::ProblemDomainSettingsPackage()
{

}

ProblemDomainSettingsPackage::ProblemDomainSettingsPackage(std::string objF, int n, int bounds[4], double trans[3])
{
    objectiveFunction = objF;
    dimensions = n;
    boundaries[0] = bounds[0];
    boundaries[1] = bounds[1];
    boundaries[2] = bounds[2];
    boundaries[3] = bounds[3];
    transformations[0] = trans[0];
    transformations[1] = trans[1];
    transformations[2] = trans[2];

}

std::string ProblemDomainSettingsPackage::getObjectiveFunction()
{
    return objectiveFunction;
}

int ProblemDomainSettingsPackage::getDimensions()
{
    return dimensions;
}

void ProblemDomainSettingsPackage::getBoundaries(int inArray[])
{
    inArray[0] = boundaries[0];
    inArray[1] = boundaries[1];
    inArray[2] = boundaries[2];
    inArray[3] = boundaries[3];
}

void ProblemDomainSettingsPackage::getTransformations(double inArray[])
{
    inArray[0] = transformations[0];
    inArray[1] = transformations[1];
    inArray[2] = transformations[2];

}

void ProblemDomainSettingsPackage::setObjectiveFunction(std::string inObjF)
{
    objectiveFunction = inObjF;
}

void ProblemDomainSettingsPackage::setDimensions(int n)
{
    dimensions = n;
}

void ProblemDomainSettingsPackage::setBoundaries(int newBounds[4])
{
    boundaries[0] = newBounds[0];
    boundaries[1] = newBounds[1];
    boundaries[2] = newBounds[2];
    boundaries[3] = newBounds[3];
}

void ProblemDomainSettingsPackage::setTransformations(double newTrans[3])
{
    transformations[0] = newTrans[0];
    transformations[1] = newTrans[1];
    transformations[2] = newTrans[2];
}
