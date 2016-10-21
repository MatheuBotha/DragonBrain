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
    Particle* gbest;
    int swarmSize;
    int dimensions;
public:
    Snapshot(int swarmSize, int dim, double bounds[4]){
        next = nullptr;
        this->swarmSize = swarmSize;
        dimensions = dim;
        initialiseSwarm(bounds);
    }
    Snapshot(Particle** swarm, int swarmSize, int dim){ //Do not use this constructor.
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
        } delete [] swarm;
    }
    Snapshot* next;

    void setGBest(Particle* p) { gbest = p; };
    Particle* getGBest() { return gbest; }
    void setSwarm(Particle **swarm);
    Particle** getSwarm();
    void initialiseSwarm(double bounds[4]);
    int getSwarmSize();
};

#endif //DRAGONBRAIN_SNAPSHOT_H
