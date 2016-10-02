//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_SKEWRASTRIGINOBJECTIVE_H
#define OBJECTIVETEST_SKEWRASTRIGINOBJECTIVE_H


#include "ObjectiveFunction.h"
class SkewRastriginObjective : public ObjectiveFunction{
public:
SkewRastriginObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_SKEWRASTRIGINOBJECTIVE_H
