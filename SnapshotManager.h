
#ifndef DRAGONBRAIN_SNAPSHOTMANAGER_H
#define DRAGONBRAIN_SNAPSHOTMANAGER_H


#include "snapshot.h"

class SnapshotManager{
private:
    int queueSize;
    int bound;
    int graphicsPosition;
    int swarmSize;
    Snapshot* head;
    Snapshot* temp;
public:
    SnapshotManager(int Bound, int i) {
        queueSize = 0;
        graphicsPosition = 0;
        bound = Bound;
        swarmSize = i;
        head = nullptr;
    }
    bool enqueue(Snapshot* snapshot);
    Snapshot* dequeue();
    Snapshot* getLast();
    Snapshot *getFirst();
};


#endif //DRAGONBRAIN_SNAPSHOTMANAGER_H
