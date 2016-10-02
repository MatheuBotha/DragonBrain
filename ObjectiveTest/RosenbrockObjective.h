//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_ROSENBROCKOBJECTIVE_H
#define OBJECTIVETEST_ROSENBROCKOBJECTIVE_H


#include "ObjectiveFunction.h"
class RosenbrockObjective : public ObjectiveFunction{
public:
    RosenbrockObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

    }

    double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_ROSENBROCKOBJECTIVE_H
