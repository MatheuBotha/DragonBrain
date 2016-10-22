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
#include "../PSO.h"
#include "../GCPSO.h"
#include "../AckleyObjective.h"
#include "../FIPS.h"
#include "../CPSO.h"

TEST(basic_check, test_SaddleHill) {

    double s[2]={0,0};
    double bounds[4]={-10,10,-10,10};
    int maxIteration = 100;
    int swarmSize = 100;
    ObjectiveFunction *obj1 = new AckleyObjective(-10,10,-10,10);
    SnapshotManager *snap1 = new SnapshotManager(maxIteration, swarmSize,2,bounds);
    OPT_Process *opt1 = new HillClimber(obj1, snap1, false,bounds);
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

    double s[2]={0,0};
    double bounds[4]={-10,10,-10,10};
    int maxIteration = 20;
    int swarmSize = 10;
    ObjectiveFunction *obj1 = new AckleyObjective(1,0,0,0);
    SnapshotManager *snap1 = new SnapshotManager(maxIteration, swarmSize,2,bounds);
    OPT_Process *opt1 = new HillClimber(obj1, snap1, true,bounds);
    double best = -1000;
    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
        best = opt1->getBestSolution()->getPersonalBest();
        cout<<"GBEST: "<<best<<endl;
        cout<<"BASELINE: "<<obj1->functionInput(s)<<endl;
    }
    delete obj1;
    delete snap1;
    delete opt1;

}



TEST(basic_check, test_OptimalSin) {
    /*
    double bounds[4]={-10,10,-10,10};
    int maxIteration = 1000;
    int swarmSize = 1000;
    ObjectiveFunction *obj1 = new SinObjective();
    SnapshotManager *snap1 = new SnapshotManager(maxIteration, swarmSize,2,bounds);
    OPT_Process *opt1 = new HillClimber(obj1, snap1, false,bounds);
    float best = -1000;
    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
        best = opt1->getBestSolution()->getPersonalBest();
    }
    EXPECT_EQ(2, best);
    delete obj1;
    delete snap1;
    delete opt1;
    */
}


TEST(pso_check,test_sin)
{
    double s[2]={0.5,0.5};
    double bounds[4]={-10,10,-10,10};
    int maxIteration = 20;
    int swarmSize = 10;
    ObjectiveFunction *obj1 = new AckleyObjective(1,0,0,0);
    SnapshotManager *snap1 = new SnapshotManager(maxIteration, swarmSize,2,bounds);
    OPT_Process *opt1 = new PSO(obj1, snap1, true,bounds,0.2,1.2);
    double best = -1000;
    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
        best = opt1->getIdeal()->getPersonalBest();
        cout<<"GBEST: "<<best<<endl;
        cout<<"BASELINE: "<<obj1->functionInput(s)<<endl;

    }
   EXPECT_GT(best,-1000);
    delete obj1;
    delete snap1;
    delete opt1;

}

TEST(CPSO_check,test_sin)
{
    /*
    double bounds[4]={-10,10,-10,10};
    int maxIteration = 20;
    int swarmSize = 1000;
    ObjectiveFunction *obj1 = new SinObjective();
    SnapshotManager *snap1 = new SnapshotManager(maxIteration, swarmSize,2);
    OPT_Process *opt1 = new CPSO(obj1, snap1, false,0.2,50,bounds);
    float best = -1000;
    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
        best = opt1->getBestSolution()->getPersonalBest();
    }
    EXPECT_GT(best,-1000);
    delete obj1;
    delete snap1;
    delete opt1;
     */
}

TEST(fips_check,test_sin)
{
    /*
    double bounds[4]={-100,100,-100,100};
    int maxIteration = 300;
    int swarmSize = 300;
    ObjectiveFunction *obj1 = new SinObjective();
    SnapshotManager *snap1 = new SnapshotManager(maxIteration, swarmSize,2,bounds);
    OPT_Process *opt1 = new FIPS(obj1, snap1, false,5,1.2,bounds,3.5,3.5);
    double best = -1000;
    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
        best = opt1->getBestSolution()->getPersonalBest();
    }
    EXPECT_GT(best,-1000);
    delete obj1;
    delete snap1;
    delete opt1;
    */
}
TEST(GCPSO_check,test_sin)
{

    double bounds[4]={-10,10,-10,10};
    double bounds2[2]={-10,10};
    int maxIteration = 10;
    int swarmSize = 10;
    ObjectiveFunction *obj1 = new AckleyObjective(-10,10,0,0);
    SnapshotManager *snap1 = new SnapshotManager(maxIteration, swarmSize,1,bounds2);
    OPT_Process *opt1 = new GCPSO(obj1, snap1, true,bounds2,15,5,0.2,0.5,0.4);
    double best = -1000;
    for(int i=0;i<maxIteration;i++){
        opt1->iterate();
        best = opt1->getBestSolution()->getPersonalBest();
    }
    EXPECT_GT(best,-1000);
    delete obj1;
    delete snap1;
    delete opt1;
}

/*



*/