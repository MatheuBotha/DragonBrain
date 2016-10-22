//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_STEPOBJECTIVE_H
#define OBJECTIVETEST_STEPOBJECTIVE_H


#include "ObjectiveFunction.h"
class StepObjective : public ObjectiveFunction{
public:
StepObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=-20.0+x;
    defaultBounds[1]=20.0+x;
    defaultBounds[2]=-20.0+y;
    defaultBounds[3]=20.0+y;
}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_STEPOBJECTIVE_H
