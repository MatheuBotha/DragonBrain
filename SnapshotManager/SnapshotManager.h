
#ifndef DRAGONBRAIN_SNAPSHOTMANAGER_H
#define DRAGONBRAIN_SNAPSHOTMANAGER_H


#include "snapshot.h"

class SnapshotManager{
private:
    int queueSize;
    int bound;
    int graphicsPosition;
    int swarmSize;
    int dimensions;
    Snapshot* head;
    Snapshot* temp;
    double bounds[4];
    int numIterations;
public:
    SnapshotManager(int Bound, int i, int dim, double bou[4],int its) {
        queueSize = 0;
        graphicsPosition = 0;
        bound = Bound;
        swarmSize = i;
        head = nullptr;
        dimensions = dim;
        for (int j = 0; j < 4; ++j) {
            bounds[j] = bou[j];
        }
        numIterations=its;
    }
    ~SnapshotManager() {
        temp = head;
        while(head)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
    }

    int getBound()
    {
        return bound;
    }

    bool enqueue(Snapshot* snapshot);
    Snapshot* dequeue();
    Snapshot* getLast();
    Snapshot *getFirst();
    int getIterations(){return numIterations;}
};


#endif //DRAGONBRAIN_SNAPSHOTMANAGER_H
