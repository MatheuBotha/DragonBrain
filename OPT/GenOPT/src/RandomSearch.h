/**
 * @class RandomSearch
 *
 * The comparative strength of the other search strategies must be bouyed against
 * some manner of search process. Traditionally, Random Searching is a good way
 * to see how well an alternative search process performs because it should, on
 * average, beat the random search by a considerable margin.
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

#ifndef OPT_RANDOM_H
#define OPT_RANDOM_H
#include "OPT_Process.h"
#include "ObjectiveFunction.h"

class RandomSearch: public OPT_Process {

public:
    //Create a RandomSearch
    RandomSearch(bool output): OPT_Process(output) { }
    ObjectiveFunction *objectiveFunction;
    SnapshotManager *snapshotManager;

///The override method for iterate
    virtual void iterate() override;

    virtual ~RandomSearch() { }
};


#endif //OPT_RANDOM_H
