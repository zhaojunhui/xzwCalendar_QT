/********************************************************************************
** Form generated from reading UI file 'mydeletedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDELETEDIALOG_H
#define UI_MYDELETEDIALOG_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyDeleteDialog
{
public:
    QLabel *label;
    QComboBox *way_box;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *OK_button;
    QPushButton *cancel_button;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDateEdit *from_date;
    QLabel *label_3;
    QDateEdit *to_date;

    void setupUi(QDialog *MyDeleteDialog)
    {
        if (MyDeleteDialog->objectName().isEmpty())
            MyDeleteDialog->setObjectName(QStringLiteral("MyDeleteDialog"));
        MyDeleteDialog->resize(446, 213);
        label = new QLabel(MyDeleteDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 181, 41));
        way_box = new QComboBox(MyDeleteDialog);
        way_box->setObjectName(QStringLiteral("way_box"));
        way_box->setGeometry(QRect(20, 60, 201, 26));
        verticalLayoutWidget = new QWidget(MyDeleteDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(240, 20, 160, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        OK_button = new QPushButton(verticalLayoutWidget);
        OK_button->setObjectName(QStringLiteral("OK_button"));

        verticalLayout->addWidget(OK_button);

        cancel_button = new QPushButton(verticalLayoutWidget);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));

        verticalLayout->addWidget(cancel_button);

        horizontalLayoutWidget = new QWidget(MyDeleteDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 120, 301, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        from_date = new QDateEdit(horizontalLayoutWidget);
        from_date->setObjectName(QStringLiteral("from_date"));

        horizontalLayout->addWidget(from_date);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        to_date = new QDateEdit(horizontalLayoutWidget);
        to_date->setObjectName(QStringLiteral("to_date"));

        horizontalLayout->addWidget(to_date);


        retranslateUi(MyDeleteDialog);

        QMetaObject::connectSlotsByName(MyDeleteDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDeleteDialog)
    {
        MyDeleteDialog->setWindowTitle(QApplication::translate("MyDeleteDialog", "\345\210\240\351\231\244\344\272\213\344\273\266\346\241\206", 0));
        label->setText(QApplication::translate("MyDeleteDialog", "\345\210\240\351\231\244:", 0));
        way_box->clear();
        way_box->insertItems(0, QStringList()
         << QApplication::translate("MyDeleteDialog", "\344\273\216\344\270\215\351\207\215\345\244\215", 0)
         << QApplication::translate("MyDeleteDialog", "\346\257\217\345\221\250", 0)
         << QApplication::translate("MyDeleteDialog", "\346\257\217\346\234\210", 0)
         << QApplication::translate("MyDeleteDialog", "\346\257\217x\345\244\251", 0)
        );
        OK_button->setText(QApplication::translate("MyDeleteDialog", "\347\241\256\350\256\244", 0));
        cancel_button->setText(QApplication::translate("MyDeleteDialog", "\345\217\226\346\266\210", 0));
        label_2->setText(QApplication::translate("MyDeleteDialog", "\344\273\216", 0));
        label_3->setText(QApplication::translate("MyDeleteDialog", "\345\210\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MyDeleteDialog: public Ui_MyDeleteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDELETEDIALOG_H
