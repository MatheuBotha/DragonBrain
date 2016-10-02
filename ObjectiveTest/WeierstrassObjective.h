//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_WEIERSTRASSOBJECTIVE_H
#define OBJECTIVETEST_WEIERSTRASSOBJECTIVE_H


#include "ObjectiveFunction.h"
class WeierstrassObjective : public ObjectiveFunction{
public:
WeierstrassObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_WEIERSTRASSOBJECTIVE_H
