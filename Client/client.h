#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

#include <QtCore>
#include <QTcpSocket>

/**
 * @brief Работа сервера с клиентом
 */
class Client : public QObject
{
    Q_OBJECT

public slots:
    /**
     * @brief Создание сокета
     */
    static bool createSocket(QObject * parent = nullptr);
    /**
     * @brief Создание соединения с хостом
     */
    static bool connectToHost(QString host, quint16 port);
    /**
     * @brief Проверка на подключение сервера к клиенту
     */
    static bool isConnected();
    /**
     * @brief Отправить запрос и получить ответ
     */
    static QByteArray * sendData(QByteArray data);
    /**
     * @brief Отправить запрос и получить ответ
     */
    static QByteArray * sendData(QString data);
private:
    /**
     * @brief Чтение сервером ответа от клиента
     */
    static QByteArray * read();

private slots:
    static void disconnected();
};

#endif // CLIENT_H
