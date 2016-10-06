//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_BOHACHEVSKYOBJECTIVE_H
#define OBJECTIVETEST_BOHACHEVSKYOBJECTIVE_H

#include "ObjectiveFunction.h"

class BohachevskyObjective: public ObjectiveFunction{
public:
    BohachevskyObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
        defaultBounds[0]=-15.0;
        defaultBounds[1]=15.0;
        defaultBounds[2]=-15.0;
        defaultBounds[3]=15.0;
    }

    double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_BOHACHEVSKYOBJECTIVE_H
