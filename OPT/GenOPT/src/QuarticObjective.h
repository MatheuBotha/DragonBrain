//
// Created by gerard on 2016/10/02.
//

#ifndef OBJECTIVETEST_QUARTICOBJECTIVE_H
#define OBJECTIVETEST_QUARTICOBJECTIVE_H

#include "ObjectiveFunction.h"
class QuarticObjective : public ObjectiveFunction{
public:
QuarticObjective(double s, double x, double y, double v): ObjectiveFunction(s, x, y, v){
    defaultBounds[0]=-1.28;
    defaultBounds[1]=1.28;
    defaultBounds[2]=-1.28;
    defaultBounds[3]=1.28;
}

double functionInput(double * parameters);
};


#endif //OBJECTIVETEST_QUARTICOBJECTIVE_H
