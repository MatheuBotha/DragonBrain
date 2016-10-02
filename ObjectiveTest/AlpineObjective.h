//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_ALPINEOBJECTIVE_H
#define OBJECTIVETEST_ALPINEOBJECTIVE_H


#include "ObjectiveFunction.h"

class AlpineObjective : public ObjectiveFunction{
public:
    AlpineObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

    }

    double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_ALPINEOBJECTIVE_H
