//
// Created by gerard on 2016/09/25.
//

#ifndef SWARMVIZ_ACKLEYOBJECTIVE_H
#define SWARMVIZ_ACKLEYOBJECTIVE_H

#include "ObjectiveFunction.h"

class AckleyObjective : public ObjectiveFunction{
public:
    AckleyObjective(){}

    double functionInput(double * parameters);
};


#endif //SWARMVIZ_ACKLEYOBJECTIVE_H
