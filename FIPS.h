/**
 * @class FIPS
 *
 * This is one form of the PSO solving strategy that is used in optimisation problem
 * solving. This particular version is the  Fully Informed PSO variant
 * of the traditional PSO.
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

#ifndef OPT_FIPS_H
#define OPT_FIPS_H

#include "PSO.h"
class FIPS:public PSO{

public:
    ///The override method for solve
    virtual void solve() override;

    ///Creates a new FIPS
    FIPS() { }

    virtual ~FIPS() { }
};


#endif //OPT_FIPS_H
