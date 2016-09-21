//
// Created by E.Singh on 9/11/2016.
//

#ifndef SIMPLEOPT_GCPSO_H
#define SIMPLEOPT_GCPSO_H

#include "PSO.h"
class GCPSO: public PSO {

private:
public:
    GCPSO();

    GCPSO(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i);
};


#endif //SIMPLEOPT_GCPSO_H
