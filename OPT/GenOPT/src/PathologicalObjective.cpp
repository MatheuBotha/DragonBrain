//
// Created by gerard on 2016/10/02.
//

#include "PathologicalObjective.h"
double PathologicalObjective::functionInput(double *parameters){
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);

    result = 0.5 + (pow(sin(sqrt(100*pow(x1,2)+pow(x2,2))),2)-0.5)
                   /(1+0.001*pow(pow(x1,2)-2*x1*x2+pow(x2,2),2));

    return transformOutput(result);
}