//
// Created by gerard on 2016/10/02.
//

#include "WeierstrassObjective.h"
double WeierstrassObjective::functionInput(double *parameters){
    double result;
    transformInput(parameters);
    double x1 = parameters[0];
    double x2 = parameters[1];

    double sum1 = 0.0;
    double sum2 = 0.0;

    for (int i = 0; i < 2; ++i) {
        for (int k = 0; k <= 20; ++k) {
            sum1 += (pow(0.5,k)*cos(2*M_PI*pow(3,k)*(parameters[i]+0.5)));
        }
    }

    for (int j = 0; j <= 20; ++j) {
        sum2 += (pow(0.5,j)*cos(2*M_PI*pow(3,j)*0.5));
    }

    result = sum1 - 2*sum2;

    return transformOutput(result);
}