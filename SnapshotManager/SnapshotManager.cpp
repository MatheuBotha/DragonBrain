#include "SnapshotManager.h"

bool SnapshotManager::enqueue(Snapshot* snapshot){

        if(queueSize>=bound){
            return false;
        }
        if(head == NULL){
            head = snapshot;
        }else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = snapshot;
        }

    if(head==NULL){
            return false;
        }else{
            queueSize++;
            return true;
        }
}

Snapshot* SnapshotManager::dequeue(){
    temp = head;
    for(int i=0; i<graphicsPosition && i<queueSize-1 && i<bound; i++){
        temp = temp->next;
    }
    if(graphicsPosition<queueSize) {
        graphicsPosition++;
    }

    if(temp->getSwarm()[0]->getPositionAtDimension(1) == DBL_MAX) {
        for (int i = 0; i < temp->getSwarmSize(); ++i) {
            temp->getSwarm()[i]->setPositionAtDimension(0.0, 1);
        }
    }
    return temp;
}

Snapshot *SnapshotManager::getLast() {
    if(head==NULL){
        head = new Snapshot(swarmSize, dimensions, bounds);
    }
    Snapshot* last=head;
    while(last->next != NULL){
        last = last->next;
    }
    return last;
}

Snapshot *SnapshotManager::getFirst() {
    if(head==NULL){
        head = new Snapshot(swarmSize, dimensions, bounds);
    }
    return head;
}
