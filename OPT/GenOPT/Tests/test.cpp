//
// Created by rento on 2016/07/21.
//


#include "gtest/gtest.h"
#include "../src/GenOPT.h"

TEST(basic_Constructor_Test_GenOPT_1,package_Test_Suite)
{
    GenOPT * test=new GenOPT();

    EXPECT_NE(test,nullptr);
}

TEST(basic_Constructor_Test_Particle_2,package_Test_Suite)
{
    double * testArray=new double[2];
    testArray[0]=1;
    testArray[1]=2;
    Particle * test=new Particle();
    test->setFitnessValue(100);
    test->setNeighbourhoodBest(100);
    test->setPositionArray(testArray);

    EXPECT_NE(test, nullptr);

    EXPECT_EQ(test->getFitnessValue(),100);
    EXPECT_EQ(test->getNeighbourhoodBest(),100);
    EXPECT_NE(test->getPositionArray(), nullptr);
    EXPECT_EQ(test->getPositionAtDimension(0),1.0);
    EXPECT_EQ(test->getPositionAtDimension(1),2.0);

}

TEST(swarm_NMatrix_test,package_Test_Suite)
{
    GenOPT * test=new GenOPT();
    test->setSwarmSize(5);
    test->generateSwarmNMatrix();

    EXPECT_NE(test->getNeighbourhoodMatrix(), nullptr);
    EXPECT_NE(test->getNeighbourhoodMatrix()[0][0],-1);
    EXPECT_EQ(test->getNeighbourhoodMatrix()[0][0],INT_MAX);
    EXPECT_NE(test->getNeighbourhoodMatrix()[0][1],INT_MAX);
    EXPECT_EQ(test->getNeighbourhoodMatrix()[1][1],INT_MAX);
    EXPECT_EQ(test->getNeighbourhoodMatrix()[2][2],INT_MAX);
    EXPECT_EQ(test->getNeighbourhoodMatrix()[3][3],INT_MAX);
    EXPECT_EQ(test->getNeighbourhoodMatrix()[4][4],INT_MAX);
}

