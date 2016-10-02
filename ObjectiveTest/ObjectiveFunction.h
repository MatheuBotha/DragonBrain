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
 * @version 0.3
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

using namespace std;

class ObjectiveFunction {
public:
    double scale;
    double xShift;
    double yShift;
    double vShift;

    ///Creates a new Objective Function
    ObjectiveFunction(double s, double x, double y, double v) {
        scale = s;
        xShift = x;
        yShift = y;
        vShift = v;
    }
    ///The static function that returns the target output for the given input
   virtual double functionInput(double * parameters)=0;

   double * transformInput(double * input)
   {
       if(input[1] == DBL_MAX){
           input[1] = 0;
       }

       input[0] *= xShift;
       input[1] *= yShift;

       input[0] *= scale;
       input[1] *= scale;

       return input;
   }

    double transformOutput(double output){
        return output * vShift;
    }
private:

};


#endif //OPT_OBJECTIVEFUNCTION_H
