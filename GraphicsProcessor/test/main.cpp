//
// Created by matheu on 2016/10/04.
//

#include "../GraphicsProcessor.h"
#include "../../OPT/GenOPT/src/SinObjective.h"
#include "../../OPT/GenOPT/src/SaddleObjective.h"
#include "../../OPT/GenOPT/src/AckleyObjective.h"
#include "../../OPT/GenOPT/src/WeierstrassObjective.h"
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
    double* boundaries = new double[4];
    boundaries[0] = 0.5;
    boundaries[1] = -0.5;
    boundaries[2] = 0.5;
    boundaries[3] = -0.5;
    pdsp.setBoundaries(boundaries);

    ObjectiveFunction* objective = new WeierstrassObjective(1, 0, 0, 0);

    GraphicsProcessor gp(pdsp);
    gp.setObjective(objective);
    gp.run();
}
