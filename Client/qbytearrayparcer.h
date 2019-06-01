#ifndef QBYTEARRAYPARCER_H
#define QBYTEARRAYPARCER_H

#include <QString>
#include <QJsonDocument>
#include <QJsonArray>

/**
 * @brief Перевод данных QByteArray
 */
class QByteArrayParcer
{
public:
    static QString toString(QByteArray bytes);
    static QJsonArray * toJsonArray(QByteArray bytes);
    static QByteArray stringToBytes(QString string);
};

#endif // QBYTEARRAYPARCER_H
