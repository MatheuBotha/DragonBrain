#ifndef SETTINGSPACKAGE_H
#define SETTINGSPACKAGE_H

#include "graphicssettingspackage.h"
#include "optimizersettingspackage.h"
#include "problemdomainsettingspackage.h"

/**
 * @class ProblemDomainSettingsPackage
 *
 * This class is a general SettingsPackage which contains
 * other, more specific SettingsPackages and extracts settings
 * from the GUI
 * */

class SettingsPackage
{

private:
    int swarmSize;
    GraphicsSettingsPackage* gpPkg;
    OptimizerSettingsPackage* optPkg;
    ProblemDomainSettingsPackage* probPkg;


public:
    /**
     * @brief Default SettingsPackage Constructor, calls default constructors for a
     * Graphics, Optimizer and ProblemDomain SettingsPackage.
     */
    SettingsPackage();

    /**
     * @brief
     * @return Returns the swarmsize associated with the entire system
     */
    int getSwarmSize();
    /**
     * @brief
     * @return Returns the associated GraphicsSettingsPackage
     */
    GraphicsSettingsPackage* getGraphicsSettingsPackage();
    /**
     * @brief
     * @return Returns the associated OptimizerSettingsPackage
     */

    OptimizerSettingsPackage* getOptimizerSettingsPackage();
    /**
     * @brief
     * @return Returns the associated ProblemDomainSettingsPackage
     */
    ProblemDomainSettingsPackage* getProblemDomainSettingsPackage();

    /**
      * @brief Sets the swarm size (given by GUI)
      * @param SwarmSize (int)
      */
    void generateSettingsGeneral(int);
    /**
      * @brief Generates a GraphicsSettingsPackage using input from the GUI
      */
    void generateSettingsGraphics(std::string, int, bool, bool, int);
    /**
      * @brief Generates a OptimizerSettingsPackage using input from the GUI
      */
    void generateSettingsOptimizer(std::string, double, double, double, int ,int);
    /**
      * @brief Generates a ProblemDomainSettingsPackage using input from the GUI
      */
    void generateSettingsDomain(std::string, int, int, int, int, int, double, double, double);
};

#endif // SETTINGSPACKAGE_H
