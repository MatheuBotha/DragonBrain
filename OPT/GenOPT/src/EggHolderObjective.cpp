//
// Created by gerard on 2016/10/02.
//

#include "EggHolderObjective.h"
double EggHolderObjective::functionInput(double *parameters){
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);

    result = -(x2+47.0)*sin(sqrt(abs(x2+(x1/2.0)+47.0)))+sin(sqrt(abs(x1-(x2+47.0))))*(-x1);

    return transformOutput(result);
}