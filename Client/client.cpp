#include "client.h"
#include "qbytearrayparcer.h"
#include <QMessageBox>
#include <QApplication>
#include <QObject>

#include "cipher.h"

static inline QByteArray IntToArray(qint32 source);
static QTcpSocket *socket;

static QString serverHost;
static quint16 serverPort;

static QByteArray password = "lcBLQUYXzyn1FynxKTYhFumzsFi6jEV2"; // Случайный пароль. Совпадает с паролем на сервере

static QByteArray* buffer = new QByteArray(); // Буфер для хранения данных, пока блок не будет полностью получен
static qint32* s = new qint32(0); // Нам нужно сохранить размер, чтобы проверить, получил ли блок полностью

// Подбирает свободный порт клиенту
bool Client::createSocket(QObject * parent)
{
    if (socket == nullptr || !socket->isOpen())
    {
        socket = new QTcpSocket(parent);
        return true;
    }
    return false;
}

void Client::disconnected()
{
    QMessageBox::warning(nullptr, "Network error", "Disconnected from the server");
    QApplication::quit();
}

bool Client::connectToHost(QString host, quint16 port)
{
    serverHost = host;
    serverPort = port;
    socket->connectToHost(host, port);
    QObject::connect(socket, &QTcpSocket::disconnected, &Client::disconnected);
    return socket->waitForConnected();
}

qint32 ArrayToInt(QByteArray source)
{
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}

QByteArray IntToArray(qint32 source) // Используем qint32 чтобы гарантировать, что размер данных имеет 4 байта
{
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}

QByteArray * Client::sendData(QByteArray data)
{
    if(socket->state() == QTcpSocket::ConnectedState)
    {
        QByteArray encryptedData = Cipher().encryptAES(password, data);
        socket->write(IntToArray(encryptedData.size())); // Отправить размер данных
        socket->write(encryptedData); // Отправить сами данные
        socket->waitForBytesWritten(); // Ожидание прочтения данных сервером
        socket->waitForReadyRead(); // Когда сервер ответит, то сокет можно будет считать

        QByteArray * bytes = read();

        return bytes;
    }
    else if (Client::connectToHost(serverHost, serverPort)) {
        return Client::sendData(data);
    } else {
        return nullptr;
    }
}

bool Client::isConnected() {
    return socket->state() == QTcpSocket::ConnectedState;
}

QByteArray * Client::sendData(QString data)
{
    return sendData(QByteArrayParcer::stringToBytes(data));
}

QByteArray * Client::read() {
    qint32 size = *s;
    QByteArray readedData = QByteArray();
    while (socket->bytesAvailable() > 0)
    {
        buffer->append(socket->readAll());
        while ((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) // Обрабатывать, пока есть данные
        {
            int f = buffer->size();
            if (size == 0 && buffer->size() >= 4) // Если размер данных получен полностью, то сохранить его
            {
                size = ArrayToInt(buffer->mid(0, 4));
                *s = size;
                buffer->remove(0, 4);
            }
            f = buffer->size();
            if (size > 0 && buffer->size() >= size) // Если данные получены полностью, то обрабатываем их
            {
                QByteArray data = buffer->mid(0, size);
                buffer->remove(0, size);
                size = 0;
                *s = size;

                readedData.append(data);
            } else {
                socket->waitForReadyRead();
            }
        }
    }

    QByteArray * decryptedData = new QByteArray(Cipher().decryptAES(password, readedData));
    return decryptedData;
}
