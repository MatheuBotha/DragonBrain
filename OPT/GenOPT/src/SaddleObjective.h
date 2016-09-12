//
// Created by gerard on 2016/09/07.
//

#ifndef SIMPLEOPT_SADDLEOBJECTIVE_H
#define SIMPLEOPT_SADDLEOBJECTIVE_H

#include "ObjectiveFunction.h"
#include <cstdlib>

class SaddleObjective : public ObjectiveFunction {
public:
    SaddleObjective(double s, double h, double v): ObjectiveFunction(s, h, v)
    {

    }

    double functionInput(double * parameters);
};


#endif //SIMPLEOPT_SADDLEOBJECTIVE_H
