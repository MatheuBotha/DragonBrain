//
// Created by gerard on 2016/09/07.
//

#ifndef SIMPLEOPT_SADDLEOBJECTIVE_H
#define SIMPLEOPT_SADDLEOBJECTIVE_H

#include "ObjectiveFunction.h"
#include <cstdlib>

class SaddleObjective : public ObjectiveFunction {
public:
    SaddleObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v)
    {
        defaultBounds[0]=-10.0;
        defaultBounds[1]=10.0;
        defaultBounds[2]=-10.0;
        defaultBounds[3]=10.0;
    }

    double functionInput(double * parameters);
};


#endif //SIMPLEOPT_SADDLEOBJECTIVE_H
