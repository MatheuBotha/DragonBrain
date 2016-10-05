//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_GOLDSTEINPRICEOBJECTIVE_H
#define OBJECTIVETEST_GOLDSTEINPRICEOBJECTIVE_H


#include "ObjectiveFunction.h"

class GoldSteinPriceObjective : public ObjectiveFunction{
public:
GoldSteinPriceObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=-2.0;
    defaultBounds[1]=2.0;
    defaultBounds[2]=-2.0;
    defaultBounds[3]=2.0;
}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_GOLDSTEINPRICEOBJECTIVE_H
