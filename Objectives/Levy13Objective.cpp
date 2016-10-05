//
// Created by gerard on 2016/10/02.
//

#include "Levy13Objective.h"
double Levy13Objective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    double term1 = pow((sin(3*M_PI*x1)),2);
    double term2 = pow((x1-1),2) * (1+pow((sin(3*M_PI*x2)),2));
    double term3 = pow((x2-1),2) * (1+pow((sin(2*M_PI*x2)),2));

    result = term1 + term2 + term3;

    return transformOutput(result);
}