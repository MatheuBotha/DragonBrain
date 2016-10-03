//
// Created by gerard on 2016/10/02.
//

#include "Schwefel26Objective.h"
double Schwefel26Objective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    result = -((x1*sin(sqrt(abs(x1))))+(x2*sin(sqrt(abs(x2)))));

    return transformOutput(result);
}