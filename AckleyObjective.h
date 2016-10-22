//
// Created by gerard on 2016/10/03.
//

#ifndef OBJECTIVETEST_ACKLEYOBJECTIVE_H
#define OBJECTIVETEST_ACKLEYOBJECTIVE_H


#include "ObjectiveFunction.h"
class AckleyObjective : public ObjectiveFunction{
public:
AckleyObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=-32.768+x;
    defaultBounds[1]=32.768+x;
    defaultBounds[2]=-32.768+y;
    defaultBounds[3]=32.768+y;
}

double functionInput(double * parameters);

};

#endif //OBJECTIVETEST_ACKLEYOBJECTIVE_H
