#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSqlDatabase>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);
    void send_to_client (QString message, QTcpSocket* clientSocket);
public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QTcpServer *tcpServer;
    int server_status;
    QMap<int,QTcpSocket *> SClients;
    QSqlDatabase db; /*= nullptr;*/ // а не, вот у меня короче висит проблема с первоначальным занулением. пока оставим так.
};



#endif // MYTCPSERVER_H
