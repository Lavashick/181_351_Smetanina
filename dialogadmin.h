#ifndef DIALOGADMIN_H
#define DIALOGADMIN_H

#include <QDialog>
#include "DataBase.h"
#include <QStandardItemModel>
#include <QByteArray>
#include <QTcpSocket>

namespace Ui {
class DialogAdmin;
}

class DialogAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdmin(QWidget *parent = nullptr, QByteArray degree = nullptr, QTcpSocket *clientSocketOfParent = nullptr);
    ~DialogAdmin();
    User* user;

    void configure();
    void selectAnswer(QList <QByteArray> shit);
    QStandardItemModel* tableDB;

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_refreshTable_clicked();

    void send_to_server(QString message);

    void readDialogAdmin (QByteArray array);

private:
    Ui::DialogAdmin *ui;
    QStandardItemModel *model;
    int degreeOfUser;
    QTcpSocket *clientSocket;
};

#endif // DIALOGADMIN_H
