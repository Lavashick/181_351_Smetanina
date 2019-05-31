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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogAdmin
{
public:
    QPushButton *pushButton_7;
    QTableView *tableDB;
    QLabel *tableOf;
    QPushButton *refreshTable;
    QFrame *frameEditUsers;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *loginValueEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *passwordValueEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *DegreeValueEdit;
    QFrame *frameAddUsers;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *loginValue;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *passwordValue;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *DegreeValue;
    QFrame *frameYesNo;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *frameAddStarpers;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *loginValue_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *passwordValue_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QLineEdit *DegreeValue_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_12;
    QLineEdit *DegreeValue_4;
    QFrame *frameEditStarpers;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_13;
    QLineEdit *loginValue_3;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_14;
    QLineEdit *passwordValue_3;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_15;
    QLineEdit *DegreeValue_5;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_16;
    QLineEdit *DegreeValue_6;
    QFrame *frameStarpers;
    QPushButton *addRecord;
    QPushButton *deleteRecord;
    QPushButton *editRecord;
    QFrame *frameUsers;
    QPushButton *addUsers;
    QPushButton *deleteUsers;
    QPushButton *editUsers;

    void setupUi(QDialog *DialogAdmin)
    {
        if (DialogAdmin->objectName().isEmpty())
            DialogAdmin->setObjectName(QString::fromUtf8("DialogAdmin"));
        DialogAdmin->resize(713, 571);
        pushButton_7 = new QPushButton(DialogAdmin);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(310, 530, 75, 23));
        pushButton_7->setAutoDefault(false);
        tableDB = new QTableView(DialogAdmin);
        tableDB->setObjectName(QString::fromUtf8("tableDB"));
        tableDB->setGeometry(QRect(30, 40, 621, 251));
        tableOf = new QLabel(DialogAdmin);
        tableOf->setObjectName(QString::fromUtf8("tableOf"));
        tableOf->setGeometry(QRect(290, 20, 111, 16));
        refreshTable = new QPushButton(DialogAdmin);
        refreshTable->setObjectName(QString::fromUtf8("refreshTable"));
        refreshTable->setGeometry(QRect(270, 300, 141, 23));
        frameEditUsers = new QFrame(DialogAdmin);
        frameEditUsers->setObjectName(QString::fromUtf8("frameEditUsers"));
        frameEditUsers->setGeometry(QRect(240, 420, 221, 91));
        frameEditUsers->setFrameShape(QFrame::StyledPanel);
        frameEditUsers->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frameEditUsers);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 193, 80));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        loginValueEdit = new QLineEdit(layoutWidget);
        loginValueEdit->setObjectName(QString::fromUtf8("loginValueEdit"));

        horizontalLayout_4->addWidget(loginValueEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        passwordValueEdit = new QLineEdit(layoutWidget);
        passwordValueEdit->setObjectName(QString::fromUtf8("passwordValueEdit"));

        horizontalLayout_5->addWidget(passwordValueEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        DegreeValueEdit = new QLineEdit(layoutWidget);
        DegreeValueEdit->setObjectName(QString::fromUtf8("DegreeValueEdit"));

        horizontalLayout_6->addWidget(DegreeValueEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        frameAddUsers = new QFrame(DialogAdmin);
        frameAddUsers->setObjectName(QString::fromUtf8("frameAddUsers"));
        frameAddUsers->setGeometry(QRect(230, 340, 221, 91));
        frameAddUsers->setFrameShape(QFrame::StyledPanel);
        frameAddUsers->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frameAddUsers);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 193, 80));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        loginValue = new QLineEdit(widget);
        loginValue->setObjectName(QString::fromUtf8("loginValue"));

        horizontalLayout->addWidget(loginValue);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        passwordValue = new QLineEdit(widget);
        passwordValue->setObjectName(QString::fromUtf8("passwordValue"));

        horizontalLayout_2->addWidget(passwordValue);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        DegreeValue = new QLineEdit(widget);
        DegreeValue->setObjectName(QString::fromUtf8("DegreeValue"));

        horizontalLayout_3->addWidget(DegreeValue);


        verticalLayout->addLayout(horizontalLayout_3);

        frameYesNo = new QFrame(DialogAdmin);
        frameYesNo->setObjectName(QString::fromUtf8("frameYesNo"));
        frameYesNo->setGeometry(QRect(30, 450, 221, 111));
        frameYesNo->setFrameShape(QFrame::StyledPanel);
        frameYesNo->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frameYesNo);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 0, 171, 51));
        pushButton = new QPushButton(frameYesNo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 50, 75, 23));
        pushButton_2 = new QPushButton(frameYesNo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 50, 75, 23));
        frameAddStarpers = new QFrame(DialogAdmin);
        frameAddStarpers->setObjectName(QString::fromUtf8("frameAddStarpers"));
        frameAddStarpers->setGeometry(QRect(440, 350, 221, 141));
        frameAddStarpers->setFrameShape(QFrame::StyledPanel);
        frameAddStarpers->setFrameShadow(QFrame::Raised);
        layoutWidget_2 = new QWidget(frameAddStarpers);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 10, 195, 110));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);

        loginValue_2 = new QLineEdit(layoutWidget_2);
        loginValue_2->setObjectName(QString::fromUtf8("loginValue_2"));

        horizontalLayout_8->addWidget(loginValue_2);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);

        passwordValue_2 = new QLineEdit(layoutWidget_2);
        passwordValue_2->setObjectName(QString::fromUtf8("passwordValue_2"));

        horizontalLayout_9->addWidget(passwordValue_2);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_10->addWidget(label_11);

        DegreeValue_3 = new QLineEdit(layoutWidget_2);
        DegreeValue_3->setObjectName(QString::fromUtf8("DegreeValue_3"));

        horizontalLayout_10->addWidget(DegreeValue_3);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout_3->addLayout(verticalLayout_4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_11->addWidget(label_12);

        DegreeValue_4 = new QLineEdit(layoutWidget_2);
        DegreeValue_4->setObjectName(QString::fromUtf8("DegreeValue_4"));

        horizontalLayout_11->addWidget(DegreeValue_4);


        verticalLayout_3->addLayout(horizontalLayout_11);

        frameEditStarpers = new QFrame(DialogAdmin);
        frameEditStarpers->setObjectName(QString::fromUtf8("frameEditStarpers"));
        frameEditStarpers->setGeometry(QRect(530, 250, 221, 141));
        frameEditStarpers->setFrameShape(QFrame::StyledPanel);
        frameEditStarpers->setFrameShadow(QFrame::Raised);
        layoutWidget_3 = new QWidget(frameEditStarpers);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 10, 195, 110));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_13 = new QLabel(layoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_12->addWidget(label_13);

        loginValue_3 = new QLineEdit(layoutWidget_3);
        loginValue_3->setObjectName(QString::fromUtf8("loginValue_3"));

        horizontalLayout_12->addWidget(loginValue_3);


        verticalLayout_6->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_14 = new QLabel(layoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_13->addWidget(label_14);

        passwordValue_3 = new QLineEdit(layoutWidget_3);
        passwordValue_3->setObjectName(QString::fromUtf8("passwordValue_3"));

        horizontalLayout_13->addWidget(passwordValue_3);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_15 = new QLabel(layoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_14->addWidget(label_15);

        DegreeValue_5 = new QLineEdit(layoutWidget_3);
        DegreeValue_5->setObjectName(QString::fromUtf8("DegreeValue_5"));

        horizontalLayout_14->addWidget(DegreeValue_5);


        verticalLayout_6->addLayout(horizontalLayout_14);


        verticalLayout_5->addLayout(verticalLayout_6);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_16 = new QLabel(layoutWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_15->addWidget(label_16);

        DegreeValue_6 = new QLineEdit(layoutWidget_3);
        DegreeValue_6->setObjectName(QString::fromUtf8("DegreeValue_6"));

        horizontalLayout_15->addWidget(DegreeValue_6);


        verticalLayout_5->addLayout(horizontalLayout_15);

        frameStarpers = new QFrame(DialogAdmin);
        frameStarpers->setObjectName(QString::fromUtf8("frameStarpers"));
        frameStarpers->setGeometry(QRect(20, 300, 191, 141));
        frameStarpers->setFrameShape(QFrame::StyledPanel);
        frameStarpers->setFrameShadow(QFrame::Raised);
        addRecord = new QPushButton(frameStarpers);
        addRecord->setObjectName(QString::fromUtf8("addRecord"));
        addRecord->setGeometry(QRect(30, 90, 141, 23));
        deleteRecord = new QPushButton(frameStarpers);
        deleteRecord->setObjectName(QString::fromUtf8("deleteRecord"));
        deleteRecord->setGeometry(QRect(30, 60, 141, 23));
        editRecord = new QPushButton(frameStarpers);
        editRecord->setObjectName(QString::fromUtf8("editRecord"));
        editRecord->setGeometry(QRect(30, 30, 141, 23));
        frameUsers = new QFrame(DialogAdmin);
        frameUsers->setObjectName(QString::fromUtf8("frameUsers"));
        frameUsers->setGeometry(QRect(0, 310, 191, 141));
        frameUsers->setFrameShape(QFrame::StyledPanel);
        frameUsers->setFrameShadow(QFrame::Raised);
        addUsers = new QPushButton(frameUsers);
        addUsers->setObjectName(QString::fromUtf8("addUsers"));
        addUsers->setGeometry(QRect(30, 90, 141, 23));
        deleteUsers = new QPushButton(frameUsers);
        deleteUsers->setObjectName(QString::fromUtf8("deleteUsers"));
        deleteUsers->setGeometry(QRect(30, 60, 141, 23));
        editUsers = new QPushButton(frameUsers);
        editUsers->setObjectName(QString::fromUtf8("editUsers"));
        editUsers->setGeometry(QRect(30, 30, 141, 23));

        retranslateUi(DialogAdmin);

        QMetaObject::connectSlotsByName(DialogAdmin);
    } // setupUi

    void retranslateUi(QDialog *DialogAdmin)
    {
        DialogAdmin->setWindowTitle(QApplication::translate("DialogAdmin", "Dialog", nullptr));
        pushButton_7->setText(QApplication::translate("DialogAdmin", "Can\321\201el", nullptr));
        tableOf->setText(QApplication::translate("DialogAdmin", "Table of starpers", nullptr));
        refreshTable->setText(QApplication::translate("DialogAdmin", "Refresh table", nullptr));
        label_4->setText(QApplication::translate("DialogAdmin", "Login:", nullptr));
        label_5->setText(QApplication::translate("DialogAdmin", "Password:", nullptr));
        label_6->setText(QApplication::translate("DialogAdmin", "Degree:", nullptr));
        label->setText(QApplication::translate("DialogAdmin", "Login:", nullptr));
        label_2->setText(QApplication::translate("DialogAdmin", "Password:", nullptr));
        label_3->setText(QApplication::translate("DialogAdmin", "Degree:", nullptr));
        label_7->setText(QApplication::translate("DialogAdmin", "Are you sure to delete this?", nullptr));
        pushButton->setText(QApplication::translate("DialogAdmin", "YES", nullptr));
        pushButton_2->setText(QApplication::translate("DialogAdmin", "NO", nullptr));
        label_9->setText(QApplication::translate("DialogAdmin", "Town:", nullptr));
        label_10->setText(QApplication::translate("DialogAdmin", "Address:", nullptr));
        label_11->setText(QApplication::translate("DialogAdmin", "Number of people:", nullptr));
        label_12->setText(QApplication::translate("DialogAdmin", "Name of pansion:", nullptr));
        label_13->setText(QApplication::translate("DialogAdmin", "Town:", nullptr));
        label_14->setText(QApplication::translate("DialogAdmin", "Address:", nullptr));
        label_15->setText(QApplication::translate("DialogAdmin", "Number of people:", nullptr));
        label_16->setText(QApplication::translate("DialogAdmin", "Name of pansion:", nullptr));
        addRecord->setText(QApplication::translate("DialogAdmin", "Add record", nullptr));
        deleteRecord->setText(QApplication::translate("DialogAdmin", "Delete record", nullptr));
        editRecord->setText(QApplication::translate("DialogAdmin", "Edit record", nullptr));
        addUsers->setText(QApplication::translate("DialogAdmin", "Add users", nullptr));
        deleteUsers->setText(QApplication::translate("DialogAdmin", "Delete users", nullptr));
        editUsers->setText(QApplication::translate("DialogAdmin", "Edit users", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAdmin: public Ui_DialogAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADMIN_H
