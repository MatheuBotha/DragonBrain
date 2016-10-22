//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_MICHALEWICZ_H
#define OBJECTIVETEST_MICHALEWICZ_H


#include "ObjectiveFunction.h"
class MichalewiczObjective : public ObjectiveFunction{
public:
MichalewiczObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=0.0+x;
    defaultBounds[1]=M_PI+x;
    defaultBounds[2]=0.0+y;
    defaultBounds[3]=M_PI+y;
}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_MICHALEWICZ_H
