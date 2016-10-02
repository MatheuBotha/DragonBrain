//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_SCHWEFEL22OBJECTIVE_H
#define OBJECTIVETEST_SCHWEFEL22OBJECTIVE_H


#include "ObjectiveFunction.h"
class Schwefel22Objective : public ObjectiveFunction{
public:
Schwefel22Objective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};

#endif //OBJECTIVETEST_SCHWEFEL22OBJECTIVE_H
