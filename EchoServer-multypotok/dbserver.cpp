#include "dbserver.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>

bool DBserver::isOpenDataBase(QSqlDatabase& db)
{
    if(!db.open()) {
        db.lastError();
        qDebug()<< "Database doesn't open :(";
    }
    else {
        qDebug()<< "Database open! :)";
    }
    return false;
}


void DBserver::selectFromDB(QString nameOfCol, QString nameOfTable, QString login, QString password,  QSqlDatabase& db)
{
    QSqlQuery query(db);
    // Подготовка запроса по синтаксису
    query.prepare("SELECT" + nameOfCol + "FROM" + nameOfTable + "WHERE login = :log AND password = :pass");
    // Дополнение запроса
    query.bindValue(":log", login);
    query.bindValue(":pass", password);
    // Выполнение запроса
    query.exec();
}








void DBserver::findDB(QSqlDatabase& db, QString nameOfDB, QString nameOfsql)
{
    // Пишем, какую СУБД будем использовать
    db = QSqlDatabase::addDatabase(nameOfsql);
    // Название БД
    db.setDatabaseName(nameOfDB);
}
