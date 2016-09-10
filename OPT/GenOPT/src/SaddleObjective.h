//
// Created by gerard on 2016/09/07.
//

#ifndef SADDLEOBJECTIVE_H
#define SADDLEOBJECTIVE_H

#include "ObjectiveFunction.h"
#include <cstdlib>

class SaddleObjective : public ObjectiveFunction {
public:
    SaddleObjective(){

    }

    double functionInput(double * parameters);
};


#endif //SIMPLEOPT_SADDLEOBJECTIVE_H
