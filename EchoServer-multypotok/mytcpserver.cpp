#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QTextStream>
#include <QByteArray>
#include <QList> //подключение листов и массивов
#include "dbserver.h"


MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    tcpServer = new QTcpServer(this);
       connect(tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
       if (!tcpServer->listen(QHostAddress::Any, 33333) && server_status==0) {
           qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(tcpServer->errorString());
       } else {
           server_status=1;
           qDebug() << QString::fromUtf8("Server run!");
       }
}

void MyTcpServer::slotNewConnection()
{
    if(server_status==1){
        qDebug() << QString::fromUtf8("new client");
        QTcpSocket* clientSocket=tcpServer->nextPendingConnection();
        int idusersocs=clientSocket->socketDescriptor();
        SClients[idusersocs]=clientSocket;
        connect(SClients[idusersocs],SIGNAL(readyRead()),this, SLOT(slotServerRead()));
     // connect(SClients[idusersocs],SIGNAL(disconected()),this, SLOT(slotClientDisconnected()));
    }
}

void MyTcpServer::slotServerRead() //после того все что мы отправили переходит в этот слот.
//сервер постоянно проверяет есть ли что-то новое
{
 QTcpSocket* clientSocket = (QTcpSocket*)sender();
 int idusersocs=clientSocket->socketDescriptor();
 QTextStream os(clientSocket);
 if (clientSocket ->bytesAvailable () >0) { // пока есть что считывать с сокета он считывает
     QByteArray array = clientSocket ->readAll(); //и записывает в массив
     qDebug() << "array is" + array; //показывает что  прилетело
     QList <QByteArray> shit =  array.split('&');
     // он будет разделять массив по символу который указан в скобке

     //итого. мы помним что строка у нас имела вид auth&login&password
     if(shit [0] == "auth")
     {
        send_to_client(authorize( shit[1], shit[2], db), clientSocket);
     }
     else if ( shit [0] == "select") {
         send_to_client(select( shit[1], shit[2], db), clientSocket);
     }

}
}

void MyTcpServer::slotClientDisconnected()
{

};

void MyTcpServer::send_to_client(QString message, QTcpSocket* clientSocket)
{

    //вот сейчас мы будем делать самую уебанскую вещь, что можно сделать в qt. но она часто нужна
 QByteArray array;
 array.append(message);
clientSocket->write(array);
};
