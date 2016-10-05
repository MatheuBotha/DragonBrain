//
// Created by gerard on 2016/10/02.
//

#include "SixHumpCamelBackObjective.h"
double SixHumpCamelBackObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    result = 4*pow(x1,2)-2.1*pow(x1,4)+(1/3)*pow(x1,6)+x1*x2-4*pow(x2,2)+4*pow(x2,4);

    return transformOutput(result);
}