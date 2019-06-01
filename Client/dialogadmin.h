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
    QList<User> users;
    QList<Human> humans;
    QList<User> tempUsers;
    QList<Human> tempHumans;
    Ui::DialogAdmin *ui;
    void updateUserTable();
    void updateHumanTable();
    QStandardItemModel *model;
};

#endif // DIALOGADMIN_H
