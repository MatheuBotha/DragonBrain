//
// Created by matheu on 10/6/16.
//

#ifndef SWARMVIZ_PARTICLESYSTEM_H
#define SWARMVIZ_PARTICLESYSTEM_H


#include "../../SnapshotManager/SnapshotManager.h"

class ParticleSystem {
public:
    ParticleSystem(SnapshotManager* snapshotManager);
    ~ParticleSystem();
    void draw();
    void analyzeSnapshotManager();
protected:
private:
    SnapshotManager* snapshotManager;
};


#endif //SWARMVIZ_PARTICLESYSTEM_H
