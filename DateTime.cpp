//
// Created by nick on 9/1/23.
//

#include "DateTime.h"

#include <iostream>
#include <ctime>
#include <string>

DateTime::DateTime() {
    update();
}
DateTime::DateTime(std::time_t time) : time(time) {}

DateTime::~DateTime() {

}

void DateTime::update() {
    std::time(&time);
}

std::string DateTime::getCurrentDateTime() const {
  return std::ctime(&time);
}

void setDateTime(std::time_t time) {
    time = time;
}
