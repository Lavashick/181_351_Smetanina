#ifndef USERDEGREES_H
#define USERDEGREES_H

#include <QString>

enum UserDegrees {
    admin = 1,
    moderator = 2,
    user = 3
};

inline const char * UserDegreeToString(UserDegrees d)
{
    switch (d) {
    case admin:
        return "admin";
    case moderator:
        return "moderator";
    case user:
        return "user";
    }
}

inline UserDegrees UserDegreeFromString(QString d)
{
    QString lower = d.toLower();
    if (lower == "admin")
        return admin;
    if (lower == "moderator")
        return moderator;
    if (lower == "user")
        return user;
    return user;
}

#endif // USERDEGREES_H
