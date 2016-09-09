#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "../SettingsPackage/src/settingspackage.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;



    SettingsPackage *setts = new SettingsPackage();
    engine.rootContext()->setContextProperty("setPkg", setts);



    engine.load(QUrl("main.qml"));

    return app.exec();
}
