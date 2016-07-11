//
// Created by Gerard van wyk u14101263 on 2016-07-11.
//

#ifndef DRAGONBRAIN_SNAPSHOT_H
#define DRAGONBRAIN_SNAPSHOT_H

class Snapshot {
private:

public:
    Snapshot(Particle *ParticleList, int **ParticleLinks);
    void setParticleList(Particle *ParticleList);
    void setParticleLinks(int **ParticleLinks);
    Particle* getParticleList();
    int** getParticleLinks();
};

#endif //DRAGONBRAIN_SNAPSHOT_H
