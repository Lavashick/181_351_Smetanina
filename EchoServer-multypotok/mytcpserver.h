#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

// Класс работы с нашим сервером
class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(quint16 port, QObject *parent = nullptr);
    void sendToClient(QTcpSocket* pSocket, const QString& str);
public slots:
    void slotNewConnection();
    void slotReadClient();

private:
    QTcpServer *tcpServer; // Сам сервер
    quint16 m_nNextBlockSize;
};

#endif // MYTCPSERVER_H
