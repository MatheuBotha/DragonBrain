//
// Created by E.Singh on 9/11/2016.
//

#include "FIPS.h"

FIPS::FIPS(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i) : PSO(pFunction, pManager, i) {

}

/**The Fully Informed PSO algorithm is predicated on increasing the scope of a particle's knowledge of the
 * problem by aggregating the best's of k nearest neighbours when considering velocity updates.
 *
 * */
void FIPS::updateVelocity(Particle *particle) {


}
