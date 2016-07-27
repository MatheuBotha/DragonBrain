

#include "snapshot.h"

Snapshot::Snapshot(Particle* ParticleList, int** ParticleLinks){
        this->ParticleList = ParticleList;
        this->ParticleLinks = ParticleLinks;
    }

void Snapshot::setParticleList(Particle *ParticleList){
        this->ParticleList = ParticleList;
    }
    
void Snapshot::setParticleLinks(int **ParticleLinks){
        this->ParticleLinks = ParticleLinks;
    }
    
Particle* Snapshot::getParticleList(){
        return this->ParticleList;
    }
    
int** Snapshot::getParticleLinks(){
        return this->ParticleLinks;
    }

