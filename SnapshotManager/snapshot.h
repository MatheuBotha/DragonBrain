//
// Created by Gerard van wyk u14101263 on 2016-07-11.
//

#ifndef DRAGONBRAIN_SNAPSHOT_H
#define DRAGONBRAIN_SNAPSHOT_H

#include <cstring>
#include "../OPT/GenOPT/src/Particle.h"

class Snapshot {
private:
    Particle** swarm;
    int swarmSize;
    int dimensions;

public:
    Snapshot(int swarmSize, int dim){
        next = nullptr;
        this->swarmSize = swarmSize;
        dimensions = dim;
        initialiseSwarm();
    }
    Snapshot(Particle** swarm, int swarmSize, int dim){
        next = nullptr;
        dimensions = dim;
        this->swarm = swarm;
    }

    Snapshot(Snapshot* other){
        swarmSize = other->swarmSize;

        swarm = new Particle*[swarmSize];
        next = other->next;
        dimensions = other->dimensions;
        for(int i=0; i<swarmSize; i++){
            swarm[i] = new Particle(other->swarm[i]);
        }
    }

    ~Snapshot()
    {
        for(int i=0; i<swarmSize; ++i)
        {
            delete swarm[i];
        }
    }
    Snapshot* next;
    void setSwarm(Particle **swarm);
    Particle** getSwarm();
    void initialiseSwarm();
    int getSwarmSize();
};

#endif //DRAGONBRAIN_SNAPSHOT_H
