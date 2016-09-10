//
// Created by gerard on 2016/09/07.
//

#ifndef SINOBJECTIVE_H
#define SINOBJECTIVE_H

#include "ObjectiveFunction.h"
#include "math.h"

class SinObjective : public ObjectiveFunction{
public:
    SinObjective(){

    }

    double functionInput(double * parameters);
};


#endif //SIMPLEOPT_SINOBJECTIVE_H
