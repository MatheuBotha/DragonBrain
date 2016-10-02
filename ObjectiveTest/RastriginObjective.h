//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_RASTRIGINOBJECTIVE_H
#define OBJECTIVETEST_RASTRIGINOBJECTIVE_H


#include "ObjectiveFunction.h"
class RastriginObjective : public ObjectiveFunction{
public:
RastriginObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_RASTRIGINOBJECTIVE_H
