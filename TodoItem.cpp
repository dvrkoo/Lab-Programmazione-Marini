//
// Created by nick on 7/10/23.
//

#include "TodoItem.h"
#include "Date.h"
#include "fstream"
//TODO add Date and time
//TODO save on memory
TodoItem::TodoItem(Date date) : id(0),  completed(false), DueDate(date)  {
}
//TodoItem::~TodoItem() = default;

int TodoItem::getId() const {
    return id;
}

std::string TodoItem::getDescription() {
    return description;
}

bool TodoItem::isCompleted() {
    return completed;
}

std::string TodoItem::getDueDate() {
    std::string date = std::to_string(DueDate.getYear()) + "/" + std::to_string(DueDate.getMonth())+ "/" + std::to_string(DueDate.getDay()) + "/" + std::to_string(DueDate.getHours())+ "/" + std::to_string(DueDate.getMinutes());
    return date;
}
void TodoItem::setCompleted(bool val) {completed = val;}

void getDueDate(int year, int month, int day, int hour, int minute) {

}
bool TodoItem::create(std::string new_description) {
    //generiamo un random int tra 1 e 100
    id = rand() % 100 + 1;
    description = new_description;
    return true;
}




TodoItem::~TodoItem() = default;
