#include "mydeletedialog.h"
#include "ui_mydeletedialog.h"
#include <QInputDialog>
#include <QMessageBox>

MyDeleteDialog::MyDeleteDialog(QWidget *parent, QString &s,int year, int month, int day) :
    QDialog(parent),
    ui(new Ui::MyDeleteDialog)
{
    ui->setupUi(this);

    s_ = s;
    year_ = year; month_ = month; day_ = day;
    x_ = 0; method_choosed = 0;

    QDate min(0,1,1);
    QDate max(2050,12,31);
    ui->from_date->setDisplayFormat("dd.MM.yyyy");
    ui->to_date->setDisplayFormat("dd.MM.yyyy");

    ui->from_date->setMinimumDate(min);
    ui->from_date->setMaximumDate(max);
    ui->to_date->setMinimumDate(min);
    ui->to_date->setMaximumDate(max);

    ui->from_date->setMinimumWidth(100);
    ui->to_date->setMinimumWidth(100);
    ui->from_date->setDate(QDate(2016,1,1));
    ui->to_date->setDate(QDate(2016,1,1));

    ui->cancel_button->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    ui->OK_button->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    ui->from_date->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    ui->to_date->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    ui->way_box->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
}

MyDeleteDialog::~MyDeleteDialog()
{
    delete ui;
}

void MyDeleteDialog::on_OK_button_clicked()
{
    emit delete_text(s_, method_choosed, ui->from_date->date(), ui->to_date->date(),x_);
    this->close();
}

void MyDeleteDialog::on_cancel_button_clicked()
{
    this->close();
}

void MyDeleteDialog::on_way_box_currentIndexChanged(int index)
{
    if(method_choosed != index)
    {
        method_choosed = index;
    }
    if(index == 3)
    {
        bool isOK;
        QString text = QInputDialog::getText(NULL, tr("输入框"),
                                                           tr("请输入x的值"),
                                                           QLineEdit::Normal,
                                                           "7",
                                                           &isOK);
        int x = text.toInt();
        if(isOK)
        {
            if(x > 0 && x < 10000)
            {
                x_ = x;
            }
            else QMessageBox::information(this, tr("错误:"), tr("无效的时间间隔"),QMessageBox::Ok);
        }
    }
}
