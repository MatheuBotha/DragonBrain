//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_ROSENBROCKOBJECTIVE_H
#define OBJECTIVETEST_ROSENBROCKOBJECTIVE_H


#include "ObjectiveFunction.h"
class RosenbrockObjective : public ObjectiveFunction{
public:
    RosenbrockObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
        defaultBounds[0]=-2.048+x;
        defaultBounds[1]=2.048+x;
        defaultBounds[2]=-2.048+y;
        defaultBounds[3]=2.048+y;
    }

    double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_ROSENBROCKOBJECTIVE_H
