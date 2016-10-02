//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_QUADRICOBJECTIVE_H
#define OBJECTIVETEST_QUADRICOBJECTIVE_H


#include "ObjectiveFunction.h"
class QuadricObjective : public ObjectiveFunction{
public:
QuadricObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_QUADRICOBJECTIVE_H
