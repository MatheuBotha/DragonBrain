//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_LEVY13OBJECTIVE_H
#define OBJECTIVETEST_LEVY13OBJECTIVE_H

#include "ObjectiveFunction.h"
class Levy13Objective : public ObjectiveFunction{
public:
Levy13Objective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=-10.0+x;
    defaultBounds[1]=10.0+x;
    defaultBounds[2]=-10.0+y;
    defaultBounds[3]=10.0+y;
}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_LEVY13OBJECTIVE_H
