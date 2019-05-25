#include "dialog.h"
#include "DataBase.h"
#include <QApplication>
#include <QDebug>
#include "dialogadmin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

 /*   DataBase::remove();
    DataBase::connect();
    qDebug() << "Кол-во таблиц:" << DataBase::getTablesCount();
    DataBase::createTableUsers();
    qDebug() << "Кол-во таблиц теперь:" << DataBase::getTablesCount();
    // degree - степень "власти": 3 - user, 2 - moderator, 1 - admin
    DataBase::addUser("1", "1", 1);
    DataBase::addUser("user", "iamuser", 3);
    DataBase::addUser("admin", "iamadmin", 1);
    DataBase::addUser("moderator", "iammoderator", 2);

    // Вывод таблицы юзеров в Debug
    QList<User> users = DataBase::getUsers();
    for (int i = 0; i < users.count(); i++) {
        qDebug() << "Login: " << users.at(i).login << "Password: " << users.at(i).password << "Degree: " << users.at(i).degree;
    }
*/
    Dialog d;
    d.show();

    return a.exec();
}
