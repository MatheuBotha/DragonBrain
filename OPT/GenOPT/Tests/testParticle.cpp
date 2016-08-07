//
// Created by Warmaster on 8/7/2016.
//

#include "gtest/gtest.h"
#include "../src/Particle.h"

TEST(construction,ParticleSuite)
{

    Particle * testParticle=new Particle();

    EXPECT_NE(testParticle,nullptr);
}

TEST(fitnessValue,ParticleSuite)
{
    Particle * testParticle=new Particle();

    testParticle->setFitnessValue(70);
    EXPECT_EQ(testParticle->getFitnessValue(),70);

}

TEST(nBestValue,ParticleSuite)
{
    Particle * testParticle=new Particle();

    testParticle->setNeighbourhoodBest(70);
    EXPECT_EQ(testParticle->getNeighbourhoodBest(),70);

}

TEST(nBestPosition,ParticleSuite)
{
    double * tmpPost=new double[2];
    tmpPost[0]=3.14;
    tmpPost[1]=4.15;

    Particle * testParticle=new Particle();

    testParticle->setNeighbourhoodBestPosition(tmpPost);
    EXPECT_EQ(testParticle->getNeighbourhoodBestPosition(),tmpPost);
    EXPECT_EQ(testParticle->getNeighbourhoodBestPosition()[0],tmpPost[0]);
    EXPECT_EQ(testParticle->getNeighbourhoodBestPosition()[1],tmpPost[1]);
}

TEST(particlePositions,ParticleSuite)
{
    double * tmpPost=new double[2];
    tmpPost[0]=3.14;
    tmpPost[1]=4.15;

    Particle * testParticle=new Particle();

    testParticle->setParticlePosition(tmpPost,2);
    EXPECT_EQ(testParticle->getPositionAtDimension(0),tmpPost[0]);
    EXPECT_EQ(testParticle->getPositionAtDimension(1),tmpPost[1]);
}

TEST(velocity,ParticleSuite)
{

    Particle * testParticle=new Particle();

    testParticle->setVelocity(20.5);
    EXPECT_EQ(testParticle->getVelocity(),20.5);
}

TEST(velocityByPtr,ParticleSuite)
{
    double *tmp=new double(20.5);
    Particle * testParticle=new Particle();

    testParticle->setVelocity(tmp);
    EXPECT_EQ(testParticle->getVelocity(),20.5);
}

TEST(svelocityByPtr,ParticleSuite)
{
    double * tmpPost=new double[2];
    tmpPost[0]=3.14;
    tmpPost[1]=4.15;

    Particle * testParticle=new Particle();

    testParticle->setPositionAtDimension(tmpPost[0],0);
    testParticle->setPositionAtDimension(tmpPost[1],1);
    EXPECT_EQ(testParticle->getPositionAtDimension(0),tmpPost[0]);
    EXPECT_EQ(testParticle->getPositionAtDimension(1),tmpPost[1]);
}