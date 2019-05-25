#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QList>
#include "user.h"

class DataBase
{
public:
    static void connect();
    static void createTableUsers();
    static int getTablesCount();
    static void remove();
    static void close();
    static void addUser(QString login, QString password, int degree);
    static bool checkUser(QString login, QString password);
    static User* getUser(QString login);
    static QList<User> getUsers();
};

#endif // DATABASE_H
