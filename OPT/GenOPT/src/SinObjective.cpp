//
// Created by gerard on 2016/09/07.
//

#include "SinObjective.h"
#include <float.h>
double SinObjective::functionInput(double *parameters) {
    double result;
    setParams(parameters);

    if(parameters[1] != DBL_MAX)
        result = sin(x)+sin(y); //2D only for now.
    else {
        result = sin(x);
    }

    return transformResult(result);
}
