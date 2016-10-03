//
// Created by gerard on 2016/09/07.
//

#ifndef SIMPLEOPT_SINOBJECTIVE_H
#define SIMPLEOPT_SINOBJECTIVE_H

#include "ObjectiveFunction.h"
#include "math.h"

class SinObjective : public ObjectiveFunction{
public:
    SinObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
        defaultBounds[0]=-8.0;
        defaultBounds[1]=8.0;
        defaultBounds[2]=-8.0;
        defaultBounds[3]=8.0;
    }

    double functionInput(double * parameters);
};


#endif //SIMPLEOPT_SINOBJECTIVE_H
