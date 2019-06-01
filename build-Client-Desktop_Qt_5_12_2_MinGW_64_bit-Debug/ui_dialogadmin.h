/********************************************************************************
** Form generated from reading UI file 'dialogadmin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADMIN_H
#define UI_DIALOGADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogAdmin
{
public:
    QPushButton *close;
    QTableView *tableView;
    QLabel *label;
    QPushButton *editButton;
    QPushButton *deleting;
    QLineEdit *searchEdit;
    QPushButton *searchButton;
    QPushButton *updateButton;

    void setupUi(QDialog *DialogAdmin)
    {
        if (DialogAdmin->objectName().isEmpty())
            DialogAdmin->setObjectName(QString::fromUtf8("DialogAdmin"));
        DialogAdmin->resize(802, 426);
        close = new QPushButton(DialogAdmin);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(20, 380, 75, 23));
        close->setAutoDefault(false);
        tableView = new QTableView(DialogAdmin);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 40, 671, 151));
        tableView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->horizontalHeader()->setDefaultSectionSize(130);
        tableView->horizontalHeader()->setMinimumSectionSize(60);
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);
        label = new QLabel(DialogAdmin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 20, 47, 13));
        editButton = new QPushButton(DialogAdmin);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(450, 300, 231, 23));
        deleting = new QPushButton(DialogAdmin);
        deleting->setObjectName(QString::fromUtf8("deleting"));
        deleting->setGeometry(QRect(50, 300, 261, 23));
        searchEdit = new QLineEdit(DialogAdmin);
        searchEdit->setObjectName(QString::fromUtf8("searchEdit"));
        searchEdit->setGeometry(QRect(50, 230, 113, 20));
        searchButton = new QPushButton(DialogAdmin);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(170, 230, 75, 23));
        updateButton = new QPushButton(DialogAdmin);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(620, 10, 75, 23));

        retranslateUi(DialogAdmin);

        QMetaObject::connectSlotsByName(DialogAdmin);
    } // setupUi

    void retranslateUi(QDialog *DialogAdmin)
    {
        DialogAdmin->setWindowTitle(QApplication::translate("DialogAdmin", "Dialog", nullptr));
        close->setText(QApplication::translate("DialogAdmin", "Can\321\201el", nullptr));
        label->setText(QApplication::translate("DialogAdmin", "Table", nullptr));
        editButton->setText(QApplication::translate("DialogAdmin", "Edit ", nullptr));
        deleting->setText(QApplication::translate("DialogAdmin", "Delete", nullptr));
        searchButton->setText(QApplication::translate("DialogAdmin", "Search", nullptr));
        updateButton->setText(QApplication::translate("DialogAdmin", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAdmin: public Ui_DialogAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADMIN_H
