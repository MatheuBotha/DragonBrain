//
// Created by gerard on 2016/10/02.
//

#include "SkewRastriginObjective.h"
double SkewRastriginObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    if(x1>0){
        x1*=10;
    }
    if(x2>0){
        x2*=10;
    }
    result = 20+((pow(x1,2)-10*cos(2*M_PI*x1))+(pow(x2,2)-10*cos(2*M_PI*x2)));

    return transformOutput(result);
}