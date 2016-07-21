//
// Created by rento on 2016/07/21.
//


#include "gtest/gtest.h"
#include "../../src/settingspackage.h"


TEST(basic_check, test_GeneralPackage) {
    SettingsPackage setPkg;
    setPkg.generateSettingsGeneral(20);
    EXPECT_EQ(20, setPkg.getSwarmSize());
}


TEST(basic_check, test_GraphicsPackage) {
    SettingsPackage setPkg;
    setPkg.generateSettingsGraphics("ResolutionString", 15, true, false, 9);
    GraphicsSettingsPackage* gPkg = setPkg.getGraphicsSettingsPackage();

    EXPECT_EQ(15, gPkg->getRenderSpeed());
    EXPECT_TRUE(gPkg->getShowLinks());
    EXPECT_FALSE(gPkg->getShowPath());
    EXPECT_EQ(9, gPkg->getMaxRam());
}


TEST(basic_check, test_OptimizerPackage) {
    SettingsPackage setPkg;
    setPkg.generateSettingsOptimizer("TempString", 0.5, 7.9, 120000.4123, 12, 21);

    OptimizerSettingsPackage* oPkg = setPkg.getOptimizerSettingsPackage();

    EXPECT_EQ("TempString", oPkg->getParticlePlacementString());
    EXPECT_EQ(0.5, oPkg->getInertiaWeight());
    EXPECT_EQ(7.9, oPkg->getCognitiveCoefficient());
    EXPECT_EQ(120000.4123, oPkg->getSocialCoefficient());
    EXPECT_EQ(12, oPkg->getMaxIterations());
    EXPECT_EQ(21, oPkg->getCutoffAcc());

}


TEST(basic_check, test_DomainPackage) {
    SettingsPackage setPkg;
    setPkg.generateSettingsDomain("TempObjFun",2,1,2,3,4,0.5,-0.5,7.0);
    ProblemDomainSettingsPackage* dPkg = setPkg.getProblemDomainSettingsPackage();
    int boundCheck[4];
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