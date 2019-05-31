#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include <QTcpSocket>
#include <QDataStream>
#include <QDateTime>

class MyServer : public QObject
{
    Q_OBJECT

public:
    explicit MyServer(quint16 port, QObject *parent = nullptr);
    void sendToSocket(QTcpSocket* socket, QByteArray data);

private slots:
    void newConnection();
    void disconnected();
    void readSocket();

private:
    QTcpServer* server;
    QHash<QTcpSocket*, QByteArray*> buffers; // Буфер для хранения данных, пока блок не будет полностью получен
    QHash<QTcpSocket*, qint32*> sizes; // Нам нужно сохранить размер, чтобы проверить, получил ли блок полностью
};

#endif // MYSERVER_H
