#ifndef MYDELETEDIALOG_H
#define MYDELETEDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class MyDeleteDialog;
}

class MyDeleteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDeleteDialog(QWidget*, QString&, int, int, int);
    ~MyDeleteDialog();

signals:
    void delete_text(QString&, int, QDate, QDate, int);

private slots:
    void on_OK_button_clicked();

    void on_cancel_button_clicked();

    void on_way_box_currentIndexChanged(int index);

private:
    Ui::MyDeleteDialog *ui;

    int method_choosed;
    int year_, month_, day_;
    int x_;
    QString s_;
};

#endif // MYDELETEDIALOG_H
