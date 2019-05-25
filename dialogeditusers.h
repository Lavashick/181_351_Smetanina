#ifndef DIALOGEDITUSERS_H
#define DIALOGEDITUSERS_H

#include <QDialog>
#include "DataBase.h"
#include <QStandardItemModel>

namespace Ui {
class DialogEditUsers;
}

class DialogEditUsers : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditUsers(QWidget *parent = nullptr);
    ~DialogEditUsers();

    void setData(QList<User> users);

private slots:
    void on_pushButton_7_clicked();

    void on_searchButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::DialogEditUsers *ui;
    QStandardItemModel *model2;
};

#endif // DIALOGEDITUSERS_H
