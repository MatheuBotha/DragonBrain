//
// Created by gerard on 2016/09/07.
//

#ifndef SIMPLEOPT_SADDLEOBJECTIVE_H
#define SIMPLEOPT_SADDLEOBJECTIVE_H

#include "ObjectiveFunction.h"
#include <cstdlib>

class SaddleObjective {
public:
    SaddleObjective(){

    }

    double functionInput(double * parameters);
};


#endif //SIMPLEOPT_SADDLEOBJECTIVE_H
