//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_SIXHUMPCAMELBACKOBJECTIVE_H
#define OBJECTIVETEST_SIXHUMPCAMELBACKOBJECTIVE_H


#include "ObjectiveFunction.h"
class SixHumpCamelBackObjective : public ObjectiveFunction{
public:
    SixHumpCamelBackObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
        defaultBounds[0]=-5.0;
        defaultBounds[1]=5.0;
        defaultBounds[2]=-5.0;
        defaultBounds[3]=5.0;
}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_SIXHUMPCAMELBACKOBJECTIVE_H
