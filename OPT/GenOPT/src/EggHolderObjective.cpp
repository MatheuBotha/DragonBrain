//
// Created by gerard on 2016/10/02.
//

#include "EggHolderObjective.h"
double EggHolderObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    result = -(x2+47)*sin(sqrt(abs(x2+x1/2+47)))+sin(sqrt(abs(x1-(x2+47))))*(-x1);

    return transformOutput(result);
}