#ifndef HUMAN_H
#define HUMAN_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include "pansionat.h"

class Human
{
public:
    Human(QJsonObject json);

    int id;
    QString firstName;
    QString lastName;
    int age;

    Pansionat * pansionat = nullptr;
};

#endif // HUMAN_H
