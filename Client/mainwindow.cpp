#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbservice.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    client.connectToHost("127.0.0.1", 8181);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int str = ui->lineEdit->text().toInt();
    if (!Client::isConnected())
        Client::connectToHost("127.0.0.1", 8181);
    switch (str) {
    case 0:
        if (DBService::createTableUsers())
            qDebug() << "Talbe is create";
        else
            qDebug() << "Talbe isn't create";
        break;
    case 1:
        if (DBService::checkUser("admin", "admin"))
            qDebug() << "User created";
        else
            qDebug() << "User DONT created";
        break;
    case 2:
        DBService::addUser("some", "some", 3);
        break;
    case 3: {
        QList<User> users = DBService::getUsers();
        for (int i = 0; i < users.count(); i++) {
            qDebug() << users.at(i).login;
        }
        break; }
    case 4: {
        User * user = DBService::getUser("some");
        if (user != nullptr)
            qDebug() << user->login;
        else
            qDebug() << "User didn't created";
        break; }
    default:
        break;
    }
}
