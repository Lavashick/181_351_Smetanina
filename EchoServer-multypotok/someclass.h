#ifndef SOMECLASS_H
#define SOMECLASS_H
#include <QObject>
#include <QDebug>

class NewClass: public QObject {
    Q_OBJECT
public:

    NewClass();

    void connected(QString str);

private slots:
    void slotNewConnection(QString str);
    void newConn();

signals:
    void newConnection(QString str);

};

#endif // SOMECLASS_H
