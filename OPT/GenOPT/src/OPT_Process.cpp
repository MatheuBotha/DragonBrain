//
// Created by E Singh on 7/1/2016.
//

#include "OPT_Process.h"

bool OPT_Process::calulateSwarmRadius(Particle** swarm,int swarmS) {
    int swarmSize=swarmS;
    double bestValue=-1;
    int bestIndex=-1;
    vector<double> distanceVector;
    double baseCoordinates[2];

    double maxDistance=0;
    double averageDistance=0;
    baseCoordinates[0]=-1;
    baseCoordinates[1]=-1;

    for (int i=0;i<swarmSize;i++)
    {
        if (swarm[i]->getFitnessValue()>bestValue) {
            bestValue = swarm[i]->getFitnessValue();
            baseCoordinates[0] = swarm[i]->getPositionArrayPointer()[0];
            baseCoordinates[1] = swarm[i]->getPositionArrayPointer()[1];
            bestIndex=i;
        }
    }

    if(swarm[0]->getPositionArrayPointer()[1]==DBL_MAX || swarm[0]->getPositionArrayPointer()[1]==DBL_MIN)
    {
        for (int j=0;j<swarmSize;j++)
        {
            if (j!=bestIndex) {
                averageDistance = averageDistance + abs(baseCoordinates[0] - swarm[j]->getPositionArrayPointer()[0]);
                distanceVector.push_back(abs(baseCoordinates[0] - swarm[j]->getPositionArrayPointer()[0]));
            }
        }
    }else
        {
            double tmp;
            for (int j=0;j<swarmSize;j++)
            {
                if (j!=bestIndex) {
                    tmp = sqrt(pow((baseCoordinates[0] - swarm[j]->getPositionArrayPointer()[0]), 2)
                               + pow((baseCoordinates[1] - swarm[j]->getPositionArrayPointer()[1]), 2));
                    averageDistance = averageDistance + tmp;
                    distanceVector.push_back(tmp);
                }
            }
        }

    for(int i=0;i<distanceVector.size();i++)
    {
        if (distanceVector.at(i)>maxDistance)
        {
            maxDistance=distanceVector.at(i);
        }
    }

    double closeness=averageDistance/maxDistance;

    if (closeness<=0.2 || abs(averageDistance-maxDistance)<0.1) return true;
    else return false;

    return false;
}

ObjectiveFunction *OPT_Process::getObjectiveFunction() const {
    return objectiveFunction;
}

void OPT_Process::setObjectiveFunction(ObjectiveFunction *objectiveFunction) {
    OPT_Process::objectiveFunction = objectiveFunction;
}

SnapshotManager *OPT_Process::getSnapshotManager() const {
    return snapshotManager;
}

void OPT_Process::setSnapshotManager(SnapshotManager *snapshotManager) {
    OPT_Process::snapshotManager = snapshotManager;
}

Particle *OPT_Process::getIdeal() const {
    return ideal;
}

void OPT_Process::setIdeal(Particle *ideal) {
    OPT_Process::ideal = ideal;
}

bool OPT_Process::isPrinter() const {
    return printer;
}

void OPT_Process::setPrinter(bool printer) {
    OPT_Process::printer = printer;
}

const double *OPT_Process::getBounds() const {
    return bounds;
}
void OPT_Process::setBounds(double boundsIn[4])
{
    for(int i=0;i<4;i++)
    {
        bounds[i]=boundsIn[i];
    }
}

double OPT_Process::getBoundAtIndex(int index) {
    return bounds[index];
}

bool OPT_Process::checkBound(double valueToCheck[2]) {
    return valueToCheck[1] == DBL_MAX ? valueToCheck[0] >= bounds[0] && valueToCheck[0] <= bounds[1] :
           valueToCheck[0] >= bounds[0] && valueToCheck[0] <= bounds[1]
           && (valueToCheck[1] >= bounds[3] && valueToCheck[1] <= bounds[4]);
}
