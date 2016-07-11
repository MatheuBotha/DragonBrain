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

#include <climits>
#include <string>
#include <random>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <cstring>`
#include <vector>

using namespace std;

class GenOPT {


public:
    /// Creates a blank, unconfigured GenOPT
    GenOPT() { }

    virtual ~GenOPT();

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
    GenOPT(int OTP,int OF,double maxVelocity, double inertiaWeight,double transA,double transB,double transC, int swarmSize, int neighbourhoodSize,int ** dimensionBounds, string * placements,int dimensions,bool gBest,double cOne,double cTwo,SnapshotManager & snaps) : maxVelocity(
            maxVelocity), inertiaWeight(inertiaWeight), swarmSize(swarmSize), neighbourhoodSize(neighbourhoodSize),
                                                                                                         gBest(gBest),c1(cOne),c2(cTwo) {

        string * tmpPlacements;
        if (placements[0].compare("-")==0)
        {
            tmpPlacements=new string[swarmSize];
            tmpPlacements=generateSwarmInitialConfiguration(dimensionBounds,dimensions);
            initialSetupOfSwarm(tmpPlacements,dimensions);
        } else
            {
                initialSetupOfSwarm(placements,dimensions);
            }

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

    neighbourhoodMatrix=new int * [swarmSize];

        for (int i = 0; i < swarmSize; ++i)
        {
            neighbourhoodMatrix[i]=new int[swarmSize];
        }
    for (int i=0;i<swarmSize;i++)
    {
        for(int j=0;j<swarmSize;j++)
        {
            neighbourhoodMatrix[i][j]=-1;
        }
    }
    generateSwarmNMatrix();

    transformationA=transA;
    transformationB=transB;
    transformationC=transC;
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


    /*
     * This method will generate the swarm linkages between all of the particles.
     * This is accomplished by randomly assigning, uniquely, particles to neighbourhoods, based on a given size,
     * until that neighbourhood is fully completed. Particles are allowed to have overlapping neighbourhoods in terms
     * of neighbourhoods having particles that are already in other neighbourhoods but a particle will only view
     * the local scope of its own neighbourhood.
     *
     * This method also helps to account for a global scope since it will mean that if global best is chosen, it will
     * then assign all of the particles per neighbourhood to all others.
     * */
    void generateSwarmNMatrix();

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

    ///Getter for C1
    double getC1() const {
        return c1;
    }

    ///Setter for C1
    void setC1(double c1) {
        GenOPT::c1 = c1;
    }

    ///Getter for C2
    double getC2() const {
        return c2;
    }

    ///Setter for C2
    void setC2(double c2) {
        GenOPT::c2 = c2;
    }

private:

    OPT_Process * solvingProcess; ///> The pointer to the solving process specific to this instance of the GenOPT

    ObjectiveFunction * objFunction; ///> The pointer to the Objective Function specific to this instance of the GenOPT

    Particle * swarm;///>A pointer to an array used to hold the swarm

    /* Swarm Configuration Structure that stores the links between particles in the swarm.
     *
     * The neighbourhood matrix is a 2D integer matrix structure that represents the links between the particles in the
     * swarm by use of integer values in the matrix representing a relationship between the specific index and its
     * row/column index which represents the particles.
     *
     * For example,
     *   0 1 2
     * 0 x 1 -1
     * 1 1 x -1
     * 2 1 1 x
     *
     * In the above example, we have 3 particles, 0-2. Obviously, a particle cannot be in a neighbourhood with itself
     * so x, INT_MAX, is used to denote this when a particle's coordinates are symmetrical. In other cases, the use
     * of 1 or -1 is to denote either that those particles are in a neighbourhood or not, with 1 being yes and -1 being
     * no.
     *
     * Note that this relationship only works row wise due to the possibility of neighbourhood overlap. So for instance,
     * we can see that particle 0 has only particle 1 in its neighbourhood. Particle 1, has particle 0 in its neighbourhood
     * but this is a case of neighbourhood overlap and both these neighbourhoods are separate entities which overlap
     * rather than bi-directional relationships although a column wise reading will indicate which of the particles
     * are in a neighbourhood with a given particle.
     *
     * */
    int ** neighbourhoodMatrix;

    int swarmSize;///>The size of the swarm

    double inertiaWeight;///>The inertia weight value of the swarm

    double maxVelocity;///> The velocity limit on the velocity updates

    int neighbourhoodSize;///> The size of the neighbourhoods for consideration. Neighbourhoods of max size are Global Best Solutions

    bool gBest; ///< The variable used to indicate if Global Best solving is in play

    double c1; ///< The variable used to store the value of the Cognitive Acceleration coefficient
    double c2; ///< The variable used to store the value of the Social Acceleration coefficient

    double transformationA;
    double transformationB;
    double transformationC;
    SnapshotManager & snappy;
};


#endif //OPT_GENOTP_H
