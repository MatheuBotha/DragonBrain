//
// Created by gerard on 2016/10/03.
//

#include "AckleyObjective.h"
<<<<<<< Updated upstream
double AckleyObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];
    double a = 20.0;
    double b = 0.2;
    double c = 2*M_PI;

    result = -a*exp(-b*sqrt(0.5*(pow(x1,2)+pow(x2,2))))-exp(0.5*(cos(c*x1)+cos(c*x2)))+a+exp(1);

    return transformOutput(result);
=======

double AckleyObjective :: functionInput(double * parameters){
    double result = -1.0;

    double a=20;
    double b=0.3;
    double c=2*M_PI;
    double d=2;

    double term1=0.0;
    double term2=0.0;

    for (int i = 0; i < d; ++i) {
        term1+=parameters[i]*parameters[i];
    }
    term1=-b*sqrt((1/d)*term1);

    for (int j = 0; j < d; ++j) {
        term2+=cos(c*parameters[j]);
    }
    term2=(1/d)*term2;

    result = -a*exp(term1)-exp(term2)+a+exp(1);

    return result;
>>>>>>> Stashed changes
}