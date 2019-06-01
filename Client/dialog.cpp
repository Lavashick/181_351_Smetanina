#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QDebug>
#include "client.h"

static QSqlDatabase myDB;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_enterBtn_clicked()
{
    QString login, password;
    login = ui->loginTxt->text();
    password = ui->passwordTxt->text();

    if (login.isEmpty() && password.isEmpty())
    {
        QMessageBox::warning(this, "Incomplete data", "Login and password are empty!");
        return;
    }
    if (password.isEmpty())
    {
        QMessageBox::warning(this, "Incomplete data", "Password is empty!");
        return;
    }
    if (login.isEmpty())
    {
        QMessageBox::warning(this, "Incomplete data", "Login is empty!");
        return;
    }
    if (DBService::checkUser(login, password)) {
        user = DBService::getUser(login);
        QMessageBox::information(this, "Successfully", "You are logged in as a " + login + "!");
        window = new DialogAdmin(user, this);
        window->show();
    }
    else if (!Client::isConnected())
        QMessageBox::warning(this, "Failure", "Server isn't connected");
    else
    {
        resetPasswordField();
        QMessageBox::warning(this, "Failure", "Wrong login or password!");
    }
}

void Dialog::resetPasswordField() {
    ui->passwordTxt->setText("");
}

void Dialog::on_clearBtn_clicked()
{
    ui->loginTxt->setText("");
    ui->passwordTxt->setText("");
}
