#ifndef GRAPHICSSETTINGSPACKAGE_H
#define GRAPHICSSETTINGSPACKAGE_H


/**
 * @class OptimizerSettingsPackage
 *
 * This class is a wrapper for all the settings related to the Graphics Processor
 * The contents are rather simplistic, only getters and setters.
 * */

class GraphicsSettingsPackage
{
private:

    int resolutionH;
    int resolutionW;
    int renderSpeed;

public:
    /**
     * @brief The default constructor for an OptimizerSettingsPackage
     */
    GraphicsSettingsPackage();
    /**
     * @brief
     * @return Returns the resolution height dimension (an int)
     */
    int getResolutionH();
    /**
     * @brief
     * @return Returns the resolution width dimension (an int)
     */
    int getResolutionW();

    /**
     * @brief Sets the resolution height
     * @param ResolutionHeight (int)
     */
    void setResolutionH(int);
    /**
     * @brief Sets the resolution width
     * @param ResolutionWidth (int)
     */
    void setResolutionW(int);

    void setRenderSpeed(int i);

    int getRenderSpeed();

};

#endif // GRAPHICSSETTINGSPACKAGE_H
