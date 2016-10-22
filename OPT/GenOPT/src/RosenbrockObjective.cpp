//
// Created by gerard on 2016/10/02.
//

#include "RosenbrockObjective.h"
double RosenbrockObjective::functionInput(double *parameters){
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);

    result = (100*pow(x2-pow(x1,2),2)+pow(x1-1,2));

    return transformOutput(result);
}