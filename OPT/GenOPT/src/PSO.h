/**
 * @class PSO
 *
 * Particle Swarm Optimisation is a general form of solving optimisation problems.
 * The PSO class forms its own root of a PSO hierarchy with several variations of the PSO
 * process represented as subclasses of this one.
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
#ifndef OPT_PSO_H
#define OPT_PSO_H

#include "OPT_Process.h"
#include <random>
class PSO: public OPT_Process {

protected:
    /**
     * cryHalt is a special boolean value that exists within the optimiser. If it
     * detects that no real progress is being made by any of the particles
     * it will be set to true allowing a premature halt.
     * */
    bool cryHalt=false;
    mt19937 generator;
    double cog=0.5; //cognitive component
    double soc=0.5; //social component
public:
    /** Default empty constructor
     * */
    PSO(bool output,double inBounds[4]);

    /** Specialised constructor
     * */
    PSO(ObjectiveFunction *myObjectiveFunction, SnapshotManager *mySnapshotManager, bool output,double inBounds[4],double s,double c);

    /**
     *  Destructor
     * */

    virtual ~PSO();

    /**Getter-setter block for c1,c2
     *
     * */
    double getCog()
    {
        return cog;
    }

    double getSoc()
    {
        return soc;
    }

    void setCog(double c)
    {
        cog=c;
    }

    void setSoc(double s)
    {
        soc=s;
    }

    /*Marsenne Twister Random Number Generator*/
    double getRandomNumberMT();

    virtual void iterate() override;

    /** updateVelocity will perform velocity updates to given particles
     *  Currently in the base PSO, velocity updates do not make use of any special techniques
     *  or mechanisms
     * */
    virtual void updateVelocity(Particle *particle);

    /**
     * updatePosition will update the position of the given particle
     * Currently, it will perform a piecewise update of the particle's position array.
     *
     * */
    virtual void updatePosition(Particle * particle);

    PSO(ObjectiveFunction *pFunction, SnapshotManager *pManager, bool i);


};


#endif //OPT_PSO_H
