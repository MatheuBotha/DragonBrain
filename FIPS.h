//
// Created by Warmaster on 9/11/2016.
//

#ifndef SIMPLEOPT_FIPS_H
#define SIMPLEOPT_FIPS_H

#include "PSO.h"
class FIPS: public PSO {

private:
public:
    FIPS();

    FIPS(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i);
};


#endif //SIMPLEOPT_FIPS_H
