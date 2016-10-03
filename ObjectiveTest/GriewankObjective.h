//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_GRIEWANKOBJECTIVE_H
#define OBJECTIVETEST_GRIEWANKOBJECTIVE_H


#include "ObjectiveFunction.h"

class GriewankObjective : public ObjectiveFunction{
public:
GriewankObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=-600.0;
    defaultBounds[1]=600.0;
    defaultBounds[2]=-600.0;
    defaultBounds[3]=600.0;
}

double functionInput(double * parameters);
};



#endif //OBJECTIVETEST_GRIEWANKOBJECTIVE_H
