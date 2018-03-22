#ifndef DATE_H
#define DATE_H

#include <QDate>

class Date : public QDate
{
public:

    Date(int year, int month, int day);
    int how_many_days_in_month();
    int first_date_day(); //返回0-6

private:

    int year_, month_, day_;
};

#endif // DATE_H
