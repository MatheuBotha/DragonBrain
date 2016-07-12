#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>

//when settingspackage exists
/*#include "settingspackage.h"
    SettingsPackage *setts = new SettingsPackage();
    engine.rootContext()->setContextProperty("setPkg", setts);
    */

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;




    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
