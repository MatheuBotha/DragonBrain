//
// Created by matheu on 9/8/16.
//

#ifndef DRAGONBRAIN_FPSLIMITER_H
#define DRAGONBRAIN_FPSLIMITER_H

namespace GraphicsEngine {

    ///Calculates FPS and also limits FPS
    class FPSLimiter {
    public:
        FPSLimiter();

        // Initializes the FPS limiter. For now, this is
        // analogous to setMaxFPS
        void init(float maxFPS);

        // Sets the desired max FPS
        void setMaxFPS(float maxFPS);

        void begin();

        // end() will return the current FPS as a float
        float end();
    private:
        // Calculates the current FPS
        void calculateFPS();

        // Variables
        float _fps;
        float _maxFPS;
        float _frameTime;
        unsigned int _startTicks;
    };

}


#endif //DRAGONBRAIN_FPSLIMITER_H
