#include "myserver.h"
#include <QDataStream>
#include <QDateTime>

QString getCurrentDateTime()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    int year = dateTime.date().year();
    int month = dateTime.date().month();
    int day = dateTime.date().day();
    QString date = QString("%1.%2.%3").arg(day).arg(month).arg(year);
    return date + " " + dateTime.time().toString();
}

void print(QString message)
{
    qDebug().noquote() << QString("%1: %2").arg(getCurrentDateTime()).arg(message);
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
    QString message = QString("Server started on %2:%3").arg(server->serverAddress().toString()).arg(server->serverPort());
    print(message);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

void MyServer::newConnection()
{
    QTcpSocket * socket = server->nextPendingConnection();
    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readSocket()));
    print(QString("New connection from %1").arg(socket->socketDescriptor()));
    sendToSocket(socket, "Connected");
}

void MyServer::sendToSocket(QTcpSocket* socket, const QString& str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out << quint16(0) << QTime::currentTime() << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - int(sizeof(quint16)));

    socket->write(arrBlock);
}

void MyServer::readSocket()
{
    QTcpSocket* clientSocket = static_cast<QTcpSocket*>(sender());
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_4_2);
    for (;;) {
        if (!m_nNextBlockSize) {
            if (clientSocket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }

        if (clientSocket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }
        QTime time;
        QString str;
        in >> time >> str;

        QString strMessage =
            time.toString() + " " + "Client has sended - " + str;

        m_nNextBlockSize = 0;

        sendToClient(clientSocket,
                     "Server Response: Received \"" + str + "\""
                    );
    }
}
