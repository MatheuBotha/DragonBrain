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
#include "Particle.h"
#include "ObjectiveFunction.h"
#include "SnapshotManager.h"


class OPT_Process {
protected:
    ObjectiveFunction *objectiveFunction;
    SnapshotManager *snapshotManager;
    Particle* ideal;
    bool printer;
public:

    ///Creates a new OPT_Process
    OPT_Process(bool output) {
        ideal = nullptr;
        printer = output; }
    Particle* getBestSolution() { return ideal; }

    virtual ~OPT_Process() { }

    ///A pure virtual method for the solving process
    virtual void iterate()=0;
private:
};


#endif //OPT_OTP_PROCESS_H
