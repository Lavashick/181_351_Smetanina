#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include "dialogadmin.h"
#include "dbservice.h"
#include "user.h"
#include "dialogadmin.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    User *user = nullptr;
    void resetPasswordField();

private slots:
    void on_enterBtn_clicked();
    void on_clearBtn_clicked();

private:
    Ui::Dialog *ui;
    DialogAdmin *window;
    Dialog *prevDialog;

};

#endif // DIALOG_H
