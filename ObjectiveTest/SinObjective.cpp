//
// Created by gerard on 2016/09/07.
//

#include "SinObjective.h"
#include <float.h>

double SinObjective::functionInput(double *parameters) {
    double result;
    transformInput(parameters);

    result = sin(parameters[0])+sin(parameters[1]);

    return transformOutput(result);
}
