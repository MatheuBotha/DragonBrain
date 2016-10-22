//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_RANAOBJECTIVE_H
#define OBJECTIVETEST_RANAOBJECTIVE_H


#include "ObjectiveFunction.h"
class RanaObjective : public ObjectiveFunction{
public:
RanaObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=-512.0+x;
    defaultBounds[1]=512.0+x;
    defaultBounds[2]=-512.0+y;
    defaultBounds[3]=512.0+y;
}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_RANAOBJECTIVE_H
