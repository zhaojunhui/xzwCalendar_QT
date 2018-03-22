#include <QLayout>
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
#include <QDebug>
#include <fstream>
#include <sstream>
#include <string>
#include "calendar.h"
#include "Date.h"
#include "mylabel.h"
#include "mydialog.h"
#include "myinputdialog.h"

using namespace std;

extern int main_width, main_height;
extern int main_x, main_y;

calendar::calendar(QWidget* parent)
    : QWidget(parent)
{
    init_calendar();

    connect(find_privious_pushbutton,SIGNAL(clicked()),this,SLOT(on_clicked_find_privious_button()));
    connect(find_next_pushbutton,SIGNAL(clicked()),this,SLOT(on_clicked_find_next_button()));
//    connect(fix_flexible,SIGNAL(clicked()),this,SLOT(on_fix_flexible_clicked()));
    connect(the_year_spinbox,SIGNAL(valueChanged(int)),this,SLOT(on_valueChanged_the_year_spinbox(int)));
    connect(the_month_spinbox,SIGNAL(valueChanged(int)),this,SLOT(on_valueChanged_the_month_spinbox(int)));

    connect(this,SIGNAL(dateChanged()),this,SLOT(change_calendar()));
    connect(this,SIGNAL(dateChanged()),this,SLOT(change_spinbox()));
    connect(this,SIGNAL(dateChanged()),this,SLOT(change_label()));
}

void calendar::init_calendar()
{
    m_year = QDate::currentDate().year();
    m_month = QDate::currentDate().month();
    m_day = QDate::currentDate().day();

    lhb1 = new QHBoxLayout;
    lhb1->setMargin(0);
    lhb1->setContentsMargins(0,0,-1,-1);
    lhb1->setSpacing(0);
    head_title_label = new QLabel("xzwCalendar");
    //head_title_label->setAlignment(Qt::AlignLeft);
    QFont ft;
    ft.setItalic(true);
    ft.setPointSize(40);
    ft.setFamily("Time");
    head_title_label->setFont(ft);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    head_title_label->setPalette(pa);
    head_title_label->setStyleSheet("background: rgb(255, 255, 255); border: 1px solid rgb(116,128,148)");
    the_year_spinbox = new QSpinBox;
    the_year_spinbox->setRange(0,2030);
    the_year_spinbox->setValue(m_year);
    the_year_spinbox->setFocusPolicy(Qt::ClickFocus);
    the_year_spinbox->setStyleSheet("border: 1px solid rgb(116,128,148)");
    //the_year_spinbox->setStyleSheet("base: #F0FFFF; border: 1px solid #F7F7F7");
    year_label = new QLabel(tr("年"));
    the_month_spinbox = new QSpinBox;
    the_month_spinbox->setRange(1,12);
    the_month_spinbox->setValue(m_month);
    the_month_spinbox->setFocusPolicy(Qt::ClickFocus);
    the_month_spinbox->setStyleSheet("border: 1px solid rgb(116,128,148)");
    month_label = new QLabel(tr("月"));
    find_privious_pushbutton = new QPushButton("<");
    find_privious_pushbutton->setStyleSheet("border: 1px solid rgb(116,128,148)");
    date_label = new QLabel(QString::number(m_year) + "." + QString::number(m_month) + "." + QString::number(m_day));
    find_next_pushbutton = new QPushButton(">");
    find_next_pushbutton->setStyleSheet("border: 1px solid rgb(116,128,148)");
    lhb1->addWidget(head_title_label);
    lhb1->addSpacerItem(new QSpacerItem(10,10));
    lhb1->addWidget(the_year_spinbox);
    lhb1->addWidget(year_label);
    lhb1->addWidget(the_month_spinbox);
    lhb1->addWidget(month_label);
    lhb1->addWidget(find_privious_pushbutton);
    lhb1->addWidget(date_label);
    lhb1->addWidget(find_next_pushbutton);

    //QWidget* w2 =new QWidget;
    lhb2 = new QHBoxLayout;
    QString the_day[] = {tr("星期日"),tr("星期一"),tr("星期二"),tr("星期三"),tr("星期四"),tr("星期五"),tr("星期六")};
    lhb2->setSpacing(0);
    lhb2->setContentsMargins(0,0,0,0);
    lhb2->setMargin(0);
    for(int i = 0; i < 7; i++)
    {
        //QWidget* tmp_widget = new QWidget;
        //tmp_widget->setBaseSize(40,40);
        QLabel* tmp_label = new QLabel(the_day[i], this);
        tmp_label->setAlignment(Qt::AlignCenter);
        QFont ft;
        ft.setPointSize(15);
        ft.setFamily(("STHeiti"));
        tmp_label->setFont(ft);
        tmp_label->setStyleSheet("background-color: rgb(254,204,197)");
//        tmp_label->setAlignment(Qt::AlignCenter);
//        QFont font("Helvetica",10,2);
//        tmp_label->setFont(font);
        lhb2->addWidget(tmp_label);
    }


    g = new QGridLayout;
    g->setHorizontalSpacing(0);
    g->setVerticalSpacing(0);
    Date* date =  new Date(m_year,m_month,m_day);
    int num_of_month = date->how_many_days_in_month();
    int first_of_month = date->first_date_day();
    ifstream fin; string tmp;
    for(int i = 0; i < 42; i++)
    {
        datecell[i] = new MyLabel("", this, m_year, m_month, m_day);
        datecell[i]->setAlignment(Qt::AlignCenter);
        QFont ft;
        ft.setPointSize(20);
        datecell[i]->setFont(ft);
        datecell[i]->setContentsMargins(1,1,1,1);
        datecell[i]->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
        g->addWidget(datecell[i], i/7, i%7);
    }
    clear_the_date();
    for(int i = 1; i <= num_of_month; i++)
    {
        int i_date = m_year*10000 + m_month*100 + i;
        QString i_date_q = QString::number(i_date);
        string i_date_s = i_date_q.toStdString();
        fin.open("./AppFile/UserFile/color.txt");
        while(getline(fin, tmp))
        {
            if(tmp.substr(0,8) == i_date_s)
            {
                QString css =QString::fromStdString(tmp.substr(9, tmp.length() - 9));
                qDebug() << css;
                datecell[i + first_of_month - 1]->setStyleSheet(css);
                break;
            }
        }
        fin.close();
        datecell[i + first_of_month - 1]->setDate(m_year, m_month, i);
        datecell[i + first_of_month - 1]->set_filename_list();
        datecell[i + first_of_month - 1]->set_text();
        connect(datecell[i + first_of_month - 1],SIGNAL(clicked(int)),this,SLOT(on_datecell_clicked(int)));
        connect(datecell[i + first_of_month - 1],SIGNAL(double_clicked(int)),this,SLOT(on_datecell_double_clicked(int)));
        connect(datecell[i + first_of_month - 1],SIGNAL(sth_changed()),this,SLOT(change_calendar()));
    }

    vb = new QVBoxLayout;
    vb->addLayout(lhb1);
    vb->addLayout(lhb2);
    vb->addLayout(g, 1);

    vb2 = new QVBoxLayout;
    title_browser = new QLabel;
    QFont ft_browser;
    ft_browser.setItalic(true);
    ft_browser.setPointSize(40);
    title_browser->setFont(ft_browser);
    title_browser->setText(tr("待办事项\n"));
    title_browser->setStyleSheet("background-color: rgb(254,204,197)");

    scroll_area = new QScrollArea;
    scroll_area->setFixedWidth(250);
    scroll_area->setMinimumHeight(400);
    list_thing_label = new QLabel;;
    list_thing_label->setMinimumWidth(2000);
    list_thing_label->setMinimumHeight(600);
    list_thing_label->setAlignment(Qt::AlignLeft);
    QFont ft_list;
    ft_list.setPointSize(18);
    ft_list.setFamily(("STHeiti"));
    list_thing_label->setFont(ft_list);
    list_thing_label->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
    scroll_area->setWidget(list_thing_label);

    vb2->addWidget(title_browser);
    vb2->addWidget(scroll_area);

    mainhb = new QHBoxLayout(this);
    mainhb->addLayout(vb);
    mainhb->addLayout(vb2);
}

void calendar::clear_the_date()
{
    for(int i = 0; i < 42; i++)
    {
        datecell[i]->setText("");
        datecell[i]->setStyleSheet("border:1px solid rgb(206,218,238);background-color: rgb(255,255,255);");
        disconnect(datecell[i],SIGNAL(clicked(int)),this,SLOT(on_datecell_clicked(int)));
        disconnect(datecell[i],SIGNAL(double_clicked(int)),this,SLOT(on_datecell_double_clicked(int)));
        disconnect(datecell[i],SIGNAL(sth_changed()),this,SLOT(change_calendar()));
    }
}

void calendar::on_clicked_find_privious_button()
{
    if(m_month != 1) m_month--;
    else
    {
        m_year--;
        m_month = 12;
    }
    emit dateChanged();
}

void calendar::on_clicked_find_next_button()
{
    if(m_month != 12) m_month++;
    else
    {
        m_year++;
        m_month = 1;
    }
    emit dateChanged();
}
void calendar::on_valueChanged_the_year_spinbox(int i)
{
    if(m_year != i)
    {
        m_year = i;
        emit dateChanged();
    }
}

void calendar::on_valueChanged_the_month_spinbox(int i)
{
    if(m_month != i)
    {
        m_month = i;
        emit dateChanged();
    }
}


void calendar::change_calendar()
{
    clear_the_date();
    Date* date =  new Date(m_year,m_month,m_day);
    int num_of_month = date->how_many_days_in_month();
    int first_of_month = date->first_date_day();
    ifstream fin; string tmp;
    for(int i = 1; i <= num_of_month; i++)
    {
        int i_date = m_year*10000 + m_month*100 + i;
        QString i_date_q = QString::number(i_date);
        string i_date_s = i_date_q.toStdString();

        datecell[i + first_of_month - 1]->setDate(m_year, m_month, i);
        datecell[i + first_of_month - 1]->set_filename_list();
        datecell[i + first_of_month - 1]->set_text();

        fin.open("./AppFile/UserFile/color.txt");
        while(getline(fin, tmp))
        {
            if(tmp.substr(0,8) == i_date_s)
            {
                QString css =QString::fromStdString(tmp.substr(9, tmp.length() - 9));
                qDebug() << css;
                datecell[i + first_of_month - 1]->setStyleSheet(css);
                break;
            }
        }
        fin.close();
        connect(datecell[i + first_of_month - 1],SIGNAL(clicked(int)),this,SLOT(on_datecell_clicked(int)));
        connect(datecell[i + first_of_month -1],SIGNAL(double_clicked(int)),this,SLOT(on_datecell_double_clicked(int)));
        connect(datecell[i + first_of_month - 1],SIGNAL(sth_changed()),this,SLOT(change_calendar()));
    }
}

void calendar::change_spinbox()
{
    the_year_spinbox->setValue(m_year);
    the_month_spinbox->setValue(m_month);
}

void calendar::change_label()
{
    date_label->setText(QString::number(m_year) + "." + QString::number(m_month) + "." + QString::number(m_day));
    ifstream fin;
    fin.open("./AppFile/UserFile/" + QString::number(m_month).toStdString() + "_" + QString::number(m_day).toStdString() + ".txt");
    string tmp;
    stringstream ss; ss.clear();
    int ndate = m_year*10000 + m_month*100 +m_day;
    string ndate_s = QString::number(ndate).toStdString();
    while(getline(fin, tmp))
    {
        if(tmp.substr(0, 8) == ndate_s)
            ss << tmp.substr(9,tmp.length() - 9) << "\n";
    }
    list_thing_label->setText(QString::fromStdString(ss.str()));
    fin.close();
}

void calendar::on_datecell_clicked(int i)
{
    if(m_day == i) return;
    m_day = i;
    emit dateChanged();
}

void calendar::on_datecell_double_clicked(int i)
{
    if(m_day != i)
    {
        m_day = i;
        emit dateChanged();
    }
    MyDialog* d = new MyDialog(this, m_year, m_month, m_day);
    connect(d,SIGNAL(sth_changed()),this,SLOT(change_calendar()));
    d->exec();
}


//void calendar::open_thing_file(int year, int month, int day)
//{
//    ifstream fin;
//    string filename = (string)year + "_" + (string)month + "_" + (string)day +  "_thing.txt";
//    fin.open("./AppFile/UserFile/" + filename);
//    string todolist;
//    fin >> todolist;
//}

//void calendar::change_thing_file(QString &s, int year, int month, int day)
//{
//    ofstream fout;
//    string filename = (string)year + "_" + (string)month + "_" + (string)day + "_thing.txt";
//    fout.open("./AppFile/UserFile/" + filename);
//    string ss = s.toStdString();
//    fout << ss;
//}


//void calendar::on_fix_flexible_clicked()
//{
//    if(fix_flexible->text() == tr("固定"))
//    {
//        fix_flexible->setText(tr("移动"));
//        this->setEnabled(false);
//        fix_flexible->setEnabled(true);
//        return;
//    }
//    if(fix_flexible->text() == tr("移动"))
//    {
//        fix_flexible->setText(tr("固定/移动"));
//        this->setEnabled(true);
//        fix_flexible->setEnabled(true);
//        return;
//    }
//}

//void calendar::init_calendar()
//{
//    QString the_day[7] = {"星期日","星期一","星期二","星期三","星期四","星期五","星期六"};
//    QHBoxLayout* THE_DAY = new QHBoxLayout(this);
//    THE_DAY->setSpacing(0);

//    for(int i = 0; i < 7; i++)
//    {
//        QWidget* tmp_widget = new QWidget(this);
//        tmp_widget->setBaseSize(40,40);
//        QLabel* tmp_label = new QLabel(the_day[7],tmp_widget);
//   //     tmp_label->setAlignment(1);
//        QFont font("Helvetica",10,2);
//        tmp_label->setFont(font);
//        THE_DAY->addWidget(tmp_label,0,0);
//    }
//    setLayout(THE_DAY);
//}
