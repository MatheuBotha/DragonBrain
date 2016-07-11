
// Created by  on 2016-07-11.
/**
 * @class Snapshot
 *
 * The snapshot is -as the name suggests- a snapshot of the particle positions of the optimiser in the current epoch.
 * A snapshot consists of a 1D array of Particles and a 2D array of integers describing the connection topology of the particles.
 * Snapshots are stored in a queue in the snapshot manager, and are created the generic optimiser class (OPT).
 * The sequence of snapshots has multiple uses, primarily to be used the graphics system to visualize the locations of
 * the particles.
 *
 * @note Still in Progress
 *
 * @author Gerard van wyk u14101263
 *
 * @version 0.1
 *
 * @date: 2016/07/11 16:20
 *
 * Contact: u14101263@tuks.co.za
 *
 * */
#include "Snapshot.h"

class Snapshot{

private:
    Particle* ParticleList;
    int** ParticleLinks;

public:
    Snapshot(Particle* ParticleList, int** ParticleLinks){
        this->ParticleList = ParticleList;
        this->ParticleLinks = ParticleLinks;
    }

};
