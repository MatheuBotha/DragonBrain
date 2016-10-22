//
// Created by gerard on 2016/09/07.
//

#include "SaddleObjective.h"

double SaddleObjective::functionInput(double *parameters) {
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);
    result = x1 + x2;

    return transformOutput(result);
}