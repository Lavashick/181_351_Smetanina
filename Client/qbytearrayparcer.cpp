#include "qbytearrayparcer.h"

QString QByteArrayParcer::toString(QByteArray bytes)
{
    return QString::fromStdString(bytes.toStdString());
}

QJsonArray * QByteArrayParcer::toJsonArray(QByteArray bytes)
{
    QJsonDocument json = QJsonDocument::fromJson(bytes);
    if (!json.isArray())
        return nullptr;
    else
        return new QJsonArray(json.array());
}
