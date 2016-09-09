//
// Created by gerard on 2016/09/07.
//

#include "SaddleObjective.h"

double SaddleObjective::functionInput(double *parameters) {
    double result;

    result = pow(parameters[0],2)+pow(parameters[1],2); //2D only for now.

    return result;
}