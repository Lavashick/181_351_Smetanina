#ifndef CONSOLE_H
#define CONSOLE_H

#include <QDebug>
#include <QString>

class Console
{
public:
    static void writeWithTime(QString msg, bool withQuote = false);
    static void write(QString msg, bool withQuote = false);
    Console();
};

#endif // CONSOLE_H
