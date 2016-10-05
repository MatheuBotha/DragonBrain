//
// Created by gerard on 2016/10/02.
//

#include "QuadricObjective.h"
double QuadricObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    result = pow(x1,2);
    result += pow(x1+x2,2);

    return transformOutput(result);
}