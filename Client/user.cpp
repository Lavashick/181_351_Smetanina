#include "user.h"

User::User(QJsonObject json) {
    this->login = json.value("login").toString();
    this->password = json.value("password").toString();
    this->degree = json.value("degree").toInt();
}
