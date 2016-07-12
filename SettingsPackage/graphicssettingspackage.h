#ifndef GRAPHICSSETTINGSPACKAGE_H
#define GRAPHICSSETTINGSPACKAGE_H


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
    GraphicsSettingsPackage();
    GraphicsSettingsPackage(int, int, int, bool, bool, int);
    int getResolutionH();
    int getResolutionW();
    int getRenderSpeed();
    bool getShowLinks();
    bool getShowPath();
    int getMaxRam();

    void setResolutionH(int);
    void setResolutionW(int);
    void setRenderSpeed(int);
    void setShowLinks(bool);
    void setShowPath(bool);
    void setMaxRam(int);
};

#endif // GRAPHICSSETTINGSPACKAGE_H
