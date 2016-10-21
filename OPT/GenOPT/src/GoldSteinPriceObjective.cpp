//
// Created by gerard on 2016/10/02.
//

#include "GoldSteinPriceObjective.h"
double GoldSteinPriceObjective::functionInput(double *parameters){
    double result;
    double x1 = parameters[0];
    double x2 = parameters[1];
    x1 = transformX1(x1);
    x2 = transformX2(x2);

    result = (1+pow(x1+x2+1,2)*(19-14*x1+3*pow(x1,2)-14*x2+6*x1*x2+3*pow(x2,2)))*
            (30+pow(2*x1-3*x2,2)*(18-32*x1+12*pow(x1,2)+48*x2-36*x1*x2+27*pow(x2,2)));

    return transformOutput(result);
}