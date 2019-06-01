#include "dbservice.h"

#define DB_NAME "db.sqlite"
#define DB_DRIVER "QSQLITE"
#define DB_CONNECTION_NAME "connect"

#include "console.h"

static QSqlDatabase db;
static QSqlQuery queryQueue;

#include <QSqlResult>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

// Подключение базы данных
bool DBService::connect() {
    if (!isCreated())
        Console::writeWithTime("DataBase was created");
    // Создание Базы данных типа QSQLite
    // QSQLite - драйвер в Qt
    db = QSqlDatabase::addDatabase(DB_DRIVER, DB_CONNECTION_NAME);
    // Задаем имя базе данных:
    db.setDatabaseName(DB_NAME);

    queryQueue = QSqlQuery(db);

    // Если не открывает нашу бд, то выводим последнюю ошибку:
    if(!db.open()) {
        Console::writeWithTime("DataBase wasn't opened");
        Console::writeWithTime(db.lastError().text());
    }
    else
        Console::writeWithTime("DataBase was opened");
    return db.isOpen();
}

bool DBService::isCreated() {
    return QFile::exists(DB_NAME);
}

QByteArray DBService::execute(QString query) {
    queryQueue.exec(query);

    if (queryQueue.lastError().isValid()) {
        QString error = "Error: " + queryQueue.lastError().text();
        QByteArray bytes;
        bytes.append(error);
        return bytes;
    }

    QJsonDocument json;
    QJsonArray recordsArray;

    while(queryQueue.next()) {
        QJsonObject recordObject;
        for (int i = 0; i < queryQueue.record().count(); i++) {
            recordObject.insert(queryQueue.record().fieldName(i), QJsonValue::fromVariant(queryQueue.value(i)));
        }
        recordsArray.push_back(recordObject);
    }
    json.setArray(recordsArray);
    return json.toJson();
}

void DBService::close() {
    queryQueue.exec();
    while (queryQueue.next()) {  }
    if (!queryQueue.next()) {
        queryQueue.finish();
        db.close();
    }
}

void DBService::remove() {
    DBService::close();
    // Удаление файла БД
    if(QFile::remove(DB_NAME))
        Console::writeWithTime("DataBase was deleted");
}
