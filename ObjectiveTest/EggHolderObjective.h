//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_EGGHOLDEROBJECTIVE_H
#define OBJECTIVETEST_EGGHOLDEROBJECTIVE_H


#include "ObjectiveFunction.h"

class EggHolderObjective : public ObjectiveFunction{
public:
EggHolderObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_EGGHOLDEROBJECTIVE_H
