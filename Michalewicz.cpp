//
// Created by gerard on 2016/10/02.
//

#include "Michalewicz.h"
double MichalewiczObjective::functionInput(double *parameters){
    double result;
//    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);
    double m = 10;
    result = -(sin(x1)*pow(sin(pow(x1,2)/M_PI),2*m));
    result += -(sin(x2)*pow(sin(pow(x2,2)/M_PI),2*m));

    return transformOutput(result);
}