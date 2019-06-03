#include "dialogadmin.h"
#include "ui_dialogadmin.h"
#include "dialog.h"
#include "dialogcreateoreditdata.h"

void DialogAdmin::updateUserTable()
{
    model->clear();
    model->setRowCount(users.count());
    model->setColumnCount(3);
    model->setHeaderData(0, Qt::Horizontal, "Login");
    model->setHeaderData(1, Qt::Horizontal, "Password");
    model->setHeaderData(2, Qt::Horizontal, "Degree");
    for (int row = 0; row < users.count(); row++)
    {
        QModelIndex index = model->index(row, 0);
        QString indexValue = users.at(row).login;
        model->setData(index, indexValue);

        index = model->index(row, 1);
        indexValue = users.at(row).password;
        model->setData(index, indexValue);

        index = model->index(row, 2);
        indexValue = UserDegreeToString(users.at(row).degree);
        model->setData(index, indexValue);
    }
}

void DialogAdmin::updateHumanTable()
{
    model->clear();
    model->setRowCount(humans.count());
    model->setColumnCount(5);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Имя");
    model->setHeaderData(2, Qt::Horizontal, "Фамилия");
    model->setHeaderData(3, Qt::Horizontal, "Возраст");
    model->setHeaderData(4, Qt::Horizontal, "Пансионат");
    for (int row = 0; row < humans.count(); row++)
    {
        QModelIndex index = model->index(row, 0);
        QString indexValue = QString::number(humans.at(row).id);
        model->setData(index, indexValue);

        index = model->index(row, 1);
        indexValue = humans.at(row).firstName;
        model->setData(index, indexValue);

        index = model->index(row, 2);
        indexValue = humans.at(row).lastName;
        model->setData(index, indexValue);

        index = model->index(row, 3);
        indexValue = QString::number(humans.at(row).age);
        model->setData(index, indexValue);

        index = model->index(row, 4);
        indexValue = humans.at(row).pansionat->title;
        model->setData(index, indexValue);
    }
}

DialogAdmin::DialogAdmin(User * user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdmin)
{
    this->user = user;
    parent->hide();
    // Создание таблицы
    ui->setupUi(this);
    model = new QStandardItemModel(0, 0, this);
    configure();
    ui->tableView->setModel(model);
}

DialogAdmin::~DialogAdmin()
{
    delete ui;
}

void DialogAdmin::configure() {
    switch (user->degree) {
    //
    case UserDegrees::admin:
        users = DBService::getUsers();
        tempUsers = users;
        updateUserTable();
        ui->editButton->setText("Add user");
        break;
    case UserDegrees::moderator:
        humans = DBService::getHumans(true);
        tempHumans = humans;
        updateHumanTable();
        ui->editButton->setText("Add human");
        break;
    case UserDegrees::user:
        humans = DBService::getHumans(true);
        tempHumans = humans;
        updateHumanTable();
        ui->editButton->hide();
        ui->deleting->hide();
        break;
    }
}

void DialogAdmin::on_deleting_clicked()
{
    int rowIndex = ui->tableView->selectionModel()->currentIndex().row();
    if (user->degree == admin)
    {
        QString login = model->index(rowIndex, 0).data().toString();
        users.removeAt(rowIndex);
        updateUserTable();
        DBService::deleteUser(login);
    } else {
        int id = model->index(rowIndex, 0).data().toInt();
        humans.removeAt(rowIndex);
        updateHumanTable();
        DBService::deleteHuman(id);
    }
}

void DialogAdmin::on_close_clicked()
{
    this->close();
    this->user = nullptr;
    Dialog * parent = reinterpret_cast<Dialog *>(this->parentWidget());
    parent->resetPasswordField();
    parent->show();
}

void DialogAdmin::on_searchButton_clicked()
{
}

void DialogAdmin::on_updateButton_clicked()
{
    if (user->degree == admin) {
        users = DBService::getUsers();
        updateUserTable();
    } else {
        humans = DBService::getHumans(true);
        updateHumanTable();
    }
}

void DialogAdmin::on_searchEdit_textChanged(const QString &arg1)
{
    QString str = ui->searchEdit->text().toLower();
    if (str.isEmpty())
    {
        if (user->degree == admin) {
            users = tempUsers;
            updateUserTable();
        } else {
            humans = tempHumans;
            updateHumanTable();
        }
    } else {
        if (user->degree == admin) {
            users.clear();
            for (int i = 0; i < tempUsers.count(); ++i) {
                if (tempUsers.at(i).login.toLower().contains(str))
                    users.append(tempUsers.at(i));
            }
            updateUserTable();
        } else {
            humans.clear();
            for (int i = 0; i < tempHumans.count(); ++i) {
                if (tempHumans.at(i).firstName.toLower().contains(str))
                    humans.append(tempHumans.at(i));
            }
            updateHumanTable();
        }
    }
}

#include "human.h"

void DialogAdmin::on_tableView_doubleClicked(const QModelIndex &index)
{
    DialogCreateOrEditData * dialog;
    if (users.isEmpty())
    {
        dialog = new DialogCreateOrEditData(editHumanType, nullptr, new Human(humans.at(index.row())), this);
    } else
    {
        dialog = new DialogCreateOrEditData(editUserType, new User(users.at(index.row())), nullptr, this);
    }
    dialog->show();
}

void DialogAdmin::on_editButton_clicked()
{
    DialogCreateOrEditData * dialog;
    if (users.isEmpty())
    {
        dialog = new DialogCreateOrEditData(createHumanType, nullptr, nullptr, this);
    } else
    {
        dialog = new DialogCreateOrEditData(createUserType, nullptr, nullptr, this);
    }
    dialog->show();
}
