#ifndef CONSOLE_H
#define CONSOLE_H

#include <QDebug>
#include <QString>

/**
 * @brief Класс работы с консолью
 */
class Console
{
public:
    static void writeWithTime(QString msg, bool withQuote = false);
    static void write(QString msg, bool withQuote = false);
    Console();
};

#endif // CONSOLE_H
