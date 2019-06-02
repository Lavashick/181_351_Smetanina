#ifndef DIALOGADMIN_H
#define DIALOGADMIN_H

#include <QDialog>
#include "dbservice.h"
#include <QStandardItemModel>

namespace Ui {
class DialogAdmin;
}

class DialogAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdmin(User * user, QWidget *parent = nullptr);
    ~DialogAdmin();

    void configure();

private slots:
    void on_pushButton_7_clicked();

    void on_deleting_clicked();

    void on_close_clicked();

    void on_searchButton_clicked();

    void on_updateButton_clicked();

    void on_searchEdit_textChanged(const QString &arg1);

private:
    User* user;

    Ui::DialogAdmin *ui;
    QStandardItemModel *model;

    QList<User> users;
    QList<User> tempUsers;
    void updateUserTable();

    QList<Human> humans;
    QList<Human> tempHumans;
    void updateHumanTable();
};

#endif // DIALOGADMIN_H
