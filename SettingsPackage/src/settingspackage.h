#ifndef SETTINGSPACKAGE_H
#define SETTINGSPACKAGE_H

#include "graphicssettingspackage.h"
#include "optimizersettingspackage.h"
#include "problemdomainsettingspackage.h"
#include <QObject>
#include <QString>
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
    int numInstances;
    bool locked;
    bool changed;
    bool closing;
    bool ready;
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
     * @brief Default SettingsPackage destructor, calls default destructors for a
     * Graphics, Optimizer and ProblemDomain SettingsPackage.
     */
    ~SettingsPackage();

    /**
     * @brief Returns the lock status of the SettingsPackage
     */
    Q_INVOKABLE bool isLocked();

     /**
     * @brief Locks the SettingsPackage, so that the OPT will not try to use it while its data is being edited.
     */
    Q_INVOKABLE void lock(bool);


    /**
    * @brief Returns the changed status of the SettingsPackage
    */
    Q_INVOKABLE bool hasChanged();

    /**
     * @brief Indicates that the settings have changed.
     */
    Q_INVOKABLE void change(bool);


    Q_INVOKABLE void closeNext() { closing = true; }
    bool readyToClose() { return closing; }

    Q_INVOKABLE void readyNext(bool r) { ready = r; }
    Q_INVOKABLE bool readyForNext() { return ready; }
    /**
     * @brief
     * @return Returns the swarmsize associated with the entire system
     */
    int getSwarmSize();

    int getNumInstances();

    void setSwarmSize(int a) { swarmSize = a; }

    void setNumInstances(int n) { numInstances = n; }
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
    Q_INVOKABLE void generateSettingsGeneral(int, int);
    /**
      * @brief Generates a GraphicsSettingsPackage using input from the GUI
      */
    Q_INVOKABLE void generateSettingsGraphics(QString,
                                              bool, bool);
    /**
      * @brief Generates a OptimizerSettingsPackage using input from the GUI
      */
    Q_INVOKABLE void generateSettingsOptimizer(QString algorithm, QString algo2, QString algo3, QString algo4, int maxIterations, double cog, double soc,
    double constrictionCoeff, double maxVelo, int success, int fail, int neighbourSize);
    /**
      * @brief Generates a ProblemDomainSettingsPackage using input from the GUI
      */
    Q_INVOKABLE void generateSettingsDomain(QString, int , double, double, double, double, double, double, double, double);

    void updateSettings(double transA, double transB, double transC, double transD, double maxVelocity, int succ, int fail);

};

#endif // SETTINGSPACKAGE_H
