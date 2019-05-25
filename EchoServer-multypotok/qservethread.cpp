#include "qservethread.h"


QServethread::QServethread(int descriptor, QObject *parent):
    QThread (parent),socketDescriptor(descriptor)
{

}

QServethread::~QServethread()
{
    delete socket;
}

void QServethread::run()
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket,&QIODevice::readyRead,this,&QServethread::slotServerRead,Qt::DirectConnection);
    connect(socket,&QAbstractSocket::disconnected,this,&QServethread::slotClientDisconnected,Qt::DirectConnection);
    exec();
}

void QServethread::slotServerRead()
{
    while(socket->bytesAvailable()>0)
    {
        QByteArray array = socket->readAll();

        socket->write(array);
    }
}

void QServethread::slotClientDisconnected()
{
socket->close();
quit();
}
