/********************************************************************************
** Form generated from reading UI file 'myinputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYINPUTDIALOG_H
#define UI_MYINPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyInputDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *way_box;
    QLabel *head_title;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *OK_button;
    QPushButton *cancel_button;
    QTextEdit *input_line;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QDateEdit *from_date;
    QLabel *label_10;
    QDateEdit *to_date;

    void setupUi(QDialog *MyInputDialog)
    {
        if (MyInputDialog->objectName().isEmpty())
            MyInputDialog->setObjectName(QStringLiteral("MyInputDialog"));
        MyInputDialog->resize(452, 274);
        horizontalLayoutWidget = new QWidget(MyInputDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 130, 201, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        way_box = new QComboBox(horizontalLayoutWidget);
        way_box->setObjectName(QStringLiteral("way_box"));

        horizontalLayout->addWidget(way_box);

        head_title = new QLabel(MyInputDialog);
        head_title->setObjectName(QStringLiteral("head_title"));
        head_title->setGeometry(QRect(40, 20, 201, 16));
        verticalLayoutWidget = new QWidget(MyInputDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 120, 160, 71));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        OK_button = new QPushButton(verticalLayoutWidget);
        OK_button->setObjectName(QStringLiteral("OK_button"));

        verticalLayout->addWidget(OK_button);

        cancel_button = new QPushButton(verticalLayoutWidget);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));

        verticalLayout->addWidget(cancel_button);

        input_line = new QTextEdit(MyInputDialog);
        input_line->setObjectName(QStringLiteral("input_line"));
        input_line->setGeometry(QRect(40, 40, 371, 71));
        horizontalLayoutWidget_3 = new QWidget(MyInputDialog);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(40, 200, 291, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
#ifndef Q_OS_MAC
        horizontalLayout_4->setSpacing(-1);
#endif
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 5, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        from_date = new QDateEdit(horizontalLayoutWidget_3);
        from_date->setObjectName(QStringLiteral("from_date"));

        horizontalLayout_4->addWidget(from_date);

        label_10 = new QLabel(horizontalLayoutWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setEnabled(true);

        horizontalLayout_4->addWidget(label_10);

        to_date = new QDateEdit(horizontalLayoutWidget_3);
        to_date->setObjectName(QStringLiteral("to_date"));

        horizontalLayout_4->addWidget(to_date);


        retranslateUi(MyInputDialog);

        QMetaObject::connectSlotsByName(MyInputDialog);
    } // setupUi

    void retranslateUi(QDialog *MyInputDialog)
    {
        MyInputDialog->setWindowTitle(QApplication::translate("MyInputDialog", "\346\267\273\345\212\240\344\272\213\344\273\266\346\241\206", 0));
        way_box->clear();
        way_box->insertItems(0, QStringList()
         << QApplication::translate("MyInputDialog", "\344\273\216\344\270\215\351\207\215\345\244\215", 0)
         << QApplication::translate("MyInputDialog", "\346\257\217\345\221\250", 0)
         << QApplication::translate("MyInputDialog", "\346\257\217\346\234\210", 0)
         << QApplication::translate("MyInputDialog", "\346\257\217x\345\244\251", 0)
        );
        head_title->setText(QApplication::translate("MyInputDialog", "\350\257\267\350\276\223\345\205\245\357\274\232", 0));
        OK_button->setText(QApplication::translate("MyInputDialog", "\347\241\256\350\256\244", 0));
        cancel_button->setText(QApplication::translate("MyInputDialog", "\345\217\226\346\266\210", 0));
        label_9->setText(QApplication::translate("MyInputDialog", "\344\273\216", 0));
        label_10->setText(QApplication::translate("MyInputDialog", "\345\210\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MyInputDialog: public Ui_MyInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYINPUTDIALOG_H
