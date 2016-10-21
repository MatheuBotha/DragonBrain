//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_SCHWEFEL26OBJECTIVE_H
#define OBJECTIVETEST_SCHWEFEL26OBJECTIVE_H


#include "ObjectiveFunction.h"
class Schwefel26Objective : public ObjectiveFunction{
public:
Schwefel26Objective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=-500.0+x;
    defaultBounds[1]=500.0+x;
    defaultBounds[2]=-500.0+y;
    defaultBounds[3]=500.0+y;
}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_SCHWEFEL26OBJECTIVE_H
