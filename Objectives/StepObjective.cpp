//
// Created by gerard on 2016/10/02.
//

#include "StepObjective.h"
double StepObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    result = pow(abs(x1+0.5),2)+pow(abs(x2+0.5),2);

    return transformOutput(result);
}