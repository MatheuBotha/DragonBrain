//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_SALOMONOBJECTIVE_H
#define OBJECTIVETEST_SALOMONOBJECTIVE_H


#include "ObjectiveFunction.h"
class SalomonObjective : public ObjectiveFunction{
public:
SalomonObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_SALOMONOBJECTIVE_H
