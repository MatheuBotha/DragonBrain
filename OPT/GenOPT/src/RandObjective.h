//
// Created by gerard on 2016/09/07.
//

#ifndef SIMPLEOPT_RANDOBJECTIVE_H
#define SIMPLEOPT_RANDOBJECTIVE_H

#include "ObjectiveFunction.h"
#include <random>

class RandObjective : public ObjectiveFunction {
public:
    RandObjective(){

    }

    double functionInput(double * parameters);
};


#endif //SIMPLEOPT_RANDOBJECTIVE_H
