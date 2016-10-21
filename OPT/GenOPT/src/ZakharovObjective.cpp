//
// Created by gerard on 2016/10/03.
//

#include "ZakharovObjective.h"
double ZakharovObjective::functionInput(double *parameters){
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);

    result = pow(x1,2)+pow(x2,2)+pow(x1/2+x2,2)+pow(x1/2+x2,4);

    return transformOutput(result);
}