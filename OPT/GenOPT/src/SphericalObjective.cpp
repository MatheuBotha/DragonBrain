//
// Created by gerard on 2016/10/02.
//

#include "SphericalObjective.h"
double SphericalObjective::functionInput(double *parameters){
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);

    result = pow(x1,2)+pow(x2,2);

    return transformOutput(result);
}