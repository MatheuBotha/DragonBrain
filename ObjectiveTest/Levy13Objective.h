//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_LEVY13OBJECTIVE_H
#define OBJECTIVETEST_LEVY13OBJECTIVE_H

#include "ObjectiveFunction.h"
class Levy13Objective : public ObjectiveFunction{
public:
Levy13Objective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_LEVY13OBJECTIVE_H
