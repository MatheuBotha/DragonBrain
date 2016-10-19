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
    bool showLinks;
    bool showPath;
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
     * @brief Sets link showing on or off
     * @param ShowLink (bool)
     */
    void setShowLinks(bool);
    /**
     * @brief Sets path showing on or off
     * @param ShowPath (bool)
     */
    void setShowPath(bool);
};

#endif // GRAPHICSSETTINGSPACKAGE_H
