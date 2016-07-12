
#ifndef DRAGONBRAIN_SNAPSHOTMANAGER_H
#define DRAGONBRAIN_SNAPSHOTMANAGER_H

class SnapshotManager{
private:
    int queueSize;
    int bound;
    Snapshot* head;
    Snapshot* temp;
public:
    SnapshotManager(int Bound);
    bool enqueue(Snapshot snapshot);
    SnapShot* dequeue();
};


#endif //DRAGONBRAIN_SNAPSHOTMANAGER_H
