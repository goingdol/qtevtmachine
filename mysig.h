#ifndef MYSIG_H
#define MYSIG_H

#include <QObject>
#include <QString>

class MyString : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString myString READ getString WRITE setString NOTIFY myStringChanged)

public:
    explicit MyString(QObject *parent = nullptr);
    ~MyString();

    Q_INVOKABLE void setString(QString value);
    Q_INVOKABLE QString getString() const;

signals:
    void myStringChanged();

private:
    QString myString;

};
#endif // MYSIG_H
