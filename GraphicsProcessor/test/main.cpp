//
// Created by matheu on 2016/10/04.
//

#include "../GraphicsProcessor.h"
#include "../../OPT/GenOPT/src/SinObjective.h"
#include "../../OPT/GenOPT/src/SaddleObjective.h"
#include "../../OPT/GenOPT/src/AckleyObjective.h"
#include "../../OPT/GenOPT/src/WeierstrassObjective.h"
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
    boundaries[0] = -10;
    boundaries[1] = 10;
    boundaries[2] = -10;
    boundaries[3] = 10;
    pdsp.setBoundaries(boundaries);


    ObjectiveFunction* objective = new SaddleObjective(1, 0, 0, 0);
    //GGGGGGGG
    int maxIteration = 2;
    int swarmSize = 3;
    int dimension = 2;
    SnapshotManager *snapshotManager = new SnapshotManager(maxIteration, swarmSize, dimension, boundaries);
    OPT_Process *opt1 = new ElitistHillClimber(objective, snapshotManager, false, boundaries);

    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
    }

    //GGGGGGGG
    GraphicsProcessor gp(pdsp, snapshotManager, 800, 600);
    gp.setObjective(objective);
    gp.run();
}
