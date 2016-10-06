//
// Created by gerard on 2016/10/02.
//

#include "Schwefel22Objective.h"
double Schwefel22Objective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    result = abs(x1)+abs(x2);
    result += abs(x1)*abs(x2);

    return transformOutput(result);
}