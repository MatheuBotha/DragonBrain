//
// Created by gerard on 2016/09/07.
//

#include "SinObjective.h"

double SinObjective::functionInput(double *parameters) {
    double result;

    result = sin(parameters[0])+sin(parameters[1]); //2D only for now.

    return result;
}
