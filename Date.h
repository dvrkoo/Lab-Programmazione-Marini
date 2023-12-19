//
// Created by nick on 9/1/23.
//

#ifndef LAB_MARINI_DATE_H
#define LAB_MARINI_DATE_H

#include <fstream>

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

    void setHours(int hours_);

    void setMinutes(int minutes_);

    void checkDate(int day);

    void serialize(std::ofstream &ofs) const;

    void deserialize(std::ifstream &ifs);
};


#endif //LAB_MARINI_DATE_H
