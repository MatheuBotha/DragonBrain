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

TEST(swarm_NMatrix_creationTest,package_Test_Suite)
{
    int size=5;
    GenOPT * test=new GenOPT();
    test->setSwarmSize(size);
    test->setNeighbourhoodSize(2);
    test->generateSwarmNMatrix();

    EXPECT_NE(test->getNeighbourhoodMatrix(), nullptr);

    for (int i=0;i<size;i++)
    {
     EXPECT_EQ(test->getNeighbourhoodMatrix()[i][i],INT_MAX);
    }
}

TEST(swarm_NMatrix_valuesTest,package_Test_Suite)
{
    int size=10;
    GenOPT * test=new GenOPT();

    test->setSwarmSize(size);
    test->setNeighbourhoodSize(2);
    test->generateSwarmNMatrix();

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if (i!=j)
            {
                EXPECT_NE(test->getNeighbourhoodMatrix()[i][j],INT_MAX);

            }
        }
    }
}

