//
// Created by Warmaster on 7/1/2016.
//

#include "GenOPT.h"
void GenOPT::initialSetupOfSwarm(string * placements,int dimensions){

    double values[dimensions];
    string sline;

    for(int i=0;i<swarmSize;i++)
    {
    sline=placements[i];
    string tmp;

    for(int j=0;j<dimensions-1;j++)
    {
    tmp=sline.substr(0,sline.find(";"));
    sline=sline.erase(0,sline.find(";")+1);
    values[j]=atof(tmp.c_str());
    }
    values[dimensions-1]=atof(tmp.c_str());

    swarm[i]->setParticlePositionByArray(values,dimensions);

    swarm[i]->setVelocity((rand()%10+1/1.0));
    }

}

string *GenOPT::generateSwarmInitialConfiguration(int **arr, int dimensions) {

    string * swarmPositions=new string[swarmSize];
    string tmp;

    bool found;

    for (int i=0;i<swarmPositions->length();i++)
    {
        do {
            found=false;
            tmp = generateParticleCoordinates(arr, dimensions);

            for(int j=0;j<swarmPositions->length();j++)
            {
                if (swarmPositions[j].compare(tmp)==0)
                {
                    found=true;
                }
            }
        }
        while (found);

        swarmPositions[i]=tmp;
    }

    return swarmPositions;
}


string GenOPT::generateParticleCoordinates(int **arr, int dimensions) {


        string result;
        double tmp;
        ostringstream strs;

        for (int i=0;i<dimensions;i++)
        {
            uniform_real_distribution<double> unif(arr[i][0],arr[i][1]);
            default_random_engine eng;
            tmp=unif(eng);

            strs<<tmp;

            if (i!=dimensions-1)
            {
                result = result + strs.str()+";";
            }   else
            {
                result=result+strs.str();
            }
            strs.clear();
        }
        return result;


}

GenOPT::~GenOPT() {
    delete objFunction;
    delete solvingProcess;
    delete [] swarm;


    for(int i=0;i<swarmSize;i++)
    {
        delete []neighbourhoodMatrix[i];
    }

    delete []neighbourhoodMatrix;
}


void GenOPT::generateSwarmNMatrix() {

    vector<int> indexPool;
    int randomIndex;
    bool found = false;

    if (neighbourhoodMatrix== nullptr){
    neighbourhoodMatrix = new int *[swarmSize];

    for (int i = 0; i < swarmSize; ++i) {
        neighbourhoodMatrix[i] = new int[swarmSize];
    }
    for (int i = 0; i < swarmSize; i++) {
        for (int j = 0; j < swarmSize; j++) {
            neighbourhoodMatrix[i][j] = -1;
        }
    }
    }
    for(int i=0;i<swarmSize;i++)
    {
        neighbourhoodMatrix[i][i]=INT_MAX;
    }

    for(int i=0;i<swarmSize;i++)
    {
        indexPool.clear();
        indexPool.resize(0);

        while(indexPool.size()!=(neighbourhoodSize)) {
            randomIndex = rand() % swarmSize;
            found = false;

            if (indexPool.size() != 0)
            {
                for (int k = 0; k < indexPool.size() && !found; k++) {
                    if (indexPool.at(k) == randomIndex) {
                        found = true;
                    }
                }
            }

            if (randomIndex!=i && !found )
            {
                indexPool.push_back(randomIndex);
            }
        }

        while(indexPool.size()>0)
        {
            neighbourhoodMatrix[i][indexPool.at(0)]=1;
            indexPool.erase(indexPool.begin());
        }
    }

}


void GenOPT::solveProblem() {

/* General Algorithm
     * Pre-Conditions:
     * 1) Swarm must be initialised
     * 2) Swarm must have a placement
     * 3) All particles must have a starting velocity
     *
     * 1) Check for stopping conditions
     *      1) Sufficient Iterations
     *      2) Ideal Solution found
     *      3) Normalised swarm radius?
     *      4) Pre-mature Halt {handled externally}
     *      5) No progress in solution(convergence?)
     * 2) If (no stopping condition is true)
     *     A) For each particle
     *            1) Update best positions {Function of GenOPT}
     *           [2)] update a global best position {Function of GenOPT}
     *     B) For each particle
     *          ->Update Velocity {Function of OPT_Algorithm}
     *          ->Update Position {Function of OPT_Algorithm}
     *
     *
     * Repeat
     *  for each particle do
     *      evaluate particle fitness
     *      update particle's personal best position
     *      update particle's neighbourhood best position
     *  end
     *
     *  for each particle do
     *      update particle's velocity
     *      update particle's position
     *  end
     *
     *  while stopping conditions false
     * **/
    int iterations=0;
    double bestSolution=-1;
    double prevBestSolution=0;
    double timesWithoutProgress=0;
    double tmpFitness=0;
    double tmpVelocity=0;
    double * tmpPositions=new double[2];

    ///Stopping Conditions
    while((iterations<maxIterations) || (bestSolution<accuracyRequirement)|| (timesWithoutProgress<20))
    {
        prevBestSolution=bestSolution;


        ///Local Best is in effect{Contingent on Neighbourhood Size}
        /** Local best attempts to find the best fitness value of any of the neighbours of a given particle
         *
         * Process
         * 1)Use N-Matrix to determine which of the other particles comprise the neighbourhood
         * 2)The best fitness/position amongst the neighbourhood
         * 3)Save best neighbourhood value/position of best
         */

        ///Determine best solution in swarm
        for(int i=0;i<swarmSize;i++) {
            tmpFitness = objFunction->functionInput(swarm[i]->getPositionArray());
            swarm[i]->setFitnessValue(tmpFitness);

            if (tmpFitness > swarm[i]->getPersonalBest()) {
                swarm[i]->setPersonalBest(tmpFitness);
                swarm[i]->setPersonalBestPositions(swarm[i]->getPositionArray());
            }
        }

        //neighbourhoodSize!=swarmSize --> Not Global Best therefore, local
        if (neighbourhoodSize!=swarmSize)
        {
            //Checks occur at i-size,i+size for neighbourhood
            //Edge cases checked first

        } else //Global Best
            {
                int indexOfBest=-1;
                bestSolution=swarm[0]->getFitnessValue();
                for (int i=0;i<swarmSize;i++)
                {
                    tmpFitness=swarm[i]->getFitnessValue();

                    if (tmpFitness>bestSolution)
                    {
                        bestSolution=tmpFitness;
                        indexOfBest=i;
                    }
                }

                for(int i=0;i<swarmSize;i++)
                {
                    swarm[i]->setNeighbourhoodBest(swarm[indexOfBest]->getFitnessValue());
                }
            }




        ///Update particles position and velocity
        for(int i=0;i<swarmSize;i++)
        {
            if (tmpPositions!= nullptr)
            {
                delete tmpPositions;
            }
            tmpPositions=new double[2];
            tmpVelocity=solvingProcess->updateVelocity(*swarm[i]);
            swarm[i]->setVelocity(tmpVelocity);

            tmpPositions=solvingProcess->updatePosition(*swarm[i]);
            swarm[i]->setPositionArray(tmpPositions);
        }


        if (bestSolution==prevBestSolution)
        {
            timesWithoutProgress++;
        }
        iterations++;
    }


}
//Getter for neighbourhood matrix
int **GenOPT::getNeighbourhoodMatrix() const {
    return neighbourhoodMatrix;
}

//Setter for neighbourhoood matrix
void GenOPT::setNeighbourhoodMatrix(int **neighbourhoodMatrix) {
    GenOPT::neighbourhoodMatrix = neighbourhoodMatrix;
}

void GenOPT::updateSettings(SettingsPackage package) {

    c1=package.getOptimizerSettingsPackage()->getCognitiveCoefficient();
    c2=package.getOptimizerSettingsPackage()->getSocialCoefficient();
}




