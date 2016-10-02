//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_STEPOBJECTIVE_H
#define OBJECTIVETEST_STEPOBJECTIVE_H


#include "ObjectiveFunction.h"
class StepObjective : public ObjectiveFunction{
public:
StepObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_STEPOBJECTIVE_H
