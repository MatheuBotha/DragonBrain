//
// Created by gerard on 2016/10/02.
//

#include "SalomonObjective.h"
double SalomonObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    result = -cos(2*M_PI*(pow(x1,2)+pow(x2,2)))+0.1*sqrt(pow(x1,2)+pow(x2,2))+1;

    return transformOutput(result);
}