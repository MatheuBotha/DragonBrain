

#include "snapshot.h"





void Snapshot::setSwarm(Particle *swarm){
        this->swarm = swarm;
    }
    
Particle* Snapshot::getSwarm(){
        return this->swarm;
    }

void Snapshot::initialiseSwarm(){
    swarm = new Particle[swarmSize];
    for(int i=0; i<swarmSize; i++){
        swarm[i] = new Particle();
    }


}

int Snapshot::getSwarmSize(){
    return swarmSize;
}