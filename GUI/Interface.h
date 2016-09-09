#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>
#include <thread>

#include "../SettingsPackage/src/settingspackage.h"
#ifndef GUI_EXE
#define GUI_EXE

void* runGUI(SettingsPackage* setts)
{
    char **arger = new char*[1];
    int argc = 1;
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QGuiApplication app(argc, arger);

    QQmlApplicationEngine engine;



    engine.rootContext()->setContextProperty("setPkg", setts);



    engine.load(QUrl("main.qml"));

    app.exec();
}

#endif