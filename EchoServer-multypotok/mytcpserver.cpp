#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QTextStream>
#include <QByteArray>
#include <QList> //подключение листов и массивов
#include "dbserver.h"
#include <QDataStream>
#include <QTime>

/**
 * @brief Конструктор сервера
 * @param port Желанный порт
 */
MyTcpServer::MyTcpServer(quint16 port, QObject *parent) : QObject(parent)
{
    tcpServer = new QTcpServer(this); // Инициализация TCP сервера
    if (!tcpServer->listen(QHostAddress::Any, port)) // Если сервер не хочет прослушивать порт
    {
        qDebug().noquote() << QString("Unable to start the server: %1.").arg(tcpServer->errorString()); // Выдать ошибку
        tcpServer->close(); // Закрыть сервер
        return; // Закрыть конструктор
    }
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection())); // Связать newConnection от tcpServer и slotNewConnection от MyTcpServer
    qDebug().noquote() << QString("Server run on %1:%2").arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort());
}

/**
 * @brief MyTcpServer::slotNewConnection
 */
void MyTcpServer::slotNewConnection()
{
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, SIGNAL(disconnected()),
            clientSocket, SLOT(deleteLater())
            );
    connect(clientSocket, SIGNAL(readyRead()),
            this, SLOT(slotReadClient())
            );
    qDebug().noquote() << QObject::tr("New client %i").arg(clientSocket->socketDescriptor());
    sendToClient(clientSocket, "Server Response: Connected!");
}

void MyTcpServer::sendToClient(QTcpSocket* pSocket, const QString& str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out << quint16(0) << QTime::currentTime() << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - int(sizeof(quint16)));

    pSocket->write(arrBlock);
}

void MyTcpServer::slotReadClient()
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
