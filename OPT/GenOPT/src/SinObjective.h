//
// Created by gerard on 2016/09/07.
//

#ifndef SIMPLEOPT_SINOBJECTIVE_H
#define SIMPLEOPT_SINOBJECTIVE_H

#include "ObjectiveFunction.h"
#include "math.h"

class SinObjective : public ObjectiveFunction{
public:
    SinObjective(double g, double h, double v): ObjectiveFunction(g, h , v)
    {

    }

    double functionInput(double * parameters);
};


#endif //SIMPLEOPT_SINOBJECTIVE_H
