//
// Created by gerard on 2016/10/02.
//

#include "SalomonObjective.h"
double SalomonObjective::functionInput(double *parameters){
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);

    result = -cos(2*M_PI*(pow(x1,2)+pow(x2,2)))+0.1*sqrt(pow(x1,2)+pow(x2,2))+1;

    return transformOutput(result);
}