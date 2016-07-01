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

    }

private:
    double * positionArray; ///> the array of double values holding the positions per dimension of the particle

    double * velocity; ///> the velocity of the particle


};


#endif //OPT_PARTICLE_H
