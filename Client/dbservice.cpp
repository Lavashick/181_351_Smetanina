#include "dbservice.h"
#include "client.h"
#include "qbytearrayparcer.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QJsonDocument>
#include "hash.h"

#define TABLE_USERS_NAME "users"
#define TABLE_HUMANS_NAME "humans"
#define TABLE_PANSIONATS_NAME "pansionats"
#define TABLE_CITIES_NAME "cities"
#define TABLE_PANSIONAT_CITY_NAME "pansionat_city"
#define TABLE_HUMAN_PANSIONAT_NAME "human_pansionat"

// Создание таблицы юзеров
bool DBService::createTableUsers()
{
    QString s = QString("CREATE TABLE %1(\n"
         "'login' VARCHAR(30) NOT NULL UNIQUE,\n"
         "'password' VARCHAR(128) NOT NULL,\n"
         "'degree' INT NOT NULL DEFAULT 3\n"
         ")").arg(TABLE_USERS_NAME);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    if (QByteArrayParcer::toJsonArray(*response) == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    return true;
}

bool DBService::createTableCities()
{
    QString s = QString("CREATE TABLE %1 (\n"
         "'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,\n"
         "'title' TEXT NOT NULL\n"
         ")").arg(TABLE_CITIES_NAME);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    if (QByteArrayParcer::toJsonArray(*response) == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    return true;
}

bool DBService::createTablePansionats()
{
    QString s = QString("CREATE TABLE %1 (\n"
         "'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,\n"
         "'title' TEXT NOT NULL\n"
         ")").arg(TABLE_PANSIONATS_NAME);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    if (QByteArrayParcer::toJsonArray(*response) == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    return true;
}

bool DBService::createTableHumans()
{
    QString s = QString("CREATE TABLE %1(\n"
         "'id' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,\n"
         "'first_name' TEXT NOT NULL,\n"
         "'last_name' TEXT NOT NULL,\n"
         "'age' INTEGER NOT NULL\n"
         ")").arg(TABLE_HUMANS_NAME);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    if (QByteArrayParcer::toJsonArray(*response) == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    return true;
}

bool DBService::createTablePansionatCity()
{
    QString s = QString("CREATE TABLE %1(\n"
                        "'pansionat_id' INTEGER NOT NULL UNIQUE,\n"
                        "'city_id' INTEGER NOT NULL,\n"
                        "FOREIGN KEY('pansionat_id') REFERENCES 'pansionats'('id'),\n"
                        "FOREIGN KEY('city_id') REFERENCES 'cities'('id')\n"
                        ")").arg(TABLE_PANSIONAT_CITY_NAME);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    if (QByteArrayParcer::toJsonArray(*response) == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    return true;
}

bool DBService::createTableHumanPansionat()
{
    QString s = QString("CREATE TABLE %1(\n"
                        "'human_id' INTEGER NOT NULL UNIQUE,\n"
                        "'pansionat_id' INTEGER NOT NULL,\n"
                        "FOREIGN KEY('pansionat_id') REFERENCES 'pansionats'('id'),\n"
                        "FOREIGN KEY('human_id') REFERENCES 'humans'('id')\n"
                        ")").arg(TABLE_HUMAN_PANSIONAT_NAME);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    if (QByteArrayParcer::toJsonArray(*response) == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    return true;
}

// Проверка на соответствие логина и пароля у юзеров
bool DBService::checkUser(QString login, QString password)
{
    QString s = QString("SELECT * FROM %1\n WHERE login = '%2' AND password = '%3'").arg(TABLE_USERS_NAME).arg(login).arg(Hash::start(password));
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    if (array->isEmpty())
        return false;
    return true;
}

// Возвращает 1 пользователя, найденного по логину
User * DBService::getUser(QString login)
{
    QString s = QString("SELECT * FROM %1 WHERE login = '%2'").arg(TABLE_USERS_NAME).arg(login);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return nullptr;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return nullptr;
    }
    if (array->isEmpty())
        return nullptr;
    return new User(array->first().toObject());
}

City * DBService::getCity(int id)
{
    QString s = QString("SELECT * FROM %1 WHERE id = %2").arg(TABLE_CITIES_NAME).arg(id);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return nullptr;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return nullptr;
    }
    if (array->isEmpty())
        return nullptr;
    return new City(array->first().toObject());
}

Pansionat * DBService::getPansionat(int id)
{
    QString s = QString("SELECT * FROM %1 WHERE id = %2").arg(TABLE_PANSIONATS_NAME).arg(id);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return nullptr;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return nullptr;
    }
    if (array->isEmpty())
        return nullptr;
    return new Pansionat(array->first().toObject());
}

bool DBService::deleteUser(QString login)
{
    QString s = QString("DELETE FROM %1 WHERE login = %2").arg(TABLE_USERS_NAME).arg(login);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    return true;
}

// Добавление нового пользователя
bool DBService::addUser(QString login, QString password, int degree)
{
    QString s = QString("INSERT INTO %1 VALUES ('%2', '%3', %4)").arg(TABLE_USERS_NAME).arg(login).arg(Hash::start(password)).arg(degree);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr) {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    return true;
}

bool DBService::addCity(QString title)
{
    QString s = QString("INSERT INTO %1 VALUES (NULL, '%2')").arg(TABLE_CITIES_NAME).arg(title);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    return true;
}

bool DBService::addPansionat(QString title, QString fromCity)
{
    // Поиск города
    QString f = QString("SELECT * FROM %1 WHERE title = '%2'").arg(TABLE_CITIES_NAME).arg(fromCity);
    QByteArray * response1 = Client::sendData(f);
    if (response1 == nullptr)
        return false;

    QJsonArray * array1 = QByteArrayParcer::toJsonArray(*response1);
    if (array1 == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response1);
        return false;
    }
    if (array1->count() == 0)
        return false;

    City city = City(array1->last().toObject());

    // Сохранение пансионата
    QString s = QString("INSERT INTO %1 VALUES (NULL, '%2')").arg(TABLE_PANSIONATS_NAME).arg(title);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr) {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }

    // Возврат объекта пансионата из БД
    QString v = QString("SELECT * FROM %1").arg(TABLE_PANSIONATS_NAME);
    QByteArray * response2 = Client::sendData(v);
    if (response2 == nullptr)
        return false;

    QJsonArray * array2 = QByteArrayParcer::toJsonArray(*response2);
    if (array2 == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response2);
        return false;
    }
    if (array2->count() == 0)
        return false;

    Pansionat pansionat = Pansionat(array2->last().toObject());

    // Сохранение пансионата
    QString b = QString("INSERT INTO %1 VALUES ('%2', '%3')").arg(TABLE_PANSIONAT_CITY_NAME).arg(pansionat.id).arg(city.id);
    QByteArray * response4 = Client::sendData(b);
    if (response4 == nullptr)
        return false;
    QJsonArray * array4 = QByteArrayParcer::toJsonArray(*response4);
    if (array4 == nullptr) {
        qDebug() << QByteArrayParcer::toString(*response4);
        return false;
    }

    return true;
}

bool DBService::addHuman(QString firstName, QString lastName, int age, QString fromPansionat)
{
    // Поиск пансионата
    QString f = QString("SELECT * FROM %1 WHERE title='%2'").arg(TABLE_PANSIONATS_NAME).arg(fromPansionat);
    QByteArray * response1 = Client::sendData(f);
    if (response1 == nullptr)
        return false;

    QJsonArray * array1 = QByteArrayParcer::toJsonArray(*response1);
    if (array1 == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response1);
        return false;
    }
    if (array1->count() == 0)
        return false;

    Pansionat pansionat = Pansionat(array1->last().toObject());

    // Сохранение человека
    QString s = QString("INSERT INTO %1 VALUES (NULL, '%2', '%3', %4)").arg(TABLE_HUMANS_NAME).arg(firstName).arg(lastName).arg(age);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr) {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }

    // Возврат человека из БД
    QString v = QString("SELECT * FROM %1").arg(TABLE_HUMANS_NAME);
    QByteArray * response2 = Client::sendData(v);
    if (response2 == nullptr)
        return false;

    QJsonArray * array2 = QByteArrayParcer::toJsonArray(*response2);
    if (array2 == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response2);
        return false;
    }
    if (array2->count() == 0)
        return false;

    Human human = Human(array2->last().toObject());

    // Сохранение пансионата
    QString b = QString("INSERT INTO %1 VALUES ('%2', '%3')").arg(TABLE_HUMAN_PANSIONAT_NAME).arg(human.id).arg(pansionat.id);
    QByteArray * response4 = Client::sendData(b);
    if (response4 == nullptr)
        return false;
    QJsonArray * array4 = QByteArrayParcer::toJsonArray(*response4);
    if (array4 == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response4);
        return false;
    }

    return true;
}

// Возвращает спиок пользователей из базы
QList<User> DBService::getUsers(QString login)
{
    QString s = QString("SELECT * FROM %1").arg(TABLE_USERS_NAME);
    if (!login.isEmpty())
        s += QString(" WHERE login = %1").arg(login);

    QList<User> users = QList<User>();

    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return users;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return users;
    }
    for (int i = 0; i < array->count(); i++)
        users.append(User(array->at(i).toObject()));
    return users;
}

QList<Human> DBService::getHumans(bool isWithPansionats, QString firstName, QString lastName)
{
    QString s = QString("SELECT * FROM %1").arg(TABLE_HUMANS_NAME);
    if (!firstName.isEmpty()) {
        s += QString(" WHERE first_name = %1").arg(firstName);
        if (!lastName.isEmpty())
            s += QString(", last_name = %1").arg(lastName);
    } else if (!lastName.isEmpty())
        s += QString(" WHERE last_name = %1").arg(lastName);
    Client::sendData(s);

    QList<Human> humans = QList<Human>();

    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return humans;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return humans;
    }
    for (int i = 0; i < array->count(); i++)
    {
        Human human = Human(array->at(i).toObject());

        if (isWithPansionats)
        {
            s = QString("SELECT %1.id, %1.title FROM %1, %2 \nWHERE %2.pansionat_id = %1.id AND %2.human_id = %3").arg(TABLE_PANSIONATS_NAME).arg(TABLE_HUMAN_PANSIONAT_NAME).arg(human.id);
            response = Client::sendData(s);
            QJsonArray * newArray = QByteArrayParcer::toJsonArray(*response);
            if (newArray == nullptr)
                qDebug() << QByteArrayParcer::toString(*response);

            Pansionat * pansionat = new Pansionat(newArray->first().toObject());
            human.pansionat = pansionat;
        }

        humans.append(human);
    }
    return humans;
}

QList<City> DBService::getCities(QString title)
{
    QString s = QString("SELECT * FROM %1").arg(TABLE_CITIES_NAME);
    if (!title.isEmpty())
        s += QString(" WHERE title = %1").arg(title);
    Client::sendData(s);

    QList<City> cities = QList<City>();

    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return cities;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return cities;
    }
    for (int i = 0; i < array->count(); i++)
        cities.append(City(array->at(i).toObject()));
    return cities;
}

QList<Pansionat> DBService::getPansionats(bool isWithCities, QString title)
{
    QString s = QString("SELECT * FROM %1").arg(TABLE_PANSIONATS_NAME);
    if (!title.isEmpty())
        s += QString(" WHERE title = %1").arg(title);
    Client::sendData(s);

    QList<Pansionat> pansionats = QList<Pansionat>();

    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return pansionats;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return pansionats;
    }
    for (int i = 0; i < array->count(); i++) {
        Pansionat pansionat = Pansionat(array->at(i).toObject());

        if (isWithCities)
        {
            s = QString("SELECT %1.id, %1.title FROM %1, %2 WHERE %2.city_id = %1.id AND %2.pansionat_id = %3").arg(TABLE_CITIES_NAME).arg(TABLE_PANSIONAT_CITY_NAME).arg(pansionat.id);
            response = Client::sendData(s);
            QJsonArray * newArray = QByteArrayParcer::toJsonArray(*response);
            if (newArray == nullptr)
                qDebug() << QByteArrayParcer::toString(*response);

            City * city = new City(newArray->first().toObject());
            pansionat.city = city;
        }

        pansionats.append(pansionat);
    }

    return pansionats;
}

bool DBService::deleteHuman(int id)
{
    QString s = QString("DELETE FROM %1 WHERE human_id = %2").arg(TABLE_HUMAN_PANSIONAT_NAME).arg(id);
    QByteArray * response = Client::sendData(s);
    if (response == nullptr)
        return false;
    QJsonArray * array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }

    s = QString("DELETE FROM %1 WHERE id = %2").arg(TABLE_HUMANS_NAME).arg(id);
    response = Client::sendData(s);
    if (response == nullptr)
        return false;
    array = QByteArrayParcer::toJsonArray(*response);
    if (array == nullptr)
    {
        qDebug() << QByteArrayParcer::toString(*response);
        return false;
    }
    return true;
}
