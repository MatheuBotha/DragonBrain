//
// Created by gerard on 2016/10/03.
//

#ifndef OBJECTIVETEST_ZAKHAROVOBJECTIVE_H
#define OBJECTIVETEST_ZAKHAROVOBJECTIVE_H


#include "ObjectiveFunction.h"
class ZakharovObjective : public ObjectiveFunction{
public:
ZakharovObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_ZAKHAROVOBJECTIVE_H
