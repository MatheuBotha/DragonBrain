//
// Created by gerard on 2016/10/02.
//

#include "GriewankObjective.h"

double GriewankObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    result = 1+(1/4000)*pow(x1,2)+(1/4000)*pow(x2,2)-cos(x1)*cos(0.5*x2*sqrt(2));

    return transformOutput(result);
}