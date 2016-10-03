/**
 * @class OTP_Process
 *
 * At the root of the optimisation problem solving strategies, lies the OTP_Process class which
 * forms the generic basis for the various kinds of processes and strategies that will
 * be used to solve optimisation problems. This class is abstract as no general purpose
 * optimisation problem solving strategy exists that is not within the specific domain of
 * optimisation problem solving strategies already.
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
#ifndef OPT_OTP_PROCESS_H
#define OPT_OTP_PROCESS_H

#include <string>
#include <vector>
#include "Particle.h"
#include "ObjectiveFunction.h"
#include "../../../SnapshotManager/SnapshotManager.h"


class OPT_Process {
protected:
    ObjectiveFunction *objectiveFunction;
    SnapshotManager *snapshotManager;
    Particle* ideal;
    bool printer;
    /**
     * Bounds has the following format
     * [xmin, xmax , ymin , ymax]
     * */
    double bounds[4];

public:

    ///Creates a new OPT_Process
    OPT_Process(bool output,double inBounds[4]) {
        ideal = nullptr;
        printer = output;
        for(int i=0;i<4;i++)
        {
            bounds[i]=inBounds[i];
        }
    }
    Particle* getBestSolution() { return ideal; }

    virtual ~OPT_Process() { }

    ///A pure virtual method for the solving process
    virtual void iterate()=0;
    virtual bool calulateSwarmRadius(Particle** swarm,int swarmS);

    ObjectiveFunction *getObjectiveFunction() const;

    void setObjectiveFunction(ObjectiveFunction *objectiveFunction);

    SnapshotManager *getSnapshotManager() const;

    void setSnapshotManager(SnapshotManager *snapshotManager);

    Particle *getIdeal() const;

    void setIdeal(Particle *ideal);

    bool isPrinter() const;

    void setPrinter(bool printer);

    const double *getBounds() const;
    void setBounds(double inBounds[4]);
    double getBoundAtIndex(int index);

    bool checkBound(double valueToCheck[2]);
private:
};


#endif //OPT_OTP_PROCESS_H
