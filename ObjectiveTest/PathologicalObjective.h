//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_PATHOLOGICALOBJECTIVE_H
#define OBJECTIVETEST_PATHOLOGICALOBJECTIVE_H


#include "ObjectiveFunction.h"
class PathologicalObjective : public ObjectiveFunction{
public:
PathologicalObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){

}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_PATHOLOGICALOBJECTIVE_H
