#ifndef DBSERVICE_H
#define DBSERVICE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QList>
#include "user.h"

class DBService
{
public:
    static void connect();
    static bool createTableUsers();
    static int getTablesCount();
    static void remove();
    static void close();
    static void addUser(QString login, QString password, int degree);
    static bool checkUser(QString login, QString password);
    static User* getUser(QString login);
    static QList<User> getUsers();
};

#endif // DBSERVICE_H
