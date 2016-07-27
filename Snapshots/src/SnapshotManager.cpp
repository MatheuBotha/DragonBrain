#include "SnapshotManager.h"


SnapshotManager::SnapshotManager(int Bound){
        queueSize = 0;
        bound = Bound;
    }


bool SnapshotManager::enqueue(Snapshot* snapshot){
        queueSize++;

        if(queueSize>bound){
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
            return true;
        }
}

Snapshot* SnapshotManager::dequeue(){
        queueSize--;

        if(queueSize>bound){
            return NULL;
        }

        temp = head;

        if(head==NULL){
            return NULL;
        }else if(head!=NULL){
            if(head->next!=NULL){
                head = head->next;
            }

        }

        return head;
}
