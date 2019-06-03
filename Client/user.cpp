#include "user.h"

User::User(QJsonObject json) {
    this->login = json.value("login").toString();
    this->password = json.value("password").toString();
    int degree = json.value("degree").toInt();
    switch (degree) {
    case 1:
        this->degree = admin;
        break;
    case 2:
        this->degree = moderator;
        break;
    case 3:
        this->degree = user;
        break;
    }
}
