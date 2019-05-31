#ifndef DBSERVER_H
#define DBSERVER_H

#include <QString>
#include <QsqlDatabase>

class DBserver
{
public:
    DBserver();

    // Проверяет, открыта ли наша база данных
    bool isOpenDataBase(QSqlDatabase& db);
    // Строка, через которые будут происходить запросы
    void selectFromDB(QString nameOfCol, QString nameOfTable, QString login, QString password,  QSqlDatabase& db);
    // Находим  БД
    void findDB(QSqlDatabase& db, QString nameOfDB, QString nameOfsql);
    QString checkValue(QString nameOfTable, QString login, QString password,  QSqlDatabase& db);

};

#endif // DBSERVER_H
