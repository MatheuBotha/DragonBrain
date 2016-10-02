//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_BEALEOBJECTIVE_H
#define OBJECTIVETEST_BEALEOBJECTIVE_H

#include "ObjectiveFunction.h"

class BealeObjective : public ObjectiveFunction{
public:
    BealeObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

    }

    double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_BEALEOBJECTIVE_H
