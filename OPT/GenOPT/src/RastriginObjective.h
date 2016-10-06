//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_RASTRIGINOBJECTIVE_H
#define OBJECTIVETEST_RASTRIGINOBJECTIVE_H


#include "ObjectiveFunction.h"
class RastriginObjective : public ObjectiveFunction{
public:
RastriginObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=-5.12;
    defaultBounds[1]=5.12;
    defaultBounds[2]=-5.12;
    defaultBounds[3]=5.12;
}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_RASTRIGINOBJECTIVE_H
