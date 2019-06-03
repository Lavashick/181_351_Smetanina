#ifndef DBSERVICE_H
#define DBSERVICE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QList>
#include "user.h"
#include "human.h"
#include "city.h"
#include "pansionat.h"

/**
 * @brief Работа сервера с БД
 */
class DBService
{
public:
    /**
     * @brief Создание таблицы юзеров
     */
    static bool createTableUsers();

    static bool createTableCities();
    static bool createTableHumans();
    static bool createTablePansionats();

    static bool createTablePansionatCity();
    static bool createTableHumanPansionat();
    /**
     * @brief Добавление юзера
     */
    static bool addUser(QString login, QString password, int degree);
    static bool addCity(QString title);
    static bool addPansionat(QString title, QString fromCity);
    static bool addHuman(QString firstName, QString lastName, int age, QString fromPansionat);
    /**
     * @brief Проверка параметров юзера
     */
    static bool checkUser(QString login, QString password);
    /**
     * @brief Запросить пользователя по определенному логину
     */
    static User * getUser(QString login);
    static Human * getHuman(int id, bool isWithPansionat = false);
    static City * getCity(int id);
    static Pansionat * getPansionat(int id);
    /**
     * @brief Удаление пользователя
     */
    static bool deleteUser(QString login);
    static bool deleteHuman(int id);
    static bool deleteCity(int id);
    static bool deletePansionat(int id);
    /**
     * @brief Запрашивает всех юзеров из БД
     */
    static QList<User> getUsers( QString login = "" );
    static QList<Human> getHumans( bool isWithPansionats = false, QString firstName = "", QString lastName = "" );
    static QList<City> getCities( QString title = "" );
    static QList<Pansionat> getPansionats( bool isWithCities = false, QString title = "" );

    static bool editUser(QString login, QString newLogin, QString newPassword, int newDegree);
    static bool editHuman(int id, QString newName, QString newLastName, int newAge, QString newPansionat);

    static QString getLastError();
};

#endif // DBSERVICE_H
