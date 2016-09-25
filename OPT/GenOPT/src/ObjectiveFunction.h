/**
 * @class ObjectiveFunction
 *
 * The objective function is the mathematical representation of the particular problem that requires
 * optimisation. The ObjectiveFunction class is the root of a hierarchy of objective functions that are specialised
 * from this class. As a result, this class is abstract since no generic objective function exists.
 *
 * @note Still in Progress
 *
 * @author Emilio Singh u14006512
 *
 * @version 0.1
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
    double scale;
    double horShift;
    double vShift;
public:
    double x;
    double y;

    ///Creates a new Objection Function
    ObjectiveFunction(double s, double h, double v) {
        scale = s;
        horShift = h;
        vShift = v;
    }
    ///The static function that returns the target output for the given input
   virtual double functionInput(double * parameters)=0;

   void setParams(double * params) {
       x=params[0]+horShift;
       if(params[1] != DBL_MAX)
           y=params[1]+horShift;
   }

   double transformResult(double res)
   {
       return (vShift+res)*scale;
   }
private:

};


#endif //OPT_OBJECTIVEFUNCTION_H
