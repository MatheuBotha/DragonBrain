
/**
 * @class SnapshotManager
 *
 * The SnapshotManager is an object that encapsulates all the snapshots that have been produced.
 * The snapshots are stored in a bounded queue from which snapshot objects will be enqueued by
 * an optimiser and dequeued by the graphics pipeline.
 *
 * @note In Progress
 *
 * @author Gerard van wyk u14101263
 *
 * @version 0.1
 *
 * @date: 2016-07-12 17:28
 *
 * Contact: u14101263@tuks.co.za
 *
 * */

class SnapshotManager{
private:
    int queueSize;
    int bound;
    Snapshot* head;
    Snapshot* temp;

public:
    SnapshotManager(int Bound){
        queueSize = 0;
        bound = Bound;
    }

    bool enqueue(Snapshot* snapshot){
        queueSize++;

        if(queueSize>bound){
            return false;
        }

        if(head == null){
            head = snapshot;
        }else{
            temp = head;
            while(temp->next != null){
                temp = temp->next;
            }
            temp->next = snapshot;
        }

        if(head==null){
            return false;
        }else{
            return true;
        }
    }

    SnapShot* dequeue(){
        queueSize--;

        if(queueSize>bound){
            return null;
        }

        temp = head;

        if(head==null){
            return null;
        }else if(head!=null){
            if(head->next!=null){
                head = head->next;
            }

        }

        return head;
    }
};

#include "SnapshotManager.h"
