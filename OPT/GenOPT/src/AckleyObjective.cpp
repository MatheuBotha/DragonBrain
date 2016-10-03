//
// Created by gerard on 2016/09/25.
//

#include "AckleyObjective.h"

double AckleyObjective :: functionInput(double * parameters){
    double result = -1.0;

    double a=20;
    double b=0.2;
    double c=2*M_1_PI;
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
}