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

    //this one lets the user first chose to close application (without it not finishing execution)
    while (setts->isLocked()) {}

    while(!setts->readyToClose()) {
        while (setts->isLocked()) {}

        swarmMan->generateSnapshotManager();
        swarmMan->initializeOptimizer();
        swarmMan->optimize();

        //swarmMan->getGraphicsProcessor()->run();
        swarmMan->waitForOpts();
        setts->readyNext(true);
        std::cout << "APPLES" << std::endl;
        setts->lock(true);
    }
    swarmMan->endGUI();
    delete swarmMan;
    return 0;
}