#include "SnapshotManager.h"


SnapshotManager::SnapshotManager(int Bound){
        queueSize = 0;
        bound = Bound;
        head = NULL;
    }


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

        if(head==NULL){
            return NULL;
        }else if(head!=NULL){
            if(head->next!=NULL){
                head = head->next;
            }
            else head = NULL;

        }

        queueSize--;
        return temp;
}
