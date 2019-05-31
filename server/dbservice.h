#ifndef DBSERVICE_H
#define DBSERVICE_H

#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QFile>
#include <QSqlResult>

class DBService
{
public:
    static bool connect();
    static void remove();
    static void close();
    static QByteArray execute(QString query);
};

#endif // DBSERVICE_H
