#include "client.h"
#include <QTime>
#include "qbytearrayparcer.h"

static inline QByteArray IntToArray(qint32 source);
static QTcpSocket *socket;

static QHash<QTcpSocket*, QByteArray*> buffers; // Буфер для хранения данных, пока блок не будет полностью получен
static QHash<QTcpSocket*, qint32*> sizes; // Нам нужно сохранить размер, чтобы проверить, получил ли блок полностью

bool Client::createSocket(QObject * parent)
{
    if (socket == nullptr || !socket->isOpen())
    {
        socket = new QTcpSocket(parent);
        QByteArray *buffer = new QByteArray();
        qint32 *s = new qint32(0);
        buffers.insert(socket, buffer);
        sizes.insert(socket, s);
        return true;
    }
    return false;
}

bool Client::connectToHost(QString host, quint16 port)
{
    socket->connectToHost(host, port);
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
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(IntToArray(data.size())); // Отправить размер данных
        socket->write(data); // Отправить сами данные
        socket->waitForBytesWritten();
        socket->waitForReadyRead();

        QByteArray * bytes = read();
        qDebug() << QTime::currentTime().toString() << "IS RESPONSE: " << QByteArrayParcer::toString(*bytes);

        return bytes;
    }
    else
        return nullptr;
}

bool Client::isConnected() {
    return socket->isOpen();
}

QByteArray * Client::sendData(QString data)
{
    QByteArray ba;
    ba.append(data);
    return sendData(ba);
}

QByteArray * Client::read() {
    QByteArray *buffer = buffers.value(socket);
    qint32 *s = sizes.value(socket);
    qint32 size = *sizes.value(socket);
    while (socket->bytesAvailable() > 0)
    {
        buffer->append(socket->readAll());
        while ((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) // Обрабатывать, пока есть данные
        {
            if (size == 0 && buffer->size() >= 4) // Если размер данных получен полностью, то сохранить его
            {
                size = ArrayToInt(buffer->mid(0, 4));
                *s = size;
                buffer->remove(0, 4);
            }
            if (size > 0 && buffer->size() >= size) // Если данные получены полностью, то обрабатываем их
            {
                QByteArray * data = new QByteArray(buffer->mid(0, size));
                buffer->remove(0, size);
                size = 0;
                *s = size;

                return data;
            }
        }
    }
    return nullptr;
}
