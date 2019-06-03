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

    QList<User> users;
    void updateUserTable();

    QList<Human> humans;
    void updateHumanTable();

private slots:
    void on_deleting_clicked();

    void on_close_clicked();

    void on_searchButton_clicked();

    void on_updateButton_clicked();

    void on_searchEdit_textChanged(const QString &arg1);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_editButton_clicked();

private:
    User* user;

    Ui::DialogAdmin *ui;
    QStandardItemModel *model;

    QList<User> tempUsers;

    QList<Human> tempHumans;
};

#endif // DIALOGADMIN_H
