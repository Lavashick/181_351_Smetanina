#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

#include <QtCore>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT

public slots:
    static bool createSocket(QObject * parent = nullptr);
    static bool connectToHost(QString host, quint16 port);
    static bool isConnected();
    static QByteArray * sendData(QByteArray data);
    static QByteArray * sendData(QString data);
    static QByteArray * read();
};

#endif // CLIENT_H
