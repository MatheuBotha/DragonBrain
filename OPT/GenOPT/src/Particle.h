/**
 * @class Particle
 *
 * This class is meant to serve as the specification for the
 * particle component of the Swarm-based Optimisation Program.
 * Particles are data objects that represent candidate solutions
 * and the Particle class describes how this representation will be modelled.
 *
 * @note Still in Progress
 *
 * @authors
 * Emilio Singh u14006512
 * Gerard van wyk u14101263
 *
 * @version 0.1
 *
 * @date: 2016/07/01 12:16
 *
 * Contact: u14006512@tuks.co.za
 *
 * */
#ifndef OPT_PARTICLE_H
#define OPT_PARTICLE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <float.h>
#include <vector>
using namespace std;

class Particle {
private:

    double positionArray[2]; ///> the array of double values holding the positions per dimension of the particle
    double personalBestPosition[2]; ///>the array that holds the position of the best personal state of the particle.
    double velocity; ///> the velocity of the particle
    double fitnessValue=0; ///> The fitness value of the particle in relation to an objective function
    double personalBest=0; ///> The personal best or memory of each particle
    vector<int> neighbourhoodIndices;

public:
    Particle(Particle* other){
        velocity = other->velocity;
        fitnessValue = other->fitnessValue;
        personalBest = other->personalBest;
        for(int i=0; i<2; i++) {
            positionArray[i] = other->positionArray[i];
            personalBestPosition[i] = other->personalBestPosition[i];
        }
    }

    Particle(const Particle &other){
        velocity = other.velocity;
        fitnessValue = other.fitnessValue;
        personalBest = other.personalBest;
        for(int i=0; i<2; i++) {
            positionArray[i] = other.positionArray[i];
            personalBestPosition[i] = other.personalBestPosition[i];
        }
    }



///Sets the position array
    void setPositionArray(double *positionArray) {
        this->positionArray[1] = positionArray[0];
        this->positionArray[1] = positionArray[1];
    }

    ///Sets the velocity of the particle
    void setVelocity(double velocity) {
        Particle::velocity = velocity;
    }

    ///Sets the position of the particle based on an array input
    void setParticlePosition(double * positions){
            this->positionArray[0] = positions[0];
            this->positionArray[1] = positions[1];
    }

    ///Sets particle positions based on fixed size array
    void setParticlePositionByArray(double positions[],int dimensions){
        for(int i=0;i<dimensions;i++)
        {
            positionArray[i]=positions[i];
        }
    }

    ///Sets a value at dimension to positionValue in the position array
    void setPositionAtDimension(double positionValue,int dimension){
        positionArray[dimension]=positionValue;
    }

    ///Gets the position array
    void getPositionArray(double *inArr) const {
        inArr[0] = positionArray[0];
        inArr[1] = positionArray[1];
    }

    ///Gets the velocity
    double getVelocity() const {
        return velocity;
    }


    //Gets the value in the position array at dimension
    double getPositionAtDimension(int dimension){
        return positionArray[dimension];
    }

    virtual ~Particle() {
    }

    ///Constructs a new default Particle
    Particle(int dimensions) {
        srand((unsigned)time(NULL));
        velocity=0.0;
        fitnessValue=0.0;
        personalBest=-1;

        positionArray[0]=((double)rand()/(double)RAND_MAX);

        if(dimensions == 2)
       {
           positionArray[1] = ((double)rand()/(double)RAND_MAX);
        }else positionArray[1] = DBL_MAX;

        for (int j = 0; j <2 ; ++j) {
            personalBestPosition[j] = positionArray[j];
        }
    }


    ///Getter for the fitness value
    double getFitnessValue() const {
        return fitnessValue;
    }

    ///Getter for the Personal Best value
    double getPersonalBest() const {
        return personalBest;
    }

    ///Setter for the Personal Best Value
    void setPersonalBest(double PersonalBest) {

        //cout<<"currentBest: "<<personalBest<<" newBest: "<<PersonalBest<<endl;
        personalBest = PersonalBest;

    }

    ///Setter for the fitness value
    void setFitnessValue(double FitnessValue) {
        fitnessValue = FitnessValue;
    }

    ///Getter for the best personal positions array
    double getPersonalBestPosition(double* inArr) const {
        inArr[0] = personalBestPosition[0];
        inArr[1] = personalBestPosition[1];
    }

    ///Setter for the best personal positions array
    void setPersonalBestPosition(double *personalBestPosition) {
        this->personalBestPosition[0] = personalBestPosition[0];
        this->personalBestPosition[1] = personalBestPosition[1];
    }
    ///Gets neighbhourhood indices
    vector<int> getNeighbourhoodIndices()
    {
        return neighbourhoodIndices;
    }

    ///Sets neighbourhood indices
    void setNIndices(vector<int> in)
    {
        neighbourhoodIndices.clear();
        for(int i=0;i<in.size();i++)
        {
            neighbourhoodIndices.push_back(in.at(i));
        }
    }
    
};


#endif //OPT_PARTICLE_H
