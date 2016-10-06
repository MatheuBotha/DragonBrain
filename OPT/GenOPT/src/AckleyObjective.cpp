//
// Created by gerard on 2016/10/03.
//

#include "AckleyObjective.h"
double AckleyObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];
    double a = 20.0;
    double b = 0.2;
    double c = 2*M_PI;

    result = -a*exp(-b*sqrt(0.5*(pow(x1,2)+pow(x2,2))))-exp(0.5*(cos(c*x1)+cos(c*x2)))+a+exp(1);

    return transformOutput(result);
}