#ifndef QSERVETHREAD_H
#define QSERVETHREAD_H
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class QServethread : public QThread
{
    Q_OBJECT
public:
    explicit QServethread(int descriptor,QObject *parent = 0);
    ~QServethread();
    void run();
signals:

public slots:
    void slotServerRead();
    void slotClientDisconnected();
private:
    int socketDescriptor;
    QTcpSocket* socket;
};

#endif // QSERVETHREAD_H
