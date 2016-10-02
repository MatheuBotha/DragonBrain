//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_RANAOBJECTIVE_H
#define OBJECTIVETEST_RANAOBJECTIVE_H


#include "ObjectiveFunction.h"
class RanaObjective : public ObjectiveFunction{
public:
RanaObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_RANAOBJECTIVE_H
