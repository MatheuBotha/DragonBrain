//
// Created by gerard on 2016/09/07.
//

#include "SaddleObjective.h"

double SaddleObjective::functionInput(double *parameters) {
    double result;
    setParams(parameters);
    result = x * y; //2D only for now.

    return transformResult(result);
}