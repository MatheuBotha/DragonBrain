/**
 * @class Manager
 *
 * The Manager class is one of the most integral components of the system. It contains, instantiates,
 * and mediates the communications between other system components: the Optimiser and Graphics Pipeline.
 * The Manager class will also make use of threads in order to facilitate concurrent optimisation operations.
 *
 *
 * @note Still in Progress
 *
 * @author Emilio Singh u14006512, Matheu Botha u14284104
 *
 * @version 0.1
 *
 * @date: 2016/07/11 12:16
 *
 * Contact: u14006512@tuks.co.za
 *
 * */

#ifndef OPT_MANAGER_H
#define OPT_MANAGER_H


#include <thread>
#include "GenOPT.h"
#include "SnapshotManager.h"

class Manager {

public:
    ///Destructor for manager objects
    virtual ~Manager();

    ///Constructor for the manager objects
    Manager();

    /*
     * This method creates a new snapshot manager class per request.
     * */
    SnapshotManager makeNewSnapShotMananger();

    /*
     * This method creates a new Graphics Pipeline.
     * The created graphics pipeline relates directly to a specific optimiser
     * and this pipeline provides graphical rendering services
     * */
    //GP makeGP(SettingsPackage setPackage);

    /*
     * This method creates a new Optimiser.
     * The created graphics pipeline relates directly to a specific graphical pipline
     * and this pipeline provides optimiser services.
     * */
    GenOPT makeOPT(SettingsPackage setPackage);
};


#endif //OPT_MANAGER_H
