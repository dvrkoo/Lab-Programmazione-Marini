//
// Created by nick on 9/1/23.
//

#include "Date.h"
#include "iostream"
#include <algorithm>



void Date::serialize(std::ofstream& ofs) const {
    ofs.write(reinterpret_cast<const char*>(&year), sizeof(year));
    ofs.write(reinterpret_cast<const char*>(&month), sizeof(month));
    ofs.write(reinterpret_cast<const char*>(&day), sizeof(day));
    ofs.write(reinterpret_cast<const char*>(&hours), sizeof(hours));
    ofs.write(reinterpret_cast<const char*>(&minutes), sizeof(minutes));
}

// Deserialization method
void Date::deserialize(std::ifstream& ifs) {
    ifs.read(reinterpret_cast<char*>(&year), sizeof(year));
    ifs.read(reinterpret_cast<char*>(&month), sizeof(month));
    ifs.read(reinterpret_cast<char*>(&day), sizeof(day));
    ifs.read(reinterpret_cast<char*>(&hours), sizeof(hours));
    ifs.read(reinterpret_cast<char*>(&minutes), sizeof(minutes));
}
void Date::setYear(int year_, bool check = false) {
    if (year_ > 0) {
        Date::year = year_;
        if (check)Date::checkDate(Date::day);
    } else throw std::invalid_argument("Invalid Year");

}

void Date::setMonth(int month_, bool check = false) {
    bool exceptionThrown;
    if (month_ <= 12 && month_ > 0) {
        int tmp = Date::month;
        Date::month = month_;
        if (check) {
            try {
                checkDate(Date::day);
            }
            catch (std::invalid_argument &) {
                exceptionThrown = true;
            }
            if (exceptionThrown){
                Date::month = tmp;
                throw std::invalid_argument("Invalid month");
            }
        }
    }
}

void Date::checkDate(int day_) {
    int longerMonths[] = {1, 3, 5, 7, 8, 10, 12};
    bool isInArray = std::find(std::begin(longerMonths), std::end(longerMonths), Date::month) != std::end(longerMonths);
    if (Date::month == 2) {
        if (((Date::year % 4 == 0 && Date::year % 100 != 0) || (Date::year % 400 == 0)) && (day_ < 30 && day_ > 0)) {
            Date::day = day_;
        } else if (day_ < 29 && day_ > 0) {
            Date::day = day_;
        } else { throw std::invalid_argument("Invalid Day"); }
    } else if (isInArray && (day_ <= 31 && day_ > 0)) {
        Date::day = day_;
    } else if (day_ < 31 && day_ > 0) {
        Date::day = day_;
    } else {
        throw std::invalid_argument("Invalid day");
    }
}

void Date::setDay(int day_) {
    Date::checkDate(day_);
}

void Date::setHours(int hours_) {
    if (hours_ >= 0 && hours_ <= 24) {
        Date::hours = hours_;
    } else { throw std::invalid_argument("Invalid hours_"); }
}

void Date::setMinutes(int minutes_) {
    if (minutes_ >= 0 && minutes_ <= 60) {
        Date::minutes = minutes_;
    } else { throw std::invalid_argument("Invalid minutes_"); }
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

Date::Date(int year, int month, int day, int hours, int minutes) {
    Date::setYear(year);
    Date::setMonth(month);
    Date::setDay(day);
    Date::setHours(hours);
    Date::setMinutes(minutes);
}

