//
// Created by gerard on 2016/10/02.
//

#include "BohachevskyObjective.h"

double BohachevskyObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    result = (pow(x1,2)+2*pow(x2,2)-0.3*cos(3*M_PI*x1)-0.4*cos(4*M_PI*x2)+0.7);

    return transformOutput(result);
}