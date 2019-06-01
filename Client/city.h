#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

class City
{
public:
    City(QJsonObject json);

    int id;
    QString title;
};

#endif // CITY_H
