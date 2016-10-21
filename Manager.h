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
#include "OPT/GenOPT/src/SinObjective.h"
#include "OPT/GenOPT/src/SaddleObjective.h"
#include "OPT/GenOPT/src/HillClimber.h"
#include "OPT/GenOPT/src/PSO.h"
#include "OPT/GenOPT/src/CPSO.h"
#include "OPT/GenOPT/src/AlpineObjective.h"
#include "OPT/GenOPT/src/BealeObjective.h"
#include "OPT/GenOPT/src/BohachevskyObjective.h"
#include "OPT/GenOPT/src/EggHolderObjective.h"
#include "OPT/GenOPT/src/GoldSteinPriceObjective.h"
#include "OPT/GenOPT/src/GriewankObjective.h"
#include "OPT/GenOPT/src/Levy13Objective.h"
#include "OPT/GenOPT/src/Michalewicz.h"
#include "OPT/GenOPT/src/PathologicalObjective.h"
#include "OPT/GenOPT/src/QuadricObjective.h"
#include "OPT/GenOPT/src/QuarticObjective.h"
#include "OPT/GenOPT/src/RanaObjective.h"
#include "OPT/GenOPT/src/RastriginObjective.h"
#include "OPT/GenOPT/src/RosenbrockObjective.h"
#include "OPT/GenOPT/src/SalomonObjective.h"
#include "OPT/GenOPT/src/Schwefel22Objective.h"
#include "OPT/GenOPT/src/Schwefel26Objective.h"
#include "OPT/GenOPT/src/SixHumpCamelBackObjective.h"
#include "OPT/GenOPT/src/SkewRastriginObjective.h"
#include "OPT/GenOPT/src/SphericalObjective.h"
#include "OPT/GenOPT/src/StepObjective.h"
#include "OPT/GenOPT/src/WeierstrassObjective.h"
#include "OPT/GenOPT/src/ZakharovObjective.h"
#include "OPT/GenOPT/src/AckleyObjective.h"
#include "GraphicsProcessor/GraphicsProcessor.h"


class Manager {
private:
    SettingsPackage* setPkg;
    SnapshotManager** snapMan;
    ObjectiveFunction* objective;
    OPT_Process** optimizer;
    std::thread* GUI_Thread;
    std::thread** optThreads;
    GraphicsProcessor* graphicsProcessor;
    double *bounds;

    static void optimizeInstance(void *, int i);
public:

    ///Constructor for the manager objects
    Manager();

    ///Destructor for manager objects
    virtual ~Manager();

    void startGUI();
    void endGUI();

    void initializeOptimizer();
    void optimize();

    void initializeGraphicsProcessor();
    void visualize();
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

    void waitForOpts();
};


#endif //OPT_MANAGER_H
