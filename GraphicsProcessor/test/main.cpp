//
// Created by matheu on 2016/10/04.
//

#include "../GraphicsProcessor.h"
#include "../../OPT/GenOPT/src/ObjectiveFunction.h"
#include "../../OPT/GenOPT/src/SaddleObjective.h"

int main()
{
    ObjectiveFunction* objective = new SaddleObjective(0,0,0);

    GraphicsProcessor gp(objective);
    gp.run();
}
