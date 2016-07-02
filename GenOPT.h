/**
 * @class GenOTP
 *
 * This class models the object GenOTP that will contain the methods and variables required
 * to perform generic Optimisation on problems through user configuration mediated by an external interface.
 * This class is designed to be generic enough and configurable enough such that the process of solving an optimisation
 * problem can be performed concurrently by up to 4 solvers at a time.
 *
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
#ifndef OPT_GENOTP_H
#define OPT_GENOTP_H

#include "../Particle/Particle.h"
#include "../OPT_Algorithms/OPT_Process.h"
#include "../OPT_Algorithms/CPSO.h"
#include "../OPT_Algorithms/FIPS.h"
#include "../OPT_Algorithms/GCPSO.h"
#include "../OPT_Algorithms/HillClimber.h"
#include "../OPT_Algorithms/RandomSearch.h"
#include "../Obj_Functions/DummyFunction.h"
#include "../Obj_Functions/ObjectiveFunction.h"
#include <string>
#include <random>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

class GenOPT {


public:
    /// Creates a blank, unconfigured GenOPT
    GenOPT() { }

    /** @brief The Configuration Constructor
     *
     * @param OTP An integer indicating which Optimisation Strategy to configure for this GenOPT
     * @param OF An integer indicating which Objective Function to configure for this GenOPT
     * @param maxVelocity A double indicating the maximum velocity size allowed for a particle
     * @param inertiaWeight The initial inertia weighting for the Swarm as a double
     * @param swarmSize An integer indicating how large the swarm must be
     * @param neighbourhoodSize An integer indicating how large neighbourhoods must be considered
     * @param gBest A boolean indicating whether the Global Best strategy must be used
     *
     * Creates a new GenOPT using configuration parameters to set up the GenOPT towards a particular strategy and
     * associated parameters.
     *
     * */
    GenOPT(int OTP,int OF,double maxVelocity, double inertiaWeight, int swarmSize, int neighbourhoodSize, bool gBest) : maxVelocity(
            maxVelocity), inertiaWeight(inertiaWeight), swarmSize(swarmSize), neighbourhoodSize(neighbourhoodSize),
                                                                                                         gBest(gBest) {

        swarm=new Particle[swarmSize];

        switch (OF)
        {
            default: objFunction=new DummyFunction();
        }

        switch (OTP)
        {
            case 0: solvingProcess=new RandomSearch();
                break;
            case 1: solvingProcess=new HillClimber();
                break;
            case 2: solvingProcess=new CPSO();
                break;
            case 3: solvingProcess=new GCPSO();
                break;
            case 5: solvingProcess=new FIPS();
                break;
            default: solvingProcess=new RandomSearch();
        }

    }

    /*A method that receives all of the positions of the configured particles and instantiates the swarm accordingly.
     *
     * The placements array should have the following format:
     *
     * [a;b;c] where [] denotes an element and a,b,c are values delimited by semicolons
    */
    void initialSetupOfSwarm(string * placements,int dimensions);

    /* This generates a random starting position for a particle in the swarm within given dimensions.
     * The arr value is a 2D matrix containing the max and min values for each dimension
     * A coordinate per dimension is randomized between those bounds. All coordinates are then
     * concatenated into a string which is returned.
     *
     * arr[i][0]==lower bound of dimension i
     * arr[i][1]==upper bound of dimension i
     *
     * The bounds are defined as integers but particle coordinates are doubles.
     *      double lower_bound = 0;
     *      double upper_bound = 10000;
     *      std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
     *      std::default_random_engine re;
     *      double a_random_double = unif(re);
     *
     *      Example output for 3 dimensions: 7;4;2
     * */
    string generateParticleCoordinates(int ** arr,int dimensions);
    /*This method will take dimensions and generate an array containing all of the initial positions for the
     * all particles in the swarm
     *
     * Example output for 2 particles with 3 dimensions
     *
     * 0:[5;4;3],1:[3;2;1]
    */
    string * generateSwarmInitialConfiguration(int ** arr,int dimensions);

    ///Getter for Swarm Size
    int getSwarmSize() const {
        return swarmSize;
    }

    ///Setter for Swarm Size
    void setSwarmSize(int swarmSize) {
        GenOPT::swarmSize = swarmSize;
    }

    ///Getter for inertiaWeight
    double getInertiaWeight() const {
        return inertiaWeight;
    }

    ///Setter for inertiaWeight
    void setInertiaWeight(double inertiaWeight) {
        GenOPT::inertiaWeight = inertiaWeight;
    }

    ///Getter for maxVelocity
    double getMaxVelocity() const {
        return maxVelocity;
    }


    ///Setter for maxVelocity
    void setMaxVelocity(double maxVelocity) {
        GenOPT::maxVelocity = maxVelocity;
    }

    ///Getter for neighbourhoodSize
    int getNeighbourhoodSize() const {
        return neighbourhoodSize;
    }

    ///Setter for neighbourhoodSize
    void setNeighbourhoodSize(int neighbourhoodSize) {
        GenOPT::neighbourhoodSize = neighbourhoodSize;
    }

    ///Getter for OPT_Process
    OPT_Process *getSolvingProcess() const {
        return solvingProcess;
    }

    ///Setter for OPT_Process
    void setSolvingProcess(OPT_Process *solvingProcess) {
        GenOPT::solvingProcess = solvingProcess;
    }

    ///Getter for ObjectiveFunction
    ObjectiveFunction *getObjFunction() const {
        return objFunction;
    }

    ///Setter for ObjectiveFunction
    void setObjFunction(ObjectiveFunction *objFunction) {
        GenOPT::objFunction = objFunction;
    }

    ///Getter for the Swarm
    Particle *getSwarm() const {
        return swarm;
    }

    ///Getter for gBest
    bool isGBest() const {
        return gBest;
    }

    ///Setter for gBest
    void setGBest(bool gBest) {
        GenOPT::gBest = gBest;
    }

    ///Setter for the Swarm
    void setSwarm(Particle *swarm) {
        GenOPT::swarm = swarm;
    }

private:

    OPT_Process * solvingProcess; ///> The pointer to the solving process specific to this instance of the GenOPT

    ObjectiveFunction * objFunction; ///> The pointer to the Objective Function specific to this instance of the GenOPT

    Particle * swarm;///>A pointer to an array used to hold the swarm

    int swarmSize;///>The size of the swarm

    double inertiaWeight;///>The inertia weight value of the swarm

    double maxVelocity;///> The velocity limit on the velocity updates

    int neighbourhoodSize;///> The size of the neighbourhoods for consideration. Neighbourhoods of max size are Global Best Solutions

    bool gBest; ///< The variable used to indicate if Global Best solving is in play
};


#endif //OPT_GENOTP_H
