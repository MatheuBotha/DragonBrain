//
// Created by lemmus on 2016/09/09.
//

#include <iostream>
#include "Manager.h"

using namespace std;

int main()
{
    Manager* swarmMan = new Manager();
    swarmMan->startGUI();
    SettingsPackage* setts = swarmMan->getSettingsPackage();
    //still needs an alternative for the situation in which a user has not clicked a button
    while(setts->isLocked()) {}

    swarmMan->generateSnapshotManager();
    swarmMan->initializeOptimizer();
    swarmMan->optimize();
/*    ObjectiveFunction *obj1 = new SinObjective();
    OPT_Process *opt1 = new HillClimber(obj1, swarmMan->getSnapshotManager(), true);

    for(int i=0;i<setts->getOptimizerSettingsPackage()->getMaxIterations();i++){
        opt1->iterate();
    }
  */
    swarmMan->endGUI();
    delete swarmMan;
    return 0;
}