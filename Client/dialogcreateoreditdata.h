#ifndef DIALOGCREATEOREDITDATA_H
#define DIALOGCREATEOREDITDATA_H

#include <QDialog>
#include "dialogadmin.h"
#include "createoreditdatatypes.h"

namespace Ui {
class DialogCreateOrEditData;
}

class DialogCreateOrEditData : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateOrEditData(CreateOrEditDataTypes type, User * user = nullptr, Human * human = nullptr, QWidget *parent = nullptr);
    ~DialogCreateOrEditData();

private slots:
    void on_change_clicked();

    void on_cancel_clicked();

private:
    Ui::DialogCreateOrEditData *ui;
    DialogAdmin *parent;
    void closeDialog();
    CreateOrEditDataTypes type;

    User * user;
    Human * human;

    void configureCreateUserForm();
    void configureCreateHumanForm();
    void configureEditUserForm();
    void configureEditHumanForm();

    void createUser();
    void createHuman();
    void editUser();
    void editHuman();
};

#endif // DIALOGCREATEOREDITDATA_H
