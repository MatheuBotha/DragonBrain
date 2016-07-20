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
 * @author Emilio Singh u14006512
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
using namespace std;

class Particle {

public:
    ///Sets the position array
    void setPositionArray(double *positionArray) {
        Particle::positionArray = positionArray;
    }

    ///Sets the velocity of the particle
    void setVelocity(double *velocity) {
        Particle::velocity = velocity;
    }

    ///Alternative setter for velocity
    void setVelocity(double v){
        *velocity=v;
    }

    ///Sets the position of the particle based on an array input
    void setParticlePosition(double * positions,int dimensions){

        if (positionArray!= nullptr)
        {
            delete positionArray;
        }


        positionArray=new double[dimensions];

        for(int i=0;i<dimensions;i++)
        {
            positionArray[i]=positions[i];
        }
    }

    ///Sets particle positions based on fixed size array
    void setParticlePositionByArray(double positions[],int dimensions){

        if (positionArray!= nullptr)
        {
            delete positionArray;
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
    double *getVelocity() const {
        return velocity;
    }

    //Gets the value in the position array at dimension
    double getPositionAtDimension(int dimension){
        return positionArray[dimension];
    }

    virtual ~Particle() {
        delete velocity;
        delete positionArray;
    }

    ///Constructs a new default Particle
    Particle() {
        velocity=new double(0.0);
        positionArray=new double[2];
        personalBestPositions=new double[2];
    }

    /** @brief Advanced Constructor Method
     *
     *  @param initV The particle's initial velocity as a double
     *  @param pos The initial positions of the particle as a double array
     *  @param dimensions The number of dimensions for the problem domain for the particle
     * */
    Particle(double initV,double* pos,int dimensions) {

        if (velocity== nullptr)
        {
            velocity=new double;
        }

        *velocity=initV;

        if (positionArray== nullptr)
        {
            positionArray=new double[dimensions];
        }

        for(int i=0;i<dimensions;i++)
        {
            positionArray[i]=pos[i];
        }

        personalBestPositions=new double[2];
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
    void setPersonalBest(double personalBest) {
        Particle::personalBest = personalBest;
    }

    ///Setter for the fitness value
    void setFitnessValue(double fitnessValue) {
        Particle::fitnessValue = fitnessValue;
    }

    ///Getter for the best personal positions array
    double *getPersonalBestPositions() const {
        return personalBestPositions;
    }

    ///Setter for the best personal positions array
    void setPersonalBestPositions(double *personalBestPositions) {
        Particle::personalBestPositions = personalBestPositions;
    }

    ///Getter for the neighbourhood best
    double getNeighbourhoodBest() const {
        return neighbourhoodBest;
    }

    ///Setter for the neighbourhood best
    void setNeighbourhoodBest(double neighbourhoodBest) {
        Particle::neighbourhoodBest = neighbourhoodBest;
    }

    ///Getter for the neighbourhood best position array
    double *getNeighbourhoodBestPosition() const {
        return neighbourhoodBestPosition;
    }

    ///Setter for the neighbourhood best position array
    void setNeighbourhoodBestPosition(double *neighbourhoodBestPosition) {
        Particle::neighbourhoodBestPosition = neighbourhoodBestPosition;
    }

private:


    double * positionArray; ///> the array of double values holding the positions per dimension of the particle
    double * personalBestPositions; ///>the array that holds the positions of the best personal state of the particle.
    double * velocity; ///> the velocity of the particle
    double * neighbourhoodBestPosition; ///> The position of the best neighbour
    double fitnessValue=0; ///> The fitness value of the particle in relation to an objective function
    double personalBest=0; ///> The personal best or memory of each particle
    double neighbourhoodBest=0; ///> The fitness value associated with the best neighbour

};


#endif //OPT_PARTICLE_H
