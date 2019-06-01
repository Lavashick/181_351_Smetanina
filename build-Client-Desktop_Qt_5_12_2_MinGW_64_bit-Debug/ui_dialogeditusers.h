/********************************************************************************
** Form generated from reading UI file 'dialogeditusers.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEDITUSERS_H
#define UI_DIALOGEDITUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogEditUsers
{
public:
    QTableView *tableView2;
    QPushButton *pushButton_7;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *searchButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *DialogEditUsers)
    {
        if (DialogEditUsers->objectName().isEmpty())
            DialogEditUsers->setObjectName(QString::fromUtf8("DialogEditUsers"));
        DialogEditUsers->resize(400, 419);
        tableView2 = new QTableView(DialogEditUsers);
        tableView2->setObjectName(QString::fromUtf8("tableView2"));
        tableView2->setGeometry(QRect(20, 10, 361, 171));
        tableView2->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView2->setSortingEnabled(false);
        tableView2->verticalHeader()->setVisible(false);
        pushButton_7 = new QPushButton(DialogEditUsers);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(160, 370, 75, 23));
        pushButton_7->setAutoDefault(false);
        layoutWidget = new QWidget(DialogEditUsers);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 260, 361, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setAutoDefault(false);

        horizontalLayout_2->addWidget(pushButton_2);

        layoutWidget1 = new QWidget(DialogEditUsers);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 210, 286, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        horizontalLayout_3->addLayout(horizontalLayout);

        searchButton = new QPushButton(layoutWidget1);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setAcceptDrops(false);

        horizontalLayout_3->addWidget(searchButton);

        pushButton_3 = new QPushButton(DialogEditUsers);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 300, 249, 23));
        pushButton_3->setAutoDefault(false);

        retranslateUi(DialogEditUsers);

        QMetaObject::connectSlotsByName(DialogEditUsers);
    } // setupUi

    void retranslateUi(QDialog *DialogEditUsers)
    {
        DialogEditUsers->setWindowTitle(QApplication::translate("DialogEditUsers", "Dialog", nullptr));
        pushButton_7->setText(QApplication::translate("DialogEditUsers", "Can\321\201el", nullptr));
        pushButton->setText(QApplication::translate("DialogEditUsers", "Add users", nullptr));
        pushButton_2->setText(QApplication::translate("DialogEditUsers", "Edit users", nullptr));
        label->setText(QApplication::translate("DialogEditUsers", "Search login:", nullptr));
        searchButton->setText(QApplication::translate("DialogEditUsers", "->", nullptr));
        pushButton_3->setText(QApplication::translate("DialogEditUsers", "Delete user", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogEditUsers: public Ui_DialogEditUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEDITUSERS_H
