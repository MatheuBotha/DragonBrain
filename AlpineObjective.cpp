//
// Created by gerard on 2016/10/02.
//

#include "AlpineObjective.h"

double AlpineObjective::functionInput(double *parameters){
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);
    for (int i = 0; i < 2; ++i) {
        result += abs(x1*sin(parameters[i])+0.1*x2);
    }

    return transformOutput(result);
}