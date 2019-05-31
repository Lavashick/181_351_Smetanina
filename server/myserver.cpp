#include "myserver.h"
#include "dbservice.h"
#include "console.h"

QString getSocketAddress(QTcpSocket * socket)
{
    return (socket->peerAddress().toString() + ":" + QString::number(socket->peerPort()));
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

MyServer::MyServer(quint16 port, QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    if (!server->listen(QHostAddress::Any, port))
    {
        qDebug().noquote() << QString("Unable to start the server: %1.").arg(server->errorString()); // Выдать ошибку
        server->close();
        return;
    }
    connect(server, SIGNAL(newConnection()), SLOT(newConnection()));
    QString message = QString("Listening %2:%3").arg(server->serverAddress().toString()).arg(server->serverPort());
    Console::writeWithTime(message);
    DBService::connect();
}

void MyServer::newConnection()
{
    while (server->hasPendingConnections())
    {
        QTcpSocket *socket = server->nextPendingConnection();
        connect(socket, SIGNAL(readyRead()), SLOT(readSocket()));
        connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
        QByteArray *buffer = new QByteArray();
        qint32 *s = new qint32(0);
        buffers.insert(socket, buffer);
        Console::writeWithTime(QString("New connection from %1:%2").arg(socket->peerAddress().toString()).arg(socket->peerPort()));
        sizes.insert(socket, s);
    }
}

void MyServer::sendToSocket(QTcpSocket* socket, QByteArray data)
{
    socket->write(IntToArray(data.size())); // Отправить размер данных
    socket->write(data); // Отправить сами данные
}

void MyServer::disconnected()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QByteArray *buffer = buffers.value(socket);
    qint32 *s = sizes.value(socket);
    QString message = QString("Disconnected from %1:%2").arg(socket->peerAddress().toString()).arg(socket->peerPort());
    Console::writeWithTime(message);
    socket->deleteLater();
    delete buffer;
    delete s;
}

void MyServer::readSocket()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
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
                // DATA
                QByteArray data = buffer->mid(0, size);
                buffer->remove(0, size);
                size = 0;
                *s = size;
                // PRINT REQUEST
                QString socketAddress = getSocketAddress(socket);
                QString dataAsString = QString::fromStdString(data.toStdString());
                Console::writeWithTime(socketAddress + ": " + dataAsString);

                // GET RESPONSE
                QByteArray response = DBService::execute(dataAsString);
                // SEND RESPONSE
                sendToSocket(socket, response);
            }
        }
    }
}