#include <QCoreApplication>
#include "myserver.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    QCoreApplication a(argc, argv);

    MyServer server(8181);

    return a.exec();
}
