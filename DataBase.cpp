#include "DataBase.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFile>

#define TABLE_USERS_NAME "users"
#define DB_NAME "db.sqlite"
#define DB_DRIVER "QSQLITE"
#define DB_CONNECTION_NAME "connect"

static QSqlDatabase db;
static QSqlQuery query;


// Подключение базы данных
void DataBase::connect() {
    // Создание Базы данных типа QSQLite
    // QSQLite - драйвер в Qt
    db = QSqlDatabase::addDatabase(DB_DRIVER, DB_CONNECTION_NAME);
    // Задаем имя базе данных:
    db.setDatabaseName(DB_NAME);

    query = QSqlQuery(db);

    // Если не открывает нашу бд, то выводим последнюю ошибку:
    if(!db.open())
        qDebug() << db.lastError().text();
}


// Создание таблицы юзеров
void DataBase::createTableUsers() {
    QString s = "CREATE TABLE ";
    s += TABLE_USERS_NAME;
    s += "("
         "login VARCHAR(30) NOT NULL UNIQUE, "
         "password VARCHAR(30) NOT NULL,"
         "degree INT NOT NULL DEFAULT 3"
         ")";
    query.exec(s);
    if (db.lastError().isValid())
        qDebug() << db.lastError().text();
}


// Проверка на соответствие логина и пароля у юзеров
bool DataBase::checkUser(QString login, QString password) {
    QString s = "SELECT login, password FROM ";
    s += TABLE_USERS_NAME;
    s += " WHERE login = '";
    s += login;
    s += "' AND password = '";
    s += password;
    s += "'";
    query.exec(s);
    if (db.lastError().isValid())
        qDebug() << db.lastError().text();
    return query.next();
}

// Возвращает 1 пользователя, найденного по логину
User* DataBase::getUser(QString login) {
    QString s = "SELECT login, password, degree FROM ";
    s += TABLE_USERS_NAME;
    s += " WHERE login = '";
    s += login;
    s += "'";
    query.exec(s);
    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");
    const int passwordIndex = rec.indexOf("password");
    const int degreeIndex = rec.indexOf("degree");
    if (query.next()) {
         return new User(query.value(loginIndex).toString(), query.value(passwordIndex).toString(), query.value(degreeIndex).toInt());
    } else return nullptr;
}

// Добавление нового пользователя
void DataBase::addUser(QString login, QString password, int degree) {
    QString s = "INSERT INTO ";
    s += TABLE_USERS_NAME;
    s += "(login, password, degree) "
         "VALUES (:login, :password, :degree)";
    // Вставляем записи с помощью поименованного параметра, т.е. дробим запрос на части
    query.prepare(s);
    // Добавляем по частям к запросу значения
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.bindValue(":degree", degree);
    // Выполняем запрос
    query.exec();
}

// Возвращает спиок пользователей из базы
QList<User> DataBase::getUsers() {
    QString s = "SELECT login, password, degree FROM ";
    s += TABLE_USERS_NAME;
    query.exec(s);
    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");
    const int passwordIndex = rec.indexOf("password");
    const int degreeIndex = rec.indexOf("degree");

    QList<User> users = QList<User>();
    while (query.next()) {
        users.append(User(query.value(loginIndex).toString(), query.value(passwordIndex).toString(), query.value(degreeIndex).toInt()));
    }

    return users;
}

// Кол-во таблиц
int DataBase::getTablesCount() {
    return db.tables().count();
}

void DataBase::close() {
    query.exec();
    while (query.next()) {  }
    if (!query.next()) {
        query.finish();
        db.close();
        //база данных нужна чтобы хранить в ней данные а не удалять их к херам
        //в идеале нам нужно чтобы создалась БД и там были какие либо записи
     }
}

void DataBase::remove() {
    DataBase::close();
    // Удаление файла БД
    qDebug() << QFile::remove(DB_NAME);
}



