#include "graphicssettingspackage.h"

GraphicsSettingsPackage::GraphicsSettingsPackage()
{

}

GraphicsSettingsPackage::GraphicsSettingsPackage(int resH, int resW, int rendSpeed, bool links, bool path, int ram)
{
    resolutionH = resH;
    resolutionW = resW;
    renderSpeed = rendSpeed;
    showLinks = links;
    showPath = path;
    maxRam = ram;

}

int GraphicsSettingsPackage::getResolutionH()
{
    return resolutionH;
}

int GraphicsSettingsPackage::getResolutionW()
{
    return resolutionW;
}

int GraphicsSettingsPackage::getRenderSpeed()
{
    return renderSpeed;
}

bool GraphicsSettingsPackage::getShowLinks()
{
    return showLinks;
}

bool GraphicsSettingsPackage::getShowPath()
{
    return showPath;
}

int GraphicsSettingsPackage::getMaxRam()
{
    return maxRam;
}

void GraphicsSettingsPackage::setResolutionH(int newH)
{
    resolutionH = newH;
}

void GraphicsSettingsPackage::setResolutionW(int newW)
{
    resolutionW = newW;
}

void GraphicsSettingsPackage::setRenderSpeed(int newRend)
{
    renderSpeed = newRend;
}

void GraphicsSettingsPackage::setShowLinks(bool links)
{
    showLinks = links;
}

void GraphicsSettingsPackage::setShowPath(bool path)
{
    showPath = path;
}

void GraphicsSettingsPackage::setMaxRam(int newRam)
{
    maxRam = newRam;
}

