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

using namespace std;

class Particle {
private:

    double * positionArray; ///> the array of double values holding the positions per dimension of the particle
    double * personalBestPosition; ///>the array that holds the position of the best personal state of the particle.
    double velocity; ///> the velocity of the particle
    double fitnessValue=0; ///> The fitness value of the particle in relation to an objective function
    double personalBest=0; ///> The personal best or memory of each particle


public:
    Particle(Particle* other){

        positionArray = new double[2];
        personalBestPosition = new double[2];
        velocity = other->velocity;
        fitnessValue = other->fitnessValue;
        personalBest = other->personalBest;
        for(int i=0; i<2; i++) {
            positionArray[i] = other->positionArray[i];
            personalBestPosition[i] = other->personalBestPosition[i];
        }
    }

    Particle(const Particle &other){

        positionArray = new double[2];
        personalBestPosition = new double[2];
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
        Particle::positionArray = positionArray;
    }

    ///Sets the velocity of the particle
    void setVelocity(double velocity) {
        Particle::velocity = velocity;
    }

    ///Sets the position of the particle based on an array input
    void setParticlePosition(double * positions){

        /*if (positionArray!= nullptr)
        {
            delete positionArray;
        }


        positionArray=new double[2];*/

        for(int i=0;i<2;i++)
        {
            positionArray[i]=positions[i];
        }
    }

    ///Sets particle positions based on fixed size array
    void setParticlePositionByArray(double positions[],int dimensions){

        if (positionArray!= nullptr)
        {
            delete [] positionArray;
        }

        positionArray=new double[dimensions];

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
    double *getPositionArray() const {
        return positionArray;
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
        delete positionArray;
    }

    ///Constructs a new default Particle
    Particle() {
        srand((unsigned)time(NULL));
        velocity=0.0;
        fitnessValue=0.0;
        personalBest=-1;
        positionArray=new double[2];
        for (int i = 0; i <2 ; ++i) {
            positionArray[i]=((double)rand()/(double)RAND_MAX);
        }
        personalBestPosition=new double[2];
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
    double *getPersonalBestPosition() const {
        return personalBestPosition;
    }

    ///Setter for the best personal positions array
    void setPersonalBestPosition(double *personalBestPosition) {
        this->personalBestPosition = personalBestPosition;
    }

};


#endif //OPT_PARTICLE_H
