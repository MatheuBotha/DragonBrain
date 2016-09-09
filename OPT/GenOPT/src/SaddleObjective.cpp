//
// Created by gerard on 2016/09/07.
//

#include "SaddleObjective.h"

double SaddleObjective::functionInput(double *parameters) {
    double result;

    result = parameters[0] * parameters[1]; //2D only for now.

    return result;
}