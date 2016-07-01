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
#include "../OTP_Algorithms/OTP_Process.h"
#include "../OTP_Algorithms/CPSO.h"
#include "../OTP_Algorithms/FIPS.h"
#include "../OTP_Algorithms/GCPSO.h"
#include "../OTP_Algorithms/HillClimber.h"
#include "../OTP_Algorithms/RandomSearch.h"
#include "../Obj_Functions/DummyFunction.h"
#include "../Obj_Functions/ObjectiveFunction.h"


class GenOTP {


public:
    /// Creates a blank, unconfigured GenOTP
    GenOTP() { }

    /** @brief The Configuration Constructor
     *
     * @param OTP An integer indicating which Optimisation Strategy to configure for this GenOTP
     * @param OF An integer indicating which Objective Function to configure for this GenOTP
     * @param maxVelocity A double indicating the maximum velocity size allowed for a particle
     * @param inertiaWeight The initial inertia weighting for the Swarm as a double
     * @param swarmSize An integer indicating how large the swarm must be
     * @param neighbourhoodSize An integer indicating how large neighbourhoods must be considered
     * @param gBest A boolean indicating whether the Global Best strategy must be used
     *
     * Creates a new GenOTP using configuration parameters to set up the GenOTP towards a particular strategy and
     * associated parameters.
     *
     * */
    GenOTP(int OTP,int OF,double maxVelocity, double inertiaWeight, int swarmSize, int neighbourhoodSize, bool gBest) : maxVelocity(
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

    ///Getter for Swarm Size
    int getSwarmSize() const {
        return swarmSize;
    }

    ///Setter for Swarm Size
    void setSwarmSize(int swarmSize) {
        GenOTP::swarmSize = swarmSize;
    }

    ///Getter for inertiaWeight
    double getInertiaWeight() const {
        return inertiaWeight;
    }

    ///Setter for inertiaWeight
    void setInertiaWeight(double inertiaWeight) {
        GenOTP::inertiaWeight = inertiaWeight;
    }

    ///Getter for maxVelocity
    double getMaxVelocity() const {
        return maxVelocity;
    }


    ///Setter for maxVelocity
    void setMaxVelocity(double maxVelocity) {
        GenOTP::maxVelocity = maxVelocity;
    }

    ///Getter for neighbourhoodSize
    int getNeighbourhoodSize() const {
        return neighbourhoodSize;
    }

    ///Setter for neighbourhoodSize
    void setNeighbourhoodSize(int neighbourhoodSize) {
        GenOTP::neighbourhoodSize = neighbourhoodSize;
    }

    ///Getter for OTP_Process
    OTP_Process *getSolvingProcess() const {
        return solvingProcess;
    }

    ///Setter for OTP_Process
    void setSolvingProcess(OTP_Process *solvingProcess) {
        GenOTP::solvingProcess = solvingProcess;
    }

    ///Getter for ObjectiveFunction
    ObjectiveFunction *getObjFunction() const {
        return objFunction;
    }

    ///Setter for ObjectiveFunction
    void setObjFunction(ObjectiveFunction *objFunction) {
        GenOTP::objFunction = objFunction;
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
        GenOTP::gBest = gBest;
    }

    ///Setter for the Swarm
    void setSwarm(Particle *swarm) {
        GenOTP::swarm = swarm;
    }

private:

    OTP_Process * solvingProcess; ///> The pointer to the solving process specific to this instance of the GenOTP

    ObjectiveFunction * objFunction; ///> The pointer to the Objective Function specific to this instance of the GenOTP

    Particle * swarm;///>A pointer to an array used to hold the swarm

    int swarmSize;///>The size of the swarm

    double inertiaWeight;///>The inertia weight value of the swarm

    double maxVelocity;///> The velocity limit on the velocity updates

    int neighbourhoodSize;///> The size of the neighbourhoods for consideration. Neighbourhoods of max size are Global Best Solutions

    bool gBest; ///< The variable used to indicate if Global Best solving is in play
};


#endif //OPT_GENOTP_H
