#ifndef SETTINGSPACKAGE_H
#define SETTINGSPACKAGE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QString>
#include "graphicssettingspackage.h"
#include "optimizersettingspackage.h"
#include "problemdomainsettingspackage.h"
class SettingsPackage: public QObject
{
    Q_OBJECT

private:
    int swarmSize;
    GraphicsSettingsPackage* gpPkg;
    OptimizerSettingsPackage* optPkg;
    ProblemDomainSettingsPackage* probPkg;


public:
    SettingsPackage();

    GraphicsSettingsPackage* getGraphicsSettingsPackage();
    OptimizerSettingsPackage* getOptimizerSettingsPackage();
    ProblemDomainSettingsPackage* getProblemDomainSettingsPackage();

    Q_INVOKABLE void generateSettingsGeneral(int);
    Q_INVOKABLE void generateSettingsGraphics(QString, int, bool, bool, int);
    Q_INVOKABLE void generateSettingsOptimizer(QString*, double, double, double);
    Q_INVOKABLE void generateSettingsDomain(QString, int, int, int, int, int, double, double, double);
};

#endif // SETTINGSPACKAGE_H
