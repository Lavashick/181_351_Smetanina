#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

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
    // Подключение к серверу
    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost("127.0.0.1", 33333);
    connect(clientSocket,SIGNAL( connected () ),this,SLOT( slot_connected () ) );
    connect(clientSocket,SIGNAL(readyRead()), this, SLOT(slot_read()));
    //чем раньше тем лучше
    bool isCorrectWindow = 0;
    QString login, password;
    login = ui->loginTxt->text();
    password = ui->passwordTxt->text();


    send_to_server("auth&"+login+"&"+password);

    //в этом месте он отправляет логин и пароль из формы серверу
/*
    qDebug() << ((DataBase::checkUser(login, password)) ? "YES" : "NO");

    if (login == "" && password == "")
        QMessageBox::warning(this, "Incomplete data", "Login and password are empty!");
    if (password == "")
        QMessageBox::warning(this, "Incomplete data", "Password is empty!");
    if (login == "")
        QMessageBox::warning(this, "Incomplete data", "Login is empty!");
    if (login != "" && password != "") {
        if (DataBase::checkUser(login, password)) {
            QMessageBox::information(this, "Successfully", "You are logged in as a " + login + "!");
            isCorrectWindow = 1;
        }
        else
            QMessageBox::warning(this, "Failure", "Wrong login or password!");
    }
    if (isCorrectWindow) {
        window = new DialogAdmin(this);
        window->user = DataBase::getUser(login);
        window->configure();
        window->show();
    }*/




}


void Dialog::resetPasswordField() {
    ui->passwordTxt->setText("");
}

void Dialog::on_clearBtn_clicked()
{
    ui->loginTxt->setText("");
    ui->passwordTxt->setText("");
}


// ОТПРАВЛЯЕТ НА СЕРВЕР

void Dialog::send_to_server(QString message)
{
    QByteArray array; // шо это говно делает. мы не можем отправить данные  чисто в строке
    // общение у нас происходит на кубайтарраевском. потому что это байтовые массивы нулей и единиц, короче вот так вот.
    //эта маленькая функция автоматизирует процесс отправки серверу всего дерьма, что нужно ему отправить
    array.append(message);
    clientSocket->write(array);// то что мы отправляем. в виде Qstring
    // теперь он всегда знает куда отправлять те пакеты говна что мы называем данными
}



// ТО, ЧТО ПРИХОДИТ ОТ СЕРВЕРА

void Dialog::slot_read()
{
    while(clientSocket->bytesAvailable()>0){
        QByteArray array;
        array = clientSocket->readAll();
        QList <QByteArray> all = array.split('&');
        if (all[0] == "authAnswer"){
            if (all [1] != ""){
            window = new DialogAdmin(this, all[1], clientSocket); // открываем окно
            window -> show();
            }
        }
        else if (all[0] == "selectAnswer") {
            emit goToDialogAdmin(array);
        }
    }
}
void Dialog::slot_connected(){

}
