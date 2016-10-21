//
// Created by matheu on 10/11/16.
//

#ifndef SWARMVIZ_TIMER_H
#define SWARMVIZ_TIMER_H


class Timer {
public:
    Timer();

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


#endif //SWARMVIZ_TIMER_H
