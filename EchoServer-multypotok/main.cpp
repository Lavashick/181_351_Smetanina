#include <QCoreApplication>
#include "mytcpserver.h"
#include "someclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NewClass newClass;
    newClass.connected("0.0.0.0:8181");

    return a.exec();
}
