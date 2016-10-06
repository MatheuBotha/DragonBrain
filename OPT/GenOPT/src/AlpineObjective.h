//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_ALPINEOBJECTIVE_H
#define OBJECTIVETEST_ALPINEOBJECTIVE_H


#include "ObjectiveFunction.h"

class AlpineObjective : public ObjectiveFunction{
public:
    AlpineObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
        defaultBounds[0]=-10.0;
        defaultBounds[1]=10.0;
        defaultBounds[2]=-10.0;
        defaultBounds[3]=10.0;
    }

    double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_ALPINEOBJECTIVE_H
