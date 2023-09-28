//
// Created by nick on 9/1/23.
//

#ifndef LAB_MARINI_DATE_H
#define LAB_MARINI_DATE_H


class Date {
private:
    int year;
    int month;
    int day;
    int hours;
    int minutes;
public:
    int getYear() const;

    int getMonth() const;

    int getDay() const;

    int getHours() const;

    int getMinutes() const;

    Date(int year, int month, int day, int hours, int minutes);

    void setYear(int year, bool check);

    void setMonth(int month, bool check);

    void setDay(int day);

    void setHours(int hours);

    void setMinutes(int minutes);

    void checkDate(int day);


public:
};


#endif //LAB_MARINI_DATE_H
