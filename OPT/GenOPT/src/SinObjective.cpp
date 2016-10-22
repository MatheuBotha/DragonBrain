//
// Created by gerard on 2016/09/07.
//

#include "SinObjective.h"
#include <float.h>

double SinObjective::functionInput(double *parameters) {
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);
    result = sin(x1)+sin(x2);

    return transformOutput(result);
}
