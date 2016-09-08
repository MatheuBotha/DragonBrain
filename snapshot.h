//
// Created by Gerard van wyk u14101263 on 2016-07-11.
//

#ifndef DRAGONBRAIN_SNAPSHOT_H
#define DRAGONBRAIN_SNAPSHOT_H

#include <cstring>
#include "Particle.h"

class Snapshot {
private:
    Particle** swarm;
    int swarmSize;

public:
    Snapshot(int swarmSize){
        next = nullptr;
        this->swarmSize = swarmSize;
        initialiseSwarm();
    }
    Snapshot(Particle** swarm, int swarmSize){
        next = nullptr;
        this->swarm = swarm;
    }

    Snapshot(Snapshot* other){
        swarmSize = other->swarmSize;

        swarm = new Particle*[swarmSize];

        for(int i=0; i<swarmSize; i++){
            swarm[i] = new Particle(other->swarm[i]);
        }
    }
    Snapshot* next;
    void setSwarm(Particle **swarm);
    Particle** getSwarm();
    void initialiseSwarm();
    int getSwarmSize();
};

#endif //DRAGONBRAIN_SNAPSHOT_H
