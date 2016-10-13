//
// Created by matheu on 2016/10/04.
//

#include "../GraphicsProcessor.h"
#include "../../OPT/GenOPT/src/SinObjective.h"
#include "../../OPT/GenOPT/src/SaddleObjective.h"
#include "../../OPT/GenOPT/src/AckleyObjective.h"
#include "../../OPT/GenOPT/src/WeierstrassObjective.h"
#include "../../OPT/GenOPT/src/QuadricObjective.h"
#include "../../SettingsPackage/src/problemdomainsettingspackage.h"
#include "../../SnapshotManager/SnapshotManager.h"
#include "../../OPT/GenOPT/src/HillClimber.h"
#include "../../OPT/GenOPT/src/ElitistHillClimber.h"

int main()
{
    //Create Problem Domain Settings Package
    ProblemDomainSettingsPackage pdsp;

    //set Objective Function
    std::string objective_function_name = "temp";
    pdsp.setObjectiveFunction(objective_function_name);

    //set dim
    pdsp.setDimensions(2);

    //set boundaries
    double* boundaries = new double[4];
    boundaries[0] = -1;
    boundaries[1] = 1;
    boundaries[2] = -1;
    boundaries[3] = 1;
    pdsp.setBoundaries(boundaries);


    ObjectiveFunction* objective = new QuadricObjective(1, 0, 0, 0);
    //GGGGGGGG
    int maxIteration = 2;
    int swarmSize = 3;
    int dimension = 2;
    SnapshotManager *snapshotManager = new SnapshotManager(maxIteration, swarmSize, dimension, boundaries);

    //******************************************************************************************************************
    //  Here Please
    //******************************************************************************************************************

    //******************************************************************************************************************
    //  End: Here Please
    //******************************************************************************************************************

    OPT_Process *opt1 = new HillClimber(objective, snapshotManager, false, boundaries);

    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
    }

    //GGGGGGGG
    GraphicsProcessor gp(pdsp, snapshotManager, 1280, 720);
    gp.setObjective(objective);
    gp.run();
}
