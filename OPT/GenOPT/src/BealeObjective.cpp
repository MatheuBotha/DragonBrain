//
// Created by gerard on 2016/10/02.
//

#include "BealeObjective.h"
double BealeObjective::functionInput(double *parameters){
    double result=0.0;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[0];

    result = pow((1.5-x1+x1*x2),2)+pow((2.25-x1+x1*pow(x2,2)),2)+pow((2.625-x1+x1*pow(x2,3)),2);

    return transformOutput(result);
}