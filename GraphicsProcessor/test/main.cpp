//
// Created by matheu on 2016/10/04.
//

#include "../GraphicsProcessor.h"
#include "../../OPT/GenOPT/src/SinObjective.h"
#include "../../OPT/GenOPT/src/SaddleObjective.h"
#include "../../OPT/GenOPT/src/AckleyObjective.h"
#include "../../SettingsPackage/src/problemdomainsettingspackage.h"

int main()
{

    ProblemDomainSettingsPackage pdsp;

    //set Objective Function
    std::string objective_function_name = "temp";
    pdsp.setObjectiveFunction(objective_function_name);

    //set dim
    pdsp.setDimensions(2);

    //set boundaries
    int* boundaries = new int[4];
    boundaries[0] = -10;
    boundaries[1] = 10;
    boundaries[2] = -10;
    boundaries[3] = 10;
    pdsp.setBoundaries(boundaries);

    ObjectiveFunction* objective = new AckleyObjective();

    GraphicsProcessor gp(pdsp);
    gp.setObjective(objective);
    gp.run();
}
