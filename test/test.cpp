//
// Created by rento on 2016/07/21.
//


#include "gtest/gtest.h"
#include "../ObjectiveFunction.h"
#include "../SinObjective.h"
#include "../RandObjective.h"
#include "../SnapshotManager.h"
#include "../OPT_Process.h"
#include "../HillClimber.h"
#include "../SaddleObjective.h"


TEST(basic_check, test_SaddleHill) {
    int maxIteration = 100;
    int swarmSize = 100;
    ObjectiveFunction *obj1 = new SaddleObjective();
    SnapshotManager *snap1 = new SnapshotManager(maxIteration, swarmSize);
    OPT_Process *opt1 = new HillClimber(obj1, snap1, false);
    double best = -1000;
    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
        EXPECT_LE(best, opt1->getBestSolution()->getPersonalBest());
        best = opt1->getBestSolution()->getPersonalBest();
    }
    delete obj1;
    delete snap1;
    delete opt1;
}

TEST(basic_check, test_SinHill) {
    int maxIteration = 100;
    int swarmSize = 100;
    ObjectiveFunction *obj1 = new SinObjective();
    SnapshotManager *snap1 = new SnapshotManager(maxIteration, swarmSize);
    OPT_Process *opt1 = new HillClimber(obj1, snap1, false);
    double best = -1000;
    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
        EXPECT_LE(best, opt1->getBestSolution()->getPersonalBest());
        best = opt1->getBestSolution()->getPersonalBest();
    }
    delete obj1;
    delete snap1;
    delete opt1;
}



TEST(basic_check, test_OptimalSin) {
    int maxIteration = 1000;
    int swarmSize = 1000;
    ObjectiveFunction *obj1 = new SinObjective();
    SnapshotManager *snap1 = new SnapshotManager(maxIteration, swarmSize);
    OPT_Process *opt1 = new HillClimber(obj1, snap1, false);
    float best = -1000;
    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
        best = opt1->getBestSolution()->getPersonalBest();
    }
    EXPECT_EQ(2, best);
    delete obj1;
    delete snap1;
    delete opt1;
}
