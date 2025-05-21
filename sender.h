#ifndef SENDER_H
#define SENDER_H
/*
*  sender.h
*/
#include <QObject>
#include <QDebug>

class Sender : public QObject {
    Q_OBJECT
    Q_PROPERTY(int m_value READ getValue WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString myValue READ getMyValue)

public:
    Sender(QObject *parent = nullptr) : QObject(parent), m_value(0), myValue("Zero") {}

    void setValue(int value) {
        if(m_value != value) {
            qDebug() << "setValue: " << value;
            m_value = value;
            myValue = QString::number(value);
            emit valueChanged(m_value, myValue);
        }
    }

signals:
    void valueChanged(int value, QString myValue);

public slots:
    void handleValueReturned(int newValue) {
            qDebug() << "Returned value: " << newValue;
            myValue = QString::number(newValue);
    }

    Q_INVOKABLE int getValue() const {
        qDebug() << "getValue: " << m_value;
        return m_value;
    }

    Q_INVOKABLE QString getMyValue() const {
        qDebug() << "getMyValue: " << myValue;
        return myValue;
    }

private:
    int m_value;
    QString myValue;
};
#endif
