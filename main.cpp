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

    //this one lets the user first chose to close application (without it not finishing execution)
    while (setts->isLocked()) {}

    while(!setts->readyToClose()) {

        setts->lock(true);

        swarmMan->generateSnapshotManager();
        swarmMan->initializeOptimizer();
        swarmMan->optimize();


        //swarmMan->getGraphicsProcessor()->run();
        swarmMan->waitForOpts();
        swarmMan->initializeGraphicsProcessor();
        swarmMan->visualize();

        swarmMan->cleanMemory();

        setts->readyNext(true);

        while (setts->isLocked()) {}

    }
    swarmMan->endGUI();
    delete swarmMan;
    return 0;
}
