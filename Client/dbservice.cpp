#include "dbservice.h"
#include "client.h"
#include "qbytearrayparcer.h"

#include <QSqlQuery>
#include <QSqlRecord>

#include <QJsonDocument>

#define TABLE_USERS_NAME "users"

// Создание таблицы юзеров
bool DBService::createTableUsers() {
    QString s = "CREATE TABLE ";
    s += TABLE_USERS_NAME;
    s += "("
         "login VARCHAR(30) NOT NULL UNIQUE, "
         "password VARCHAR(30) NOT NULL,"
         "degree INT NOT NULL DEFAULT 3"
         ")";
    QByteArray * response = Client::sendData(s);
    if (QByteArrayParcer::toJsonArray(*response) == nullptr) {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    return true;
}

// Проверка на соответствие логина и пароля у юзеров
bool DBService::checkUser(QString login, QString password) {
    QString s = "SELECT login, password FROM ";
    s += TABLE_USERS_NAME;
    s += " WHERE login = '";
    s += login;
    s += "' AND password = '";
    s += password;
    s += "'";
    QByteArray * response = Client::sendData(s);
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr) {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    if (array->count() == 0)
        return false;
    return true;
}

// Возвращает 1 пользователя, найденного по логину
User* DBService::getUser(QString login) {
    QString s = "SELECT login, password, degree FROM ";
    s += TABLE_USERS_NAME;
    s += " WHERE login = '";
    s += login;
    s += "'";
    QByteArray * response = Client::sendData(s);
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr) {
        qDebug() << QByteArrayParcer::toString(*response);
        return nullptr;
    }
    if (array->count() == 0)
        return nullptr;
    return new User(array->at(0).toObject());
}

// Добавление нового пользователя
void DBService::addUser(QString login, QString password, int degree) {
    QString s = "INSERT INTO ";
    s += TABLE_USERS_NAME;
    s += QString("(login, password, degree) "
         "VALUES ('%1', '%2', %3)").arg(login).arg(password).arg(degree);
    QByteArray * response = Client::sendData(s);
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr) {
        qDebug() << QByteArrayParcer::toString(*response);
        return;
    }
    return;
}

// Возвращает спиок пользователей из базы
QList<User> DBService::getUsers() {
    QString s = "SELECT login, password, degree FROM ";
    s += TABLE_USERS_NAME;
    Client::sendData(s);

    QList<User> users = QList<User>();

    QByteArray * response = Client::sendData(s);
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr) {
        qDebug() << QByteArrayParcer::toString(*response);
        return users;
    }
    for (int i = 0; i < array->count(); i++)
        users.append(User(array->at(i).toObject()));
    return users;
}

// Кол-во таблиц
int DBService::getTablesCount() {
    return 0;
}
