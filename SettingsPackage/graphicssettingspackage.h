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
    bool showLinks;
    bool showPath;
    int maxRam;
public:
    /**
     * @brief The default constructor for an OptimizerSettingsPackage
     */
    GraphicsSettingsPackage();
    /**
     * @brief Creates a GraphicsSettingsPackage with specified settings (currently unused)
     * @param Resolution height (int)
     * @param Resolution width (int)
     * @param Render speed (int)
     * @param ShowLinks(bool)
     * @param ShowPath (bool)
     * @param MaxRam (int)
     */
    GraphicsSettingsPackage(int, int, int, bool, bool, int);
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
     * @brief
     * @return Returns the render speed (an int)
     */
    int getRenderSpeed();
    /**
     * @brief
     * @return Returns whether links are to be shown or not (a bool)
     */
    bool getShowLinks();
    /**
     * @brief
     * @return Returns whether the path is shown or not (a bool)
     */
    bool getShowPath();
    /**
     * @brief
     * @return Returns the max useable ram in Megabytes (an int)
     */
    int getMaxRam();

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
    /**
     * @brief Sets the render speed
     * @param RenderSpeed (int)
     */
    void setRenderSpeed(int);
    /**
     * @brief Sets link showing on or off
     * @param ShowLink (bool)
     */
    void setShowLinks(bool);
    /**
     * @brief Sets path showing on or off
     * @param ShowPath (bool)
     */
    void setShowPath(bool);
    /**
     * @brief Sets maximum useable ram in megabytes
     * @param MaxRam (int)
     */
    void setMaxRam(int);
};

#endif // GRAPHICSSETTINGSPACKAGE_H
