#ifndef USER_H
#define USER_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

/**
 * @brief Класс пользователей
 */
class User {
public:
    QString login;
    QString password;
    int degree;

    User(QString login, QString password, int degree);
    User(QJsonObject json);
};


#endif // USER_H
