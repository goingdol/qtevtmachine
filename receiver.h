#ifndef RECEIVER_H
#define RECEIVER_H
/*
*   receiver.h
*/
#include <QObject>
#include <QDebug>

class Receiver : public QObject {
    Q_OBJECT

public:
    Receiver(QObject *parent = nullptr) : QObject(parent) {}

public slots:
    void handleValueChange(int newValue) {
        qDebug() << "Receiver value: " << newValue;
        emit valueReturn(newValue);
    }

signals:
    void valueReturn(int value);

};
#endif // RECEIVER_H