/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *login;
    QLineEdit *loginTxt;
    QHBoxLayout *horizontalLayout_5;
    QLabel *password;
    QLineEdit *passwordTxt;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *enterBtn;
    QPushButton *clearBtn;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        layoutWidget_2 = new QWidget(Dialog);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(60, 110, 278, 85));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        login = new QLabel(layoutWidget_2);
        login->setObjectName(QString::fromUtf8("login"));

        horizontalLayout_4->addWidget(login);

        loginTxt = new QLineEdit(layoutWidget_2);
        loginTxt->setObjectName(QString::fromUtf8("loginTxt"));

        horizontalLayout_4->addWidget(loginTxt);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        password = new QLabel(layoutWidget_2);
        password->setObjectName(QString::fromUtf8("password"));

        horizontalLayout_5->addWidget(password);

        passwordTxt = new QLineEdit(layoutWidget_2);
        passwordTxt->setObjectName(QString::fromUtf8("passwordTxt"));
        passwordTxt->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(passwordTxt);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        enterBtn = new QPushButton(layoutWidget_2);
        enterBtn->setObjectName(QString::fromUtf8("enterBtn"));

        horizontalLayout_6->addWidget(enterBtn);

        clearBtn = new QPushButton(layoutWidget_2);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));

        horizontalLayout_6->addWidget(clearBtn);


        verticalLayout_3->addLayout(horizontalLayout_6);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 70, 71, 20));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        login->setText(QApplication::translate("Dialog", "       Login:", nullptr));
        password->setText(QApplication::translate("Dialog", "Password:", nullptr));
        enterBtn->setText(QApplication::translate("Dialog", "Enter", nullptr));
        clearBtn->setText(QApplication::translate("Dialog", "Clear", nullptr));
        label->setText(QApplication::translate("Dialog", "Authorization", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
