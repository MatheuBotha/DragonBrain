//
// Created by gerard on 2016/10/03.
//

#ifndef OBJECTIVETEST_ZAKHAROVOBJECTIVE_H
#define OBJECTIVETEST_ZAKHAROVOBJECTIVE_H


#include "ObjectiveFunction.h"
class ZakharovObjective : public ObjectiveFunction{
public:
ZakharovObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=-5.0+x;
    defaultBounds[1]=10.0+x;
    defaultBounds[2]=-5.0+y;
    defaultBounds[3]=10.0+y;
}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_ZAKHAROVOBJECTIVE_H
