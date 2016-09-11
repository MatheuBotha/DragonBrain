//
// Created by Warmaster on 9/11/2016.
//

#ifndef SIMPLEOPT_CPSO_H
#define SIMPLEOPT_CPSO_H

#include "PSO.h"
class CPSO: public PSO{
private:
public:
    CPSO();

    CPSO(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i);
};


#endif //SIMPLEOPT_CPSO_H
