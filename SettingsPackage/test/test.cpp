//
// Created by rento on 2016/07/21.
//


#include "gtest/gtest.h"
#include "../src/settingspackage.h"


TEST(basic_check, test_GeneralPackage) {
    SettingsPackage setPkg;
    setPkg.generateSettingsGeneral(20, 1);
    EXPECT_EQ(20, setPkg.getSwarmSize());
}


TEST(basic_check, test_GraphicsPackage) {
    SettingsPackage setPkg;
    setPkg.generateSettingsGraphics("ResolutionString",true, false);
    GraphicsSettingsPackage* gPkg = setPkg.getGraphicsSettingsPackage();

    EXPECT_TRUE(gPkg->getShowLinks());
    EXPECT_FALSE(gPkg->getShowPath());
}


TEST(basic_check, test_OptimizerPackage) {
    SettingsPackage setPkg;
    setPkg.generateSettingsOptimizer("HillClimber", "HillClimber", "HillClimber", "HillClimber",  21, 5.3, 2.6, 1.1, 1.0, 50.0, 15, 5, 2);

    OptimizerSettingsPackage* oPkg = setPkg.getOptimizerSettingsPackage();

    EXPECT_EQ("HillClimber", oPkg->getAlgorithm(1));
    EXPECT_EQ(21, oPkg->getMaxIterations());
    EXPECT_EQ(1.1, oPkg->getInertiaWeight());
    EXPECT_EQ(50.0, oPkg->getMaxVelocity());
    EXPECT_EQ(15, oPkg->getSuccessCount());
    EXPECT_EQ(5, oPkg->getFailCount());
    EXPECT_EQ(2, oPkg->getNeighbourhoodSize());

}


TEST(basic_check, test_DomainPackage) {
    SettingsPackage setPkg;
    setPkg.generateSettingsDomain("TempObjFun",2,1,2,3,4,0.5,-0.5,7.0,0);
    ProblemDomainSettingsPackage* dPkg = setPkg.getProblemDomainSettingsPackage();
    double boundCheck[4];
    double transCheck[3];
    dPkg->getBoundaries(boundCheck);
    dPkg->getTransformations(transCheck);

    EXPECT_EQ(2,dPkg->getDimensions());
    EXPECT_EQ(1, boundCheck[0]);
    EXPECT_EQ(2, boundCheck[1]);
    EXPECT_EQ(3, boundCheck[2]);
    EXPECT_EQ(4, boundCheck[3]);
    EXPECT_EQ(0.5, transCheck[0]);
    EXPECT_NE(0.5, transCheck[1]);
    EXPECT_EQ(-0.5, transCheck[1]);
    EXPECT_EQ(7.0, transCheck[2]);
}

