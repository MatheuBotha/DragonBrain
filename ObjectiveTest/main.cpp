#include <iostream>
#include "ObjectiveFunction.h"
#include "SinObjective.h"
#include "SaddleObjective.h"
#include "AlpineObjective.h"
#include "BealeObjective.h"
#include "BohachevskyObjective.h"
#include "EggHolderObjective.h"
#include "GoldSteinPriceObjective.h"
#include "GriewankObjective.h"
#include "Levy13Objective.h"
#include "Michalewicz.h"
#include "PathologicalObjective.h"
#include "QuadricObjective.h"
#include "QuarticObjective.h"
#include "RanaObjective.h"
#include "RastriginObjective.h"
#include "RosenbrockObjective.h"
#include "SalomonObjective.h"
#include "Schwefel22Objective.h"
#include "Schwefel26Objective.h"
#include "SixHumpCamelBackObjective.h"
#include "SkewRastriginObjective.h"
#include "SphericalObjective.h"
#include "StepObjective.h"
#include "WeierstrassObjective.h"
#include "ZakharovObjective.h"

int main() {
    std::cout << "Start\n\n";

    ObjectiveFunction *objective = new ZakharovObjective(1,1,1,1);
    //std::cout << "alpha\n";
    double * parameters = new double[2];

    parameters[0]=0.0;
    parameters[1]=0.0;
    std::cout << objective->functionInput(parameters) << std::endl;

    parameters[0]=1;
    parameters[1]=2;
    std::cout << objective->functionInput(parameters) << std::endl;

    parameters[0]=-10;
    parameters[1]=-10;
    std::cout << objective->functionInput(parameters) << std::endl;

    parameters[0]=1;
    parameters[1]=0;
    std::cout << objective->functionInput(parameters) << std::endl;

    parameters[0]=1;
    parameters[1]=DBL_MAX;
    std::cout << objective->functionInput(parameters) << std::endl;

    std::cout << "\nEnd" << std::endl;
    return 0;
}