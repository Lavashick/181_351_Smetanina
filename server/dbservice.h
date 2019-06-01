#ifndef DBSERVICE_H
#define DBSERVICE_H

#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QFile>
#include <QSqlResult>

/**
 * @brief Работа Сервера с БД
 */
class DBService
{
public:
    /**
     * @brief Подключение сервера к БД
     */
    static bool connect();
    /**
     * @brief Проверка на создание БД
     */
    static bool isCreated();
    /**
     * @brief Удаление БД
     */
    static void remove();
    /**
     * @brief Закрытие БД
     */
    static void close();
    static QByteArray execute(QString query);
};

#endif // DBSERVICE_H
