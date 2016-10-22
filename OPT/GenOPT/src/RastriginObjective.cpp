//
// Created by gerard on 2016/10/02.
//

#include "RastriginObjective.h"
double RastriginObjective::functionInput(double *parameters){
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);

    result = (pow(x1,2)-10*cos(2*M_PI*x1)+10);
    result += (pow(x2,2)-10*cos(2*M_PI*x2)+10);

    return transformOutput(result);
}