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
    User(QJsonObject json);

    QString login;
    QString password;
    int degree;
};


#endif // USER_H
