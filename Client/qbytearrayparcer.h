#ifndef QBYTEARRAYPARCER_H
#define QBYTEARRAYPARCER_H

#include <QString>
#include <QJsonDocument>
#include <QJsonArray>

class QByteArrayParcer
{
public:
    static QString toString(QByteArray bytes);
    static QJsonArray * toJsonArray(QByteArray bytes);
};

#endif // QBYTEARRAYPARCER_H
