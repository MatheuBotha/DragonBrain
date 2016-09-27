//
// Created by E Singh on 7/1/2016.
//

#include "OPT_Process.h"

bool OPT_Process::caclulateSwarmRadius(Particle** swarm,int swarmS) {
    int swarmSize=swarmS;
    double bestValue=-1;
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
        }
    }

    if(swarm[0]->getPositionArrayPointer()[1]==DBL_MAX || swarm[0]->getPositionArrayPointer()[1]==DBL_MIN)
    {
        for (int j=0;j<swarmSize;j++)
        {
            averageDistance=averageDistance+abs(baseCoordinates[0]-swarm[j]->getPositionArrayPointer()[0]);
            distanceVector.push_back(abs(baseCoordinates[0]-swarm[j]->getPositionArrayPointer()[0]));
        }
    }else
        {
            double tmp;
            for (int j=0;j<swarmSize;j++)
            {
                tmp=sqrt(pow((baseCoordinates[0]-swarm[j]->getPositionArrayPointer()[0]),2)
                         +pow((baseCoordinates[1]-swarm[j]->getPositionArrayPointer()[1]),2));
                averageDistance=averageDistance+tmp;
                distanceVector.push_back(tmp);
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

    if (closeness<=0.2) return true;
    else return false;

    return false;
}
