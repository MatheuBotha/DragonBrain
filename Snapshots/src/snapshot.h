//
// Created by Gerard van wyk u14101263 on 2016-07-11.
//

#ifndef DRAGONBRAIN_SNAPSHOT_H
#define DRAGONBRAIN_SNAPSHOT_H

#include "../../OPT/src/Particle.h"

class Snapshot {
private:
    Particle* ParticleList;
    int** ParticleLinks;

public:
    Snapshot* next;


    Snapshot(Particle *ParticleList, int **ParticleLinks);
    void setParticleList(Particle *ParticleList);
    void setParticleLinks(int **ParticleLinks);
    Particle* getParticleList();
    int** getParticleLinks();
};

#endif //DRAGONBRAIN_SNAPSHOT_H
