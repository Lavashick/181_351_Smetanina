#include "dialogcreateoreditdata.h"
#include "ui_dialogcreateoreditdata.h"
#include "dbservice.h"
#include <QMessageBox>

static QRegExp loginRx("[a-zA-Z][a-zA-Z0-9-_\\.]{1,10}");
static QRegExp passwordRx("((?=.*\\w)).{10,15}");

static QRegExp nameRx("[А-ЯA-Z].[а-яa-z]{2,15}");
static QRegExp ageRx("\\d{1,2}");

void DialogCreateOrEditData::configureCreateUserForm()
{
    ui->label_1->setText("Login");
    ui->lineEdit_1->setValidator(new QRegExpValidator(loginRx, this));
    ui->label_2->setText("Password");
    ui->lineEdit_2->setValidator(new QRegExpValidator(passwordRx, this));
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->label_3->setText("Repeat");
    ui->lineEdit_3->setValidator(new QRegExpValidator(passwordRx, this));
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    ui->label_4->setText("Degree");
    for (int i = 1; i <= 3; i++)
        ui->comboBox->addItem(UserDegreeToString(UserDegrees(i)));
    ui->change->setText("Create");
}

void DialogCreateOrEditData::configureCreateHumanForm()
{
    ui->label_1->setText("Name");
    ui->lineEdit_1->setValidator(new QRegExpValidator(nameRx, this));
    ui->label_2->setText("Last name");
    ui->lineEdit_2->setValidator(new QRegExpValidator(nameRx, this));
    ui->label_3->setText("Age");
    ui->lineEdit_3->setValidator(new QRegExpValidator(ageRx, this));
    ui->label_4->setText("Pansionat");
    QList<Pansionat> pansionats = DBService::getPansionats(false);
    for (int i = 0; i < pansionats.count(); i++)
        ui->comboBox->addItem(pansionats.at(i).title);
    ui->change->setText("Create");
}

void DialogCreateOrEditData::configureEditUserForm()
{
    ui->label_1->setText("Login");
    ui->lineEdit_1->setValidator(new QRegExpValidator(loginRx, this));
    ui->label_2->setText("Password");
    ui->lineEdit_2->setValidator(new QRegExpValidator(passwordRx, this));
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->label_3->setText("Repeat");
    ui->lineEdit_3->setValidator(new QRegExpValidator(passwordRx, this));
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    ui->label_4->setText("Degree");
    for (int i = 1; i <= 3; i++)
        ui->comboBox->addItem(UserDegreeToString(UserDegrees(i)));
    ui->comboBox->setCurrentIndex(user->degree - 1);
    ui->change->setText("Edit");
    ui->lineEdit_1->setText(user->login);
}

void DialogCreateOrEditData::configureEditHumanForm()
{
    ui->label_1->setText("Name");
    ui->lineEdit_1->setValidator(new QRegExpValidator(nameRx, this));
    ui->lineEdit_1->setText(human->firstName);
    ui->label_2->setText("Last name");
    ui->lineEdit_2->setValidator(new QRegExpValidator(nameRx, this));
    ui->lineEdit_2->setText(human->lastName);
    ui->lineEdit_3->setText(QString::number(human->age));
    ui->label_3->setText("Age");
    ui->lineEdit_3->setValidator(new QRegExpValidator(ageRx, this));
    ui->label_4->setText("Pansionat");
    QList<Pansionat> pansionats = DBService::getPansionats(false);
    for (int i = 0; i < pansionats.count(); i++)
    {
        ui->comboBox->addItem(pansionats.at(i).title);
        if (pansionats.at(i).id == human->pansionat->id)
            ui->comboBox->setCurrentIndex(i);
    }
    ui->change->setText("Edit");
}

DialogCreateOrEditData::DialogCreateOrEditData(CreateOrEditDataTypes type, User * user, Human * human, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreateOrEditData)
{
    this->parent = reinterpret_cast<DialogAdmin *>(parent);
    this->user = user;
    this->human = human;
    this->type = type;
    ui->setupUi(this);

    switch (type) {
    case createUserType:
        configureCreateUserForm();
        break;
    case createHumanType:
        configureCreateHumanForm();
        break;
    case editUserType:
        configureEditUserForm();
        break;
    case editHumanType:
        configureEditHumanForm();
        break;
    }
}

DialogCreateOrEditData::~DialogCreateOrEditData()
{
    delete ui;
}

void DialogCreateOrEditData::createUser()
{
    if (!loginRx.exactMatch(ui->lineEdit_1->text()))
    {
        QMessageBox::warning(this, "Incomplete data", "Invalid login!");
        return;
    }
    if (!passwordRx.exactMatch(ui->lineEdit_2->text()))
    {
        QMessageBox::warning(this, "Incomplete data", "Invalid password!");
        return;
    }
    if (ui->lineEdit_2->text() == ui->lineEdit_3->text())
    {
        QString login = ui->lineEdit_1->text();
        QString password = ui->lineEdit_2->text();
        int degree = UserDegreeFromString(ui->comboBox->currentText());
        if (!DBService::addUser(login, password, degree))
        {
            QMessageBox::warning(this, "DB Error", DBService::getLastError());
        } else {
            User * user = DBService::getUser(login);
            parent->users.append(*user);
            parent->updateUserTable();
            closeDialog();
        }
    } else {
        QMessageBox::warning(this, "Error", "Passwords don't match");
    }
}

void DialogCreateOrEditData::createHuman()
{
    QString firstName = ui->lineEdit_1->text();
    if (!nameRx.exactMatch(firstName))
    {
        QMessageBox::warning(this, "Incomplete data", "Invalid name!");
        return;
    }
    QString lastName = ui->lineEdit_2->text();
    if (!nameRx.exactMatch(lastName))
    {
        QMessageBox::warning(this, "Incomplete data", "Invalid last name!");
        return;
    }
    int age = ui->lineEdit_3->text().toInt();
    if (!ageRx.exactMatch(ui->lineEdit_3->text()))
    {
        QMessageBox::warning(this, "Incomplete data", "Invalid age!");
        return;
    }
    QString pansionat = ui->comboBox->currentText();
    if (!DBService::addHuman(firstName, lastName, age, pansionat))
    {
        QMessageBox::warning(this, "DB Error", DBService::getLastError());
    } else {
        Human human = DBService::getHumans(true, firstName, lastName).first();
        parent->humans.append(human);
        parent->updateHumanTable();
        closeDialog();
    }
}

void DialogCreateOrEditData::editUser()
{
    if (!loginRx.exactMatch(ui->lineEdit_1->text()))
    {
        QMessageBox::warning(this, "Incomplete data", "Invalid login!");
        return;
    }
    if (!passwordRx.exactMatch(ui->lineEdit_2->text()))
    {
        QMessageBox::warning(this, "Incomplete data", "Invalid password!");
        return;
    }
    if (ui->lineEdit_2->text() == ui->lineEdit_3->text())
    {
        QString login = ui->lineEdit_1->text();
        QString password = ui->lineEdit_2->text();
        int degree = UserDegreeFromString(ui->comboBox->currentText());
        if (!DBService::editUser(this->user->login, login, password, degree))
        {
            QMessageBox::warning(this, "DB Error", DBService::getLastError());
        } else {
            User * user = DBService::getUser(login);
            for (int i = 0; i < parent->users.count(); i++)
                if (parent->users.at(i).login == this->user->login)
                {
                    parent->users.replace(i, *user);
                    break;
                }
            parent->updateUserTable();
            closeDialog();
        }
    } else {
        QMessageBox::warning(this, "Error", "Passwords don't match");
    }
}

void DialogCreateOrEditData::editHuman()
{
    QString firstName = ui->lineEdit_1->text();
    if (!nameRx.exactMatch(firstName))
    {
        QMessageBox::warning(this, "Incomplete data", "Invalid name!");
        return;
    }
    QString lastName = ui->lineEdit_2->text();
    if (!nameRx.exactMatch(lastName))
    {
        QMessageBox::warning(this, "Incomplete data", "Invalid last name!");
        return;
    }
    int age = ui->lineEdit_3->text().toInt();
    if (!ageRx.exactMatch(ui->lineEdit_3->text()))
    {
        QMessageBox::warning(this, "Incomplete data", "Invalid age!");
        return;
    }
    QString pansionat = ui->comboBox->currentText();
    if (!DBService::editHuman(this->human->id, firstName, lastName, age, pansionat))
    {
        QMessageBox::warning(this, "DB Error", DBService::getLastError());
    } else {
        Human human = *DBService::getHuman(this->human->id, true);
        for (int i = 0; i < parent->humans.count(); i++)
            if (parent->humans.at(i).id == this->human->id)
            {
                parent->humans.replace(i, human);
                break;
            }
        parent->updateHumanTable();
        closeDialog();
    }
}

void DialogCreateOrEditData::on_change_clicked()
{
    switch (type) {
    case createUserType:
        createUser();
        break;
    case createHumanType:
        createHuman();
        break;
    case editUserType:
        editUser();
        break;
    case editHumanType:
        editHuman();
        break;
    }
}

void DialogCreateOrEditData::closeDialog()
{
    this->close();
}

void DialogCreateOrEditData::on_cancel_clicked()
{
    closeDialog();
}
