#include "console.h"
#include <QDateTime>

QString getCurrentDate()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    int year = dateTime.date().year();
    int month = dateTime.date().month();
    int day = dateTime.date().day();
    return QString("%1.%2.%3").arg(day).arg(month).arg(year);
}

QString getCurrentTime()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    return dateTime.time().toString();
}

void Console::writeWithTime(QString msg, bool withQuote)
{
    QDebug debug = qDebug();
    if (!withQuote)
        debug = debug.noquote();
    debug << QString("%1: %2").arg(getCurrentTime()).arg(msg);
}

void Console::write(QString msg, bool withQuote) {
    QDebug debug = qDebug();
    if (!withQuote)
        debug = debug.noquote();
    debug << msg;
}
