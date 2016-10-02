//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_SPHERICALOBJECTIVE_H
#define OBJECTIVETEST_SPHERICALOBJECTIVE_H


#include "ObjectiveFunction.h"
class SphericalObjective : public ObjectiveFunction{
public:
SphericalObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_SPHERICALOBJECTIVE_H
