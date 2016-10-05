//
// Created by gerard on 2016/10/02.
//

#include "AlpineObjective.h"

double AlpineObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);

    for (int i = 0; i < 2; ++i) {
        result += abs(parameters[i]*sin(parameters[i])+0.1*parameters[i]);
    }

    return transformOutput(result);
}