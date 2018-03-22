#include "Date.h"

Date::Date(int year, int month, int day)
    : QDate(year,month,day)
{
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::how_many_days_in_month()
{
    switch(month_)
    {
        case 1: return 31;
        case 2: return isLeapYear(year_)?29:28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: break;
    }
}

int Date::first_date_day()
{
    return (50 + dayOfWeek() - day_)%7;
}
