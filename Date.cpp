//
// Created by nick on 9/1/23.
//

#include "Date.h"
#include "iostream"
#include <algorithm>

void Date::setYear(int year_) {
    if(year_ > 0)Date::year = year_;
    else throw std::invalid_argument("Invalid Year");

}

void Date::setMonth(int month_) {
    if (month_ <= 12 && month_ > 0) {
        Date::month = month_;
    }
    else { throw std::invalid_argument("Invalid Month"); }
}

void Date::setDay(int day_) {
    int longerMonths[] ={1, 3, 5,7, 8 ,10, 12};
    bool isInArray = std::find(std::begin(longerMonths), std::end(longerMonths), Date::month) != std::end(longerMonths);
    if(Date::month == 2){
        if (((Date::year % 4 == 0 && Date::year % 100 != 0) || (Date::year % 400 == 0)) && (day_ < 30 && day_ > 0)) {
            Date::day = day_;
        }
        else if (day_ < 29 && day_ > 0) {
            Date::day = day_ ;
        }
    }
    else if(isInArray && (day_ <= 31 && day_ > 0)) {
        Date::day = day_;
    }
    else if (day_ < 31 and day_ > 0){
        Date::day = day_;
    }
    else {
        throw std::invalid_argument("Invalid day");
    }


}

void Date::setHours(int hours) {
    if (hours >= 0 && hours <= 24){
    Date::hours= hours;
    }
    else {throw std::invalid_argument("Invalid hours");}
}

void Date::setMinutes(int minutes) {
    if (minutes >= 0 && minutes <=60){
    Date::minutes = minutes;
    }
    else {throw std::invalid_argument("Invalid minutes");}
}

Date::Date(int year, int month, int day, int hours, int minutes) {
    Date::setYear(year);
    Date::setMonth(month);
    Date::setDay(day);
    Date::setHours(hours);
    Date::setMinutes(minutes);
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getHours() const {
    return hours;
}

int Date::getMinutes() const {
    return minutes;
}
