#include "someclass.h"

NewClass::NewClass()
{
    connect(this, SIGNAL(newConnection(QString)), this, SLOT(slotNewConnection(QString)));
    connect(this, SIGNAL(newConnection(QString)), this, SLOT(newConn()));
}

void NewClass::connected(QString str) {
    qDebug() << QString("Try connect");
    bool isConnected = true;
    if (isConnected)
        emit newConnection(str);
}

void NewClass::slotNewConnection(QString str)
{
    qDebug() << QString("CONNECTED!!! Connection: %1").arg(str);
}

void NewClass::newConn() {
    qDebug() << "newCone";
}
