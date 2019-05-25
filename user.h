#ifndef USER_H
#define USER_H

#include <QString>

class User {
public:
    QString login;
    QString password;
    int degree;

    User(QString login, QString password, int degree) {
        this->login = login;
        this->password = password;
        this->degree = degree;
    }
};

#endif // USER_H
