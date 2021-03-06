//
// Created by lemmus on 2016/09/09.
//


#include <iostream>
#include "ObjectiveFunction.h"
#include "SinObjective.h"
#include "RandObjective.h"
#include "../../../SnapshotManager/SnapshotManager.h"
#include "SaddleObjective.h"
#include "OPT_Process.h"
#include "HillClimber.h"

int main() {
    std::cout << "PROGRAM START\n\n";

    int maxIteration = 100;
    int swarmSize = 15;
    ObjectiveFunction *obj1 = new SinObjective();
    SnapshotManager *snap1 = new SnapshotManager(maxIteration, swarmSize);
    OPT_Process *opt1 = new HillClimber(obj1, snap1, true);

    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
    }

    /*double *parameters = new double[2];
    parameters[0] = 1.9;
    parameters[1] = 2.1;

    cout << obj1->functionInput(parameters);*/

    std::cout << "\n\nPROGRAM END";
    return 0;
}