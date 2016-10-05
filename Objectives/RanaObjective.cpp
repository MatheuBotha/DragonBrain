//
// Created by gerard on 2016/10/02.
//

#include "RanaObjective.h"
double RanaObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    result = x1*sin(sqrt(abs(x2+1-x1)))*cos(sqrt(abs(x1+x2+1)))+cos(sqrt(abs(x2+1-x1)))*sin(sqrt(abs(x1+x2+1)));

    return transformOutput(result);
}