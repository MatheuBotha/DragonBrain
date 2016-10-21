//
// Created by gerard on 2016/10/02.
//

#include "SixHumpCamelBackObjective.h"
double SixHumpCamelBackObjective::functionInput(double *parameters){
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);
    result = 4*pow(x1,2)-2.1*pow(x1,4)+(1/3)*pow(x1,6)+x1*x2-4*pow(x2,2)+4*pow(x2,4);

    return transformOutput(result);
}