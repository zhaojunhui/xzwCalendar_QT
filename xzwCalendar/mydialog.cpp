#include "mydialog.h"
#include "ui_mydialog.h"
#include "myinputdialog.h"
#include "mydeletedialog.h"
#include <QInputDialog>
#include <fstream>
#include <string>
#include <QDebug>
#include <QModelIndex>
#include <QListWidget>
#include <QListWidgetItem>
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include "date.h"

using namespace std;

MyDialog::MyDialog(QWidget *parent, int year, int month, int day) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);

    initMyDialog(year, month, day);

    resize(400,600);

    connect(add_thing,SIGNAL(clicked()),this,SLOT(on_clicked_add_thing()));
    connect(delete_thing,SIGNAL(clicked()),this,SLOT(on_clicked_delete_thing()));
    connect(delete_all_thing,SIGNAL(clicked()),this,SLOT(on_clicked_delete_all_thing()));
    connect(add_file, SIGNAL(clicked()),this,SLOT(on_clicked_add_file()));
    connect(color_button,SIGNAL(clicked()),this,SLOT(on_clicked_color_button()));
}

MyDialog::~MyDialog()
{
    emit sth_changed();
    delete ui;
}

void MyDialog::initMyDialog(int year, int month, int day)
{
    m_color = new QColor;

    year_ = year; month_ = month; day_ = day;

    head_title = new QLabel;
    QFont ft_head_title;
    ft_head_title.setItalic(true);
    ft_head_title.setPointSize(30);
    head_title->setFont(ft_head_title);
    head_title->setText(QString::number(year) + tr("年") + QString::number(month) + tr("月") + QString::number(day) + tr("日"));
    head_title->setStyleSheet("background-color: rgb(255,255,255)");
    hb1 = new QHBoxLayout;
    hb1->addWidget(head_title);
    hb1->addSpacerItem(new QSpacerItem(100,40));
    //setLayout(hb1);

    title_list_thing = new QLabel;
    title_list_thing->setText(tr("待办事项"));
    QFont ft_title_list_thing;
    ft_title_list_thing.setPointSize(18);
    title_list_thing->setFont(ft_title_list_thing);
    title_list_file = new QLabel;
    title_list_file->setText(tr("相关文件"));
    QFont ft_title_list_file;
    ft_title_list_file.setPointSize(18);
    title_list_file->setFont(ft_title_list_file);
    hb2 = new QHBoxLayout;
    hb2->addWidget(title_list_thing);
    hb2->addWidget(title_list_file);
    //setLayout(hb2);

    list_thing = new QListWidget(this);    
    QFont ft_list_thing;
    ft_list_thing.setPointSize(15);
    list_thing->setFont(ft_list_thing);
    list_thing->setStyleSheet("background-color: rgb(255,255,255)");

    list_file = new QListWidget(this);
    QFont ft_list_file;
    ft_list_file.setPointSize(15);
    list_file->setFont(ft_list_file);
    list_file->setStyleSheet("background-color: rgb(255,255,255)");

    hb3 = new QHBoxLayout;
    hb3->addWidget(list_thing);
    hb3->addWidget(list_file);


    string filename = set_filename(month, day);
    ifstream fin; fin.open(filename);
    string ss;
    int ndate = year*10000 + month*100 + day;
    while(getline(fin, ss))
    {
        QString qq = QString::fromStdString(ss);
        QString ndate_q = QString::number(ndate);
        string ndate_s = ndate_q.toStdString();
        qDebug() << ndate_q;
        string sub_ss = ss.substr(0, 8);
        string con = ss.substr(9, ss.length() - 9);
        QString con_q = QString::fromStdString(con);
        QString sub_qq = QString::fromStdString(sub_ss);
        qDebug() << sub_qq;
        if(ndate_s == sub_ss)
        {
            list_thing->addItem(con_q);
        }
    }
    if(list_thing->count() != 0) s_in_list_thing = list_thing->item(0)->text();
    connect(list_thing,SIGNAL(clicked(QModelIndex)),this,SLOT(on_clicked_list_thing(QModelIndex)));

    fin.close();
    //setLayout(hb3);

    string ndate_s = QString::number(ndate).toStdString();
    string tmp;
    fin.open("./AppFile/UserFile/" + ndate_s + "_" + "index.txt");
    while(getline(fin, tmp))
    {
        list_file->addItem(QString::fromStdString(tmp));
    }
    fin.close();

    add_thing = new QPushButton(tr("添加事项"));
    add_thing->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    delete_thing = new QPushButton(tr("删除事项"));
    delete_thing->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    delete_all_thing = new QPushButton(tr("删除所有今日事项"));
    delete_all_thing->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    add_file = new QPushButton(tr("添加文件"));
    add_file->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    hb4 = new QHBoxLayout;
    hb4->addWidget(add_thing);
    hb4->addWidget(delete_thing);
    hb4->addWidget(delete_all_thing);
    hb4->addWidget(add_file);
    //setLayout(hb4);

    hb5 = new QHBoxLayout;
    color_button = new QPushButton(tr("颜色"));
    color_button->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    hb5->addWidget(color_button);
    hb5->addSpacerItem(new QSpacerItem(300,20));

    vb1 = new QVBoxLayout;
    vb1->addLayout(hb1);
    vb1->addLayout(hb2);
    vb1->addLayout(hb3);
    vb1->addLayout(hb4);
    vb1->addLayout(hb5);
    //setLayout(vb1);

    mainLayout = new QHBoxLayout;
    mainLayout->addLayout(vb1);
    setLayout(mainLayout);

}

void MyDialog::on_clicked_add_thing()
{
    MyInputDialog* tmp = new MyInputDialog(this);
    connect(tmp,SIGNAL(add_text(QString&, int, QDate, QDate, int)),this,SLOT(to_add_text(QString&, int, QDate, QDate, int)));
    tmp->exec();
}

void MyDialog::on_clicked_add_file()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("添加文件"));
    QString real_filename = filename.section("/", -1, -1);
    int ndate = year_ *10000 + month_ *100 + day_;
    QString ndate_s = QString::number(ndate);
    QString new_filename = "./AppFile/UserFile/" + ndate_s + "_" + real_filename;
    if(QFile::copy(filename, new_filename))
        list_file->addItem(real_filename);
    ofstream fout;
    fout.open("./AppFile/UserFile/" + ndate_s.toStdString() + "_" + "index.txt",ios::app);
    fout << real_filename.toStdString() << endl;
    fout.close();
}

void MyDialog::to_add_text(QString& s, int i, QDate from, QDate to, int x)
{
    list_thing->addItem(s);
    if(i == 0) addthing(s, year_, month_, day_);
    if(i == 1) addthing_by_week(s, year_, month_, day_, from, to);
    if(i == 2) addthing_by_month(s, year_, month_, day_, from, to);
    if(i == 3) addthing_by_define(s,year_, month_, day_, from, to, x);
}

string MyDialog::set_filename(int month, int day)
{
    QString filename_q = "./AppFile/UserFile/" + QString::number(month) +
            "_" + QString::number(day) + ".txt";
    string filename = filename_q.toStdString();
    return filename;
}

string MyDialog::set_contains(QString &s, int year, int month, int day)
{
    int ndate = year * 10000 + month * 100 + day;
    QString t_of_q =QString::number(ndate) + " " + s;
    string t_of_s = t_of_q.toStdString();
    return t_of_s;
}

void MyDialog::delete_tar(string &tar, string &filename)
{
    ifstream fin; fin.open(filename);
    ofstream fout; fout.open("./AppFile/UserFile/tmp.txt");
    string ss;
    while(getline(fin,ss))
    {
        QString ss_q =QString::fromStdString(ss);
        QString tar_q =QString::fromStdString(tar);
        qDebug() << ss_q << tar_q << "hahah";
        if(ss != tar)  fout << ss << endl;
    }
    fin.close(); fout.close();
    fin.open("./AppFile/UserFile/tmp.txt");
    fout.open(filename);
    while(getline(fin,ss))
    {
        fout << ss << endl;
    }
}

void MyDialog::addthing(QString &s, int year, int month, int day)
{
    string filename = set_filename(month, day);
    ofstream fout;
    fout.open(filename,ios::app);
    string t_of_s = set_contains(s, year, month, day);
    fout << t_of_s << endl;
    fout.close();
}

void MyDialog::addthing_by_week(QString &s, int year, int month, int day, QDate from, QDate to)
{
    int ndate = year * 10000 + month * 100 + day;
    QDate n_date(year, month, day);
    int fdate = from.year() * 10000 + from.month() * 100 + from.day();
    int tdate = to.year() * 10000 + to.month() * 100 + to.day();

    for(int i = fdate; i <= tdate; i++)
    {
        int i_year =(i - (i%10000))/10000;
        int i_month = ((i%10000)-(i%100))/100;
        int i_day = i%100;
        if(QDate::isValid(i_year, i_month, i_day))
        {
            QDate i_date(i_year, i_month, i_day);
            if((i_date.daysTo(n_date))%7 == 0)
            {

                string filename = set_filename(i_month, i_day);
                ofstream fout;
                fout.open(filename,ios::app);
                string t_of_s = set_contains(s, i_year, i_month, i_day);
                fout << t_of_s << endl;
                fout.close();
            }
        }
    }
}

void MyDialog::addthing_by_month(QString &s, int year, int month, int day, QDate from, QDate to)
{
    int ndate = year * 10000 + month * 100 + day;
    int fdate = from.year() * 10000 + from.month() * 100 + from.day();
    int tdate = to.year() * 10000 + to.month() * 100 + to.day();

    for(int i = fdate; i <= tdate; i++)
    {
        int i_year =(i - (i%10000))/10000;
        int i_month = ((i%10000)-(i%100))/100;
        int i_day = i%100;
        if(QDate::isValid(i_year, i_month, i_day))
        {
            if(i_day == day)
            {

                string filename = set_filename(i_month, i_day);
                ofstream fout;
                fout.open(filename,ios::app);

                string t_of_s = set_contains(s, i_year, i_month, i_day);
                fout << t_of_s << endl;

                fout.close();
            }
        }
    }
}

void MyDialog::addthing_by_define(QString &s, int year, int month, int day, QDate from, QDate to, int x)
{
    int ndate = year * 10000 + month * 100 + day;
    QDate n_date(year, month, day);
    int fdate = from.year() * 10000 + from.month() * 100 + from.day();
    int tdate = to.year() * 10000 + to.month() * 100 + to.day();

    for(int i = fdate; i <= tdate; i++)
    {
        int i_year =(i - (i%10000))/10000;
        int i_month = ((i%10000)-(i%100))/100;
        int i_day = i%100;
        if(QDate::isValid(i_year, i_month, i_day))
        {
            QDate i_date(i_year, i_month, i_day);
            if((i_date.daysTo(n_date))%x == 0)
            {

                string filename = set_filename(i_month, i_day);
                ofstream fout;
                fout.open(filename,ios::app);
                string t_of_s = set_contains(s, i_year, i_month, i_day);
                fout << t_of_s << endl;
                fout.close();
            }
        }
    }
}

void MyDialog::on_clicked_delete_thing()
{
    MyDeleteDialog* tmp = new MyDeleteDialog(this, s_in_list_thing, year_, month_, day_);
    connect(tmp,SIGNAL(delete_text(QString&, int, QDate, QDate, int)),this,SLOT(to_delete_text(QString&, int, QDate, QDate, int)));
    tmp->exec();
}

void MyDialog::to_delete_text(QString &s, int i, QDate from, QDate to, int x)
{
    QListWidgetItem *item = list_thing->takeItem(list_thing->currentRow()); delete item;
    if(i == 0) deletething(s, year_, month_, day_);
    if(i == 1) deletething_by_week(s, year_, month_, day_, from, to);
    if(i == 2) deletething_by_month(s, year_, month_, day_, from, to);
    if(i == 3) deletething_by_define(s,year_, month_, day_, from, to, x);
}

void MyDialog::deletething(QString &s, int year, int month, int day)
{
    string filename = set_filename(month, day);
    string tar = set_contains(s, year, month, day);
    delete_tar(tar, filename);
}

void MyDialog::deletething_by_week(QString &s, int year, int month, int day, QDate from, QDate to)
{
    QDate n_date(year, month, day);
    int ndate = year * 10000 + month * 100 + day;
    int fdate = from.year() * 10000 + from.month() * 100 + from.day();
    int tdate = to.year() * 10000 + to.month() * 100 + to.day();

    for(int i = fdate; i <= tdate; i++)
    {
        int i_year =(i - (i%10000))/10000;
        int i_month = ((i%10000)-(i%100))/100;
        int i_day = i%100;
        if(QDate::isValid(i_year, i_month, i_day))
        {
            QDate i_date(i_year, i_month, i_day);
            if(i_date.daysTo(n_date)%7 == 0)
            {
                string filename = set_filename(i_month, i_day);
                string tar = set_contains(s, i_year, i_month, i_day);
                delete_tar(tar, filename);
            }
        }
    }
}

void MyDialog::deletething_by_month(QString &s, int year, int month, int day, QDate from, QDate to)
{
    string filename = set_filename(month, day);
    int ndate = year * 10000 + month * 100 + day;
    int fdate = from.year() * 10000 + from.month() * 100 + from.day();
    int tdate = to.year() * 10000 + to.month() * 100 + to.day();

    for(int i = fdate; i <= tdate; i++)
    {
        int i_year =(i - (i%10000))/10000;
        int i_month = ((i%10000)-(i%100))/100;
        int i_day = i%100;
        if(QDate::isValid(i_year, i_month, i_day))
        {
            if(i_day == day)
            {
                string tar = set_contains(s, i_year, i_month, i_day);
                delete_tar(tar, filename);
            }
        }
    }
}

void MyDialog::deletething_by_define(QString &s, int year, int month, int day, QDate from, QDate to, int x)
{
    QDate n_date(year, month, day);
    int ndate = year * 10000 + month * 100 + day;
    int fdate = from.year() * 10000 + from.month() * 100 + from.day();
    int tdate = to.year() * 10000 + to.month() * 100 + to.day();

    for(int i = fdate; i <= tdate; i++)
    {
        int i_year =(i - (i%10000))/10000;
        int i_month = ((i%10000)-(i%100))/100;
        int i_day = i%100;
        if(QDate::isValid(i_year, i_month, i_day))
        {
            QDate i_date(i_year, i_month, i_day);
            if(i_date.daysTo(n_date)%x == 0)
            {
                string filename = set_filename(i_month, i_day);
                string tar = set_contains(s, i_year, i_month, i_day);
                delete_tar(tar, filename);
            }
        }
    }
}

void MyDialog::on_clicked_list_thing(QModelIndex ind)
{
    s_in_list_thing = list_thing->item(ind.row())->text();
}

void MyDialog::on_clicked_delete_all_thing()
{
    string filename = set_filename(month_, day_);
    int ndate = year_*10000 + month_*100 + day_;
    QString ndate_q = QString::number(ndate);
    while(list_thing->count() != 0)
    {
        QListWidgetItem *item = list_thing->takeItem(0);
        QString tar_q = ndate_q + " " + item->text();
        string tar = tar_q.toStdString();
        delete item;
        delete_tar(tar, filename);
    }
}

void MyDialog::on_clicked_color_button()
{
    QColor pickedColor = QColorDialog::getColor(Qt::red);
    m_color->setRgb(pickedColor.red(), pickedColor.green(), pickedColor.blue());
    QString css = QString("background-color: rgb(") + QString::number(pickedColor.red()) + QString(",") + QString::number(pickedColor.green()) + QString(",") + QString::number(pickedColor.blue()) + QString(");");
    ofstream fout;
    fout.open("./AppFile/UserFile/color.txt", ios::app);
    fout.close();
    ifstream fin; string tmp;
    int ndate = year_*10000 + month_*100 +day_;
    QString css_q = QString::number(ndate) + " " + css;
    string css_s = css_q.toStdString();
    fin.open("./AppFile/UserFile/color.txt");
    fout.open("./AppFile/UserFile/tmp.txt");
    while(getline(fin,tmp))
    {
        if(tmp.substr(0,8) != QString::number(ndate).toStdString())
            fout << tmp << endl;
    }
    fin.close(); fout.close();
    fin.open("./AppFile/UserFile/tmp.txt");
    fout.open("./AppFile/UserFile/color.txt");
    while(getline(fin, tmp))
    {
        fout << tmp << endl;
    }
    fout << css_s << endl;
    fin.close(); fout.close();
}
