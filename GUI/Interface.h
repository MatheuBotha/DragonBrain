#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>
#include <thread>

#include "../SettingsPackage/src/settingspackage.h"
#ifndef GUI_EXE_H
#define GUI_EXE_H

class GUI_EXE
{
public:
    static void* runGUI(SettingsPackage* setts)
    {
        char **arger = new char*[1];
        int argc = 1;
            QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
            QCoreApplication::setApplicationName("SwarmViz");
            QGuiApplication app(argc, arger);

        QQmlApplicationEngine engine;



        engine.rootContext()->setContextProperty("setPkg", setts);



        engine.load(QUrl("qml_resources/main.qml"));

        app.exec();
    }
};
#endif