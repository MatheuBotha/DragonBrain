//
// Created by gerard on 2016/09/07.
//

#ifndef SIMPLEOPT_SINOBJECTIVE_H
#define SIMPLEOPT_SINOBJECTIVE_H

#include "ObjectiveFunction.h"
#include "math.h"

class SinObjective{
public:
    SinObjective(){

    }

    double functionInput(double * parameters);
};


#endif //SIMPLEOPT_SINOBJECTIVE_H
