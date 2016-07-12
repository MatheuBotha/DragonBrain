#ifndef SETTINGSPACKAGE_H
#define SETTINGSPACKAGE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QString>
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

class SettingsPackage: public QObject
{
    Q_OBJECT

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
    Q_INVOKABLE void generateSettingsGeneral(int);
    /**
      * @brief Generates a GraphicsSettingsPackage using input from the GUI
      */
    Q_INVOKABLE void generateSettingsGraphics(QString, int, bool, bool, int);
    /**
      * @brief Generates a OptimizerSettingsPackage using input from the GUI
      */
    Q_INVOKABLE void generateSettingsOptimizer(QString*, double, double, double);
    /**
      * @brief Generates a ProblemDomainSettingsPackage using input from the GUI
      */
    Q_INVOKABLE void generateSettingsDomain(QString, int, int, int, int, int, double, double, double);
};

#endif // SETTINGSPACKAGE_H
