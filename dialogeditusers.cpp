#include "dialogeditusers.h"
#include "ui_dialogeditusers.h"
#include "dialogadmin.h"
#include "ui_dialogadmin.h"
#include "dialogeditusers.h"

DialogAdmin *prevDialog;

void DialogEditUsers::setData(QList<User> users)
{
    model2->clear();
    model2->setRowCount(users.count());
    model2->setColumnCount(3);
    model2->setHeaderData(0, Qt::Horizontal, "Login");
    model2->setHeaderData(1, Qt::Horizontal, "Password");
    model2->setHeaderData(2, Qt::Horizontal, "Degree");
    for (int row = 0; row < users.count(); row++)
    {
        QModelIndex index = model2->index(row, 0);
        QString indexValue = users.at(row).login;
        model2->setData(index, indexValue);

        index = model2->index(row, 1);
        indexValue = users.at(row).password;
        model2->setData(index, indexValue);

        index = model2->index(row, 2);
        indexValue = QString::number(users.at(row).degree);
        model2->setData(index, indexValue);
    }
}

DialogEditUsers::DialogEditUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditUsers)
{
    ui->setupUi(this);

    prevDialog = (DialogAdmin*)parent;

    QList<User> users = DataBase::getUsers();

    model2 = new QStandardItemModel(users.count(), 3, this);
    ui->tableView2->setModel(model2);

    setData(users);
}

DialogEditUsers::~DialogEditUsers()
{
    delete ui;
}

void DialogEditUsers::on_pushButton_7_clicked()
{
    this->hide();
    prevDialog->show();
}



void DialogEditUsers::on_searchButton_clicked()
{
}

void DialogEditUsers::on_lineEdit_textChanged(const QString &arg1)
{
    if (ui->lineEdit->text() == "") {
        setData(DataBase::getUsers());
        return;
    }
    QList<User> users = DataBase::getUsers();
    QString searchValue = ui->lineEdit->text();
    model2->clear();
    QString loginValue;

    QList<User> searchedUsers = QList<User>();

    foreach (User user, users) {
        if (user.login.toLower().contains(searchValue.toLower())) {
            searchedUsers.append(user);
        }
    }

    setData(searchedUsers);
}

void DialogEditUsers::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}
