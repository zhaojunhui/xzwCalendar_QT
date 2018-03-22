#ifndef MYINPUTDIALOG_H
#define MYINPUTDIALOG_H

#include <QInputDialog>
#include <QDate>

namespace Ui {
class MyInputDialog;
}

class MyInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyInputDialog(QWidget *parent = 0);
    ~MyInputDialog();

signals:
    void add_text(QString&, int, QDate, QDate, int);
    //void delete_text(QString&, int, QDate*, QDate*, int);
    //void add_file(QString&, int);
    //void add_file(QString&,int);

private slots:
    void on_OK_button_clicked();

    void on_way_box_currentIndexChanged(int index);

    void on_cancel_button_clicked();

    void on_input_line_textChanged();

private:
    Ui::MyInputDialog *ui;

    int method_choosed;
    int x_;
};

#endif // MYINPUTDIALOG_H
