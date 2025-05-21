#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mysig.h"
#include "sender.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<MyString>("com.example.mysig", 1, 0, "MyString");
    qmlRegisterType<Sender>("com.example.mysig", 1, 0, "Sender");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    auto* mySender = new Sender(&engine);
    auto* myReceiver = new Receiver(&engine);
    MyString* myString = new MyString(&engine);

    engine.rootContext()->setContextProperty("myStringInstance", myString);
    engine.rootContext()->setContextProperty("mySenderInstance", mySender);
    engine.rootContext()->setContextProperty("myReceiverInstance", myReceiver);

    QObject::connect(mySender, &Sender::valueChanged, myReceiver, &Receiver::handleValueChange);
    QObject::connect(myReceiver, &Receiver::valueReturn, mySender, &Sender::handleValueReturned);

    mySender->setValue(10);

    engine.load(url);

    qDebug() << "engine.load(url) is called";

    return app.exec();
}
