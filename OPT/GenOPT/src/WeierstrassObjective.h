//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_WEIERSTRASSOBJECTIVE_H
#define OBJECTIVETEST_WEIERSTRASSOBJECTIVE_H


#include "ObjectiveFunction.h"
class WeierstrassObjective : public ObjectiveFunction{
public:
WeierstrassObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=-0.5+x;
    defaultBounds[1]=0.5+x;
    defaultBounds[2]=-0.5+y;
    defaultBounds[3]=0.5+y;
}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_WEIERSTRASSOBJECTIVE_H
