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
#include "SettingsPackage/src/settingspackage.h"
#include "GUI/Interface.h"
#include "SnapshotManager/SnapshotManager.h"
#include "Objectives/SinObjective.h"
#include "Objectives/SaddleObjective.h"
#include "OPT/src/HillClimber.h"
#include "OPT/src/PSO.h"
#include "OPT/src/CPSO.h"
#include "OPT/src/FIPS.h"
#include "Objectives/AlpineObjective.h"
#include "Objectives/BealeObjective.h"
#include "Objectives/BohachevskyObjective.h"
#include "Objectives/EggHolderObjective.h"
#include "Objectives/GoldSteinPriceObjective.h"
#include "Objectives/GriewankObjective.h"
#include "Objectives/Levy13Objective.h"
#include "Objectives/Michalewicz.h"
#include "Objectives/PathologicalObjective.h"
#include "Objectives/QuadricObjective.h"
#include "Objectives/QuarticObjective.h"
#include "Objectives/RanaObjective.h"
#include "Objectives/RastriginObjective.h"
#include "Objectives/RosenbrockObjective.h"
#include "Objectives/SalomonObjective.h"
#include "Objectives/Schwefel22Objective.h"
#include "Objectives/Schwefel26Objective.h"
#include "Objectives/SixHumpCamelBackObjective.h"
#include "Objectives/SkewRastriginObjective.h"
#include "Objectives/SphericalObjective.h"
#include "Objectives/StepObjective.h"
#include "Objectives/WeierstrassObjective.h"
#include "Objectives/ZakharovObjective.h"
#include "Objectives/AckleyObjective.h"


class Manager {
private:
    SettingsPackage* setPkg;
    SnapshotManager* snapMan;
    ObjectiveFunction* objective;
    OPT_Process* optimizer;
    std::thread* GUI_Thread;
public:

    ///Constructor for the manager objects
    Manager();

    ///Destructor for manager objects
    virtual ~Manager();

    void startGUI();
    void endGUI();

    void initializeOptimizer();
    void optimize();
    /*
     * This method creates a new snapshot manager class per request.
     * */
    void generateSnapshotManager();
    SnapshotManager* getSnapshotManager();

    bool stillRunning() { return GUI_Thread->joinable(); }
    SettingsPackage* getSettingsPackage();
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
};


#endif //OPT_MANAGER_H
