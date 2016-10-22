//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_BOHACHEVSKYOBJECTIVE_H
#define OBJECTIVETEST_BOHACHEVSKYOBJECTIVE_H

#include "ObjectiveFunction.h"

class BohachevskyObjective: public ObjectiveFunction{
public:
    BohachevskyObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
        defaultBounds[0]=-15.0+x;
        defaultBounds[1]=15.0+x;
        defaultBounds[2]=-15.0+y;
        defaultBounds[3]=15.0+y;
    }

    double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_BOHACHEVSKYOBJECTIVE_H
