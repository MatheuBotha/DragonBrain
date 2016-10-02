//
// Created by gerard on 2016/09/07.
//

#include "SaddleObjective.h"

double SaddleObjective::functionInput(double *parameters) {
    double result;
    transformInput(parameters);

    result = parameters[0] * parameters[1];

    return transformOutput(result);
}