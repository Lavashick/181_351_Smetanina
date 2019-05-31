#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include <QTcpSocket>

class MyServer : public QObject
{
    Q_OBJECT

public:
    explicit MyServer(quint16 port, QObject *parent = nullptr);
    void sendToSocket(QTcpSocket* pSocket, const QString& str);

private:
    QTcpServer* server;
    quint16 m_nNextBlockSize;

private slots:
    void newConnection();
    void readSocket();

};

#endif // MYSERVER_H
