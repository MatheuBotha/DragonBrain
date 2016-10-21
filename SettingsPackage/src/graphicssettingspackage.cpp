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



void GraphicsSettingsPackage::setResolutionH(int newH)
{
    resolutionH = newH;
}

void GraphicsSettingsPackage::setResolutionW(int newW)
{
    resolutionW = newW;
}



void GraphicsSettingsPackage::setRenderSpeed(int i) {
    renderSpeed = i;
}

int GraphicsSettingsPackage::getRenderSpeed() {
    return renderSpeed;
}

