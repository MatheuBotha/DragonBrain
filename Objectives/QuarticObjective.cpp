//
// Created by gerard on 2016/10/02.
//

#include "QuarticObjective.h"
double QuarticObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    result = pow(x1,4);
    result += 2*pow(x2,4);

    return transformOutput(result);
}