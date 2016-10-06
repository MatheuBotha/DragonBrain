/**
 * @class ObjectiveFunction
 *
 * The objective function is the mathematical representation of the particular problem that requires
 * optimisation. The ObjectiveFunction class is the root of a hierarchy of objective functions that are specialised
 * from this class. As a result, this class is abstract since no generic objective function exists.
 *
 * @note Still in Progress
 *
 * @authors
 * Gerard van wyk u14101263
 * Emilio Singh u14006512
 *
 * @version 0.4
 *
 * @date: 2016/07/01 12:16
 *
 * Contact: u14006512@tuks.co.za
 *
 * */
#ifndef OPT_OBJECTIVEFUNCTION_H
#define OPT_OBJECTIVEFUNCTION_H

#include <cmath>
#include <cfloat>
#include <iostream>
using namespace std;

class ObjectiveFunction {
public:
    ///Creates a new Objective Function
    ObjectiveFunction(double s, double x, double y, double v) {
        scale = s;
        xShift = x;
        yShift = y;
        vShift = v;

        defaultBounds[0]=-1.0;
        defaultBounds[1]=1.0;
        defaultBounds[2]=-1.0;
        defaultBounds[3]=1.0;
    }
    ///The static function that returns the target output for the given input
   virtual double functionInput(double * parameters)=0;

   void transformInput(double * input)
   {

       if(input[1] == DBL_MAX){
           input[1] = 0;
       }
       input[0] += xShift;
       input[1] += yShift;

   }

    double transformOutput(double output){
        return (output + vShift)*scale;
    }

    void getBounds(double *boundArr)
    {
        boundArr[0] = defaultBounds[0];
        boundArr[1] = defaultBounds[1];
        boundArr[2] = defaultBounds[2];
        boundArr[3] = defaultBounds[3];
    }
private:
    double scale;
    double xShift;
    double yShift;
    double vShift;
protected:
    double defaultBounds[4];

};


#endif //OPT_OBJECTIVEFUNCTION_H
