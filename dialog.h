#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include "dialogadmin.h"
#include "DataBase.h"
#include <QTcpSocket>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    User *user = NULL;

    void resetPasswordField();
    void send_to_server(QString message);
    QTcpSocket * clientSocket;

signals:
    void goToDialogAdmin(QByteArray array);
private slots:
    void on_enterBtn_clicked();
    void slot_read();     // здесь мы делаем слот для чтения того что приходит с сервера
    void on_clearBtn_clicked();
    void slot_connected();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    DialogAdmin *window;
     //нахуя это здесь? чтоб ссылка на сокет не терялась. сокет - грубо говоря канал связи с сервером.
    //если мы не собъявим в классе, что он у нас должен храниться - мы проебем ссылку на канал связи и не сможем передать сообщение.
    // тупа как я, когда умудряюсь заблудиться на электро. наше сообщение будет пускать слюни и не понимать что за клиент сокет который мы везде пишем


};

#endif // DIALOG_H
