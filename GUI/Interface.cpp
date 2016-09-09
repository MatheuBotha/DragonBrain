#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>
#include <thread>

#include "../SettingsPackage/src/settingspackage.h"


void* generateGUI(char *argv[], SettingsPackage* setts)
{
    int argc = 1;
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;



    engine.rootContext()->setContextProperty("setPkg", setts);



    engine.load(QUrl("main.qml"));

    app.exec();
}

int main()
{
    char **arger = new char*[1];
    SettingsPackage *setts = new SettingsPackage();
    std::thread GUI_Thread(generateGUI, std::ref(arger), std::ref(setts));

    GUI_Thread.join();
    return 0;
}
