//
// Created by gerard on 2016/09/07.
//

#include "RandObjective.h"

double RandObjective::functionInput(double *parameters) {
    double result;

    //Type of random number distribution
    std::uniform_real_distribution<double> dist(-1.0, 1.0);  //(min, max)
    //Mersenne Twister: Good quality random number generator
    std::mt19937 rng;
    //Initialize with deterministic seeds for consistent fitness landscape.
    unsigned long seed;
    if((parameters[0] * parameters[0] * parameters[1] * parameters[1])<0){
        seed = (unsigned long)(-(parameters[0] * parameters[0] * parameters[1] * parameters[1]));
    }else{
        seed = (unsigned long)(parameters[0] * parameters[0] * parameters[1] * parameters[1]);
    }
    rng.seed(seed);
    result = dist(rng);

    return result;
}