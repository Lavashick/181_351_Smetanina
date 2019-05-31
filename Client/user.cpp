#include "user.h"

User::User(QString login, QString password, int degree) {
    this->login = login;
    this->password = password;
    this->degree = degree;
}

User::User(QJsonObject json) {
    this->login = json.value("login").toString();
    this->password = json.value("password").toString();
    this->degree = json.value("degree").toInt();
}
