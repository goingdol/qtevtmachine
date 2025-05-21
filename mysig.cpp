#include <QObject>
#include <QDebug>
#include "mysig.h"

MyString::MyString(QObject *parent) : QObject(parent){
    myString = "This is a MyString";
    qDebug() << "MyString constructor:" << myString;
}

MyString::~MyString() {
    qDebug() << "MyString destructor";
}

void MyString::setString(QString value) {
    myString = value;
    qDebug() << "setString: " << myString;
    emit myStringChanged();
}

QString MyString::getString() const {
    qDebug() << "getString: " << myString;
    return myString;
}