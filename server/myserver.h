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
    /**
     * @brief Отправление на сокет
     */
    void sendToSocket(QTcpSocket* socket, QByteArray data);

private slots:
    /**
     * @brief Обработка нового соединения
     */
    void newConnection();
    /**
     * @brief Обработка отсоединения
     */
    void disconnected();
    /**
     * @brief Чтение сокета
     */
    void readSocket();

private:
    QTcpServer* server;

    /**
     * @brief Буфер для хранения данных, пока блок не будет полностью получен
     */
    QHash<QTcpSocket*, QByteArray*> buffers;

    /**
     * @brief Хранение размера для проверки получения блока полностью
     */
    QHash<QTcpSocket*, qint32*> sizes;
};

#endif // MYSERVER_H
