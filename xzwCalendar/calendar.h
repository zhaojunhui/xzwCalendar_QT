#ifndef CALENDAR_H
#define CALENDAR_H

#include <QMainWindow>
#include <QWidget>
#include <QDate>
//#include <QVector>

#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QMouseEvent>
#include <QTextBrowser>
#include <QScrollArea>
#include "mylabel.h"

class calendar : public QWidget
{
    Q_OBJECT

public:

//     friend class display;

    calendar(QWidget* parent);
    void init_calendar();
    void clear_the_date();

signals:
      void dateChanged();

public slots:

      void on_clicked_find_privious_button();
      void on_clicked_find_next_button();
      //void on_clicked_datecell();
      void on_valueChanged_the_year_spinbox(int);
      void on_valueChanged_the_month_spinbox(int);
      void on_datecell_clicked(int);
      void on_datecell_double_clicked(int);
//      void on_fix_flexible_clicked();

      void change_calendar();
      void change_spinbox();
      void change_label();

//      void on_contain_changed(QString&);


private:

    QDate cur_date;
    int m_year;
    int m_month;
    int m_day;

    QHBoxLayout* lhb1, *lhb2, *lhb3, *mainhb;
    QGridLayout* g;
    QLabel *head_title_label, *year_label, *month_label, *date_label, *title_browser;
    QSpinBox* the_year_spinbox, *the_month_spinbox;
    QPushButton* find_privious_pushbutton, *find_next_pushbutton;
    QVBoxLayout* vb, *vb2;
    QLabel* list_thing_label;
    QScrollArea* scroll_area;
    MyLabel* datecell[42];


};

#endif // CALENDAR_H
