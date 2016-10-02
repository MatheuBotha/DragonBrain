//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_GOLDSTEINPRICEOBJECTIVE_H
#define OBJECTIVETEST_GOLDSTEINPRICEOBJECTIVE_H


#include "ObjectiveFunction.h"

class GoldSteinPriceObjective : public ObjectiveFunction{
public:
GoldSteinPriceObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_GOLDSTEINPRICEOBJECTIVE_H
