/**
 * @class DummyFunction
 *
 * This class is a stand-in class representing an objective function until such time as the actual set
 * of objective functions is known.
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

#ifndef OPT_DUMMYFUNCTION_H
#define OPT_DUMMYFUNCTION_H

#include "ObjectiveFunction.h"

class DummyFunction:public ObjectiveFunction {

public:
    ///The override for the functionInput specific to the DummyFunction
    double functionInput(double *parameters) override;

    ///Creates a new DummyFunction
    DummyFunction() { }

    virtual ~DummyFunction() { }
};


#endif //OPT_DUMMYFUNCTION_H
