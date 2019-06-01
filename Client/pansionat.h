#ifndef PANSIONAT_H
#define PANSIONAT_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include "city.h"

class Pansionat
{
public:
    Pansionat(QJsonObject json);

    int id;
    QString title;

    City * city = nullptr;
};

#endif // PANSIONAT_H
