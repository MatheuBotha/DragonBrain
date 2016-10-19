#include "graphicssettingspackage.h"

GraphicsSettingsPackage::GraphicsSettingsPackage()
{

}


int GraphicsSettingsPackage::getResolutionH()
{
    return resolutionH;
}

int GraphicsSettingsPackage::getResolutionW()
{
    return resolutionW;
}

bool GraphicsSettingsPackage::getShowLinks()
{
    return showLinks;
}

bool GraphicsSettingsPackage::getShowPath()
{
    return showPath;
}


void GraphicsSettingsPackage::setResolutionH(int newH)
{
    resolutionH = newH;
}

void GraphicsSettingsPackage::setResolutionW(int newW)
{
    resolutionW = newW;
}


void GraphicsSettingsPackage::setShowLinks(bool links)
{
    showLinks = links;
}

void GraphicsSettingsPackage::setShowPath(bool path)
{
    showPath = path;
}


