#include "dbserver.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>

bool isOpenDataBase(QSqlDatabase& db)
{
    if(!db.open()) {
        db.lastError();
        qDebug()<< "Database doesn't open :(";
    }
    else {
        qDebug()<< "Database open! :)";
    }
}

QString authorize(QString login, QString password, QSqlDatabase& db)
{    // тут у нас будет функция, которая делает авторизацию
    // КОРОЧЕЕ
  //каждый раз когда я пытаюсь свернуть окно у тебя я сворачиваю нахер окно проги TViwer и горю
    // теперь у нас есть на сервере файлик с БД. вау.
    //ЪеЪ
    //так. вот тут начинаются увеселения. фишка в том, что если мы будем каждый раз создавать
    //QSqlDatabase db ghb при каждом обращении к базе - сервер будет обмазываться уведомлениями о дупликатных подключениях к базе
    // я делала как. запихивала это все в класс сервера. и изначально зануляла. при авторизации оно записывает это все в класс.
    // в дальнейшем если эта хрень не нулевая - он использует ее. если нулевая, то создает новую. для этого в конструкторе есть эта строка
    //я не знаю правильно ли это делать все через конструкторы, но вот так вот у меня получилось. лучше выхода не нашла.

    // Пишем, какую СУБД будем использовать
    db = QSqlDatabase::addDatabase("QSQLITE");
    // Название БД
    db.setDatabaseName("db.sqlite");
    isOpenDataBase(db);
    // Строка, через которую мы будем делать запросы
   QSqlQuery query(db);
   query.prepare("SELECT degree FROM users WHERE login = :log AND password = :pass");
   std::string stdLog = login.toStdString();
   std::string stdPass = password.toStdString();
   query.bindValue(":log", login);
   query.bindValue(":pass", password);
   query.exec();
   QString status;
   query.next(); //
   QSqlRecord rec = query.record();
   status = "authAnswer&";
   status += query.value(rec.indexOf("degree")).toString();
   qDebug() << status;
   if (status == "authAnswer&")
   {
       qDebug() << "error authorization";
       status = "authAnswer&errorAuth";
   }
   else {
      qDebug() << "authorization";
   }
   db.close();
   return status;
}
QString select(QString col, QString nameOfTable, QSqlDatabase& db){
    isOpenDataBase(db);
    // Строка, через которую мы будем делать запросы
   QSqlQuery query(db);
   query.prepare("SELECT "+col+" FROM "+nameOfTable);
   query.exec();
   QSqlRecord rec = query.record();
   if (nameOfTable == "users"){
       QString rowsValue = "selectAnswer&3&login&password&degree";
       while(query.next()){
           rowsValue += query.value(rec.indexOf("login")).toString();
           rowsValue += "&";
           rowsValue += query.value(rec.indexOf("password")).toString();
           rowsValue += "&";
           rowsValue += query.value(rec.indexOf("degree")).toString();
           rowsValue += "&";
        }
       qDebug() << rowsValue;
       return rowsValue;
    }
}
