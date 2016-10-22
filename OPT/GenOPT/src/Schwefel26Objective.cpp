//
// Created by gerard on 2016/10/02.
//

#include "Schwefel26Objective.h"
double Schwefel26Objective::functionInput(double *parameters){
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);

    result = -((x1*sin(sqrt(abs(x1))))+(x2*sin(sqrt(abs(x2)))));

    return transformOutput(result);
}