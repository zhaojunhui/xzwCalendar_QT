#include "myinputdialog.h"
#include "ui_myinputdialog.h"
#include <QMessageBox>
#include <QString>
#include <QDate>

MyInputDialog::MyInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyInputDialog)
{
    ui->setupUi(this);

    ui->OK_button->setEnabled(false);

    method_choosed = 0;
    x_ = 0;

    QDate min(1000,1,1);
    QDate max(2050,12,31);

    ui->OK_button->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    ui->from_date->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    ui->to_date->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    ui->cancel_button->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    ui->input_line->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    ui->way_box->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");

    ui->from_date->setDisplayFormat("dd.MM.yyyy");
    ui->to_date->setDisplayFormat("dd.MM.yyyy");

    ui->from_date->setMinimumWidth(100);
    ui->to_date->setMinimumWidth(100);
    ui->from_date->setDate(QDate(2016,1,1));
    ui->to_date->setDate(QDate(2016,1,1));

    ui->from_date->setMinimumDate(min);
    ui->from_date->setMaximumDate(max);
    ui->to_date->setMinimumDate(min);
    ui->to_date->setMaximumDate(max);
}

MyInputDialog::~MyInputDialog()
{
    delete ui;
}

void MyInputDialog::on_OK_button_clicked()
{
    if(ui->input_line->toPlainText() != "")
    {
        QString tmp = ui->input_line->toPlainText();
        emit add_text(tmp, method_choosed, ui->from_date->date(), ui->to_date->date(), x_);
    }
    this->close();
}

void MyInputDialog::on_way_box_currentIndexChanged(int index)
{
    if(method_choosed != index)
    {
        method_choosed = index;
    }
    if(index == 3)
    {
        bool isOK;
        QString text = QInputDialog::getText(NULL, tr("输入框"),
                                                           tr("请输入x值"),
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

void MyInputDialog::on_cancel_button_clicked()
{
    this->close();
}

void MyInputDialog::on_input_line_textChanged()
{
    if(ui->input_line->toPlainText() == "")
    {
        ui->OK_button->setEnabled(false);
    }
    else ui->OK_button->setEnabled(true);
}
