#ifndef DBSERVER_H
#define DBSERVER_H

#include <QString>
#include <QsqlDatabase> // если он ругается, значит не подключено в самом проекте

QString authorize(QString login, QString password, QSqlDatabase& db);
bool isOpenDataBase(QSqlDatabase& db, QString DataBaseName);
QString select(QString col, QString nameOfTable, QSqlDatabase& db);

#endif // DBSERVER_H
