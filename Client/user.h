#ifndef USER_H
#define USER_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include "userdegrees.h"

/**
 * @brief Класс пользователей
 */
class User {
public:
    User(QJsonObject json);

    QString login;
    QString password;
    UserDegrees degree;
};


#endif // USER_H
