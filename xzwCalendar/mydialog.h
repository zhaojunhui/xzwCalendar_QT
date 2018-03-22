#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QScrollBar>
#include <QCommandLinkButton>
#include <QVector>
#include <QWidget>
#include <QString>
#include <QDate>
#include <QPalette>
#include <QStyle>
#include <QFont>
#include <QPalette>
#include <QLayout>
#include <QListWidget>
#include <string>
#include <QColor>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent, int year, int month, int day);
    ~MyDialog();

    void initMyDialog(int year, int month, int day);

signals:
//    void contain_changed(QString&, int);
//    color_changed(QColor);
    void sth_changed();

public slots:
    void on_clicked_add_thing();
    void on_clicked_delete_thing();
    void on_clicked_delete_all_thing();
    void on_clicked_add_file();
    void to_add_text(QString&, int, QDate, QDate, int);
    void to_delete_text(QString&, int, QDate, QDate, int);
    void on_clicked_list_thing(QModelIndex);
    void on_clicked_color_button();

private:
    Ui::MyDialog *ui;

    QHBoxLayout *hb1, *hb2, *hb3, *hb4, *hb5, *mainLayout;
    QVBoxLayout *vb1;
    QLabel *head_title, *title_list_thing, *title_list_file;
    QListWidget *list_thing, *list_file;
    QPushButton *add_thing, *delete_thing, *delete_all_thing, *add_file;
    QPushButton *color_button;

    int year_, month_, day_;
    QString s_in_list_thing;
    QColor* m_color;

    std::string set_filename(int month, int day);

    std::string set_contains(QString& s, int year, int month, int day);

    void delete_tar(std::string& tar, std::string& filename);

    void addthing(QString&, int, int, int);
    void addthing_by_week(QString&, int, int, int, QDate, QDate);
    void addthing_by_month(QString&, int, int, int, QDate, QDate);
    void addthing_by_define(QString&, int, int, int, QDate, QDate, int);

    void deletething(QString&, int, int, int);
    void deletething_by_week(QString&, int, int, int, QDate, QDate);
    void deletething_by_month(QString&, int, int, int, QDate, QDate);
    void deletething_by_define(QString&, int, int, int, QDate, QDate, int);
};

#endif // MYDIALOG_H
