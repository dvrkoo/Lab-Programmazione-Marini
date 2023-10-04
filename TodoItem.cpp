//
// Created by nick on 7/10/23.
//

#include "TodoItem.h"
#include "Date.h"


TodoItem::TodoItem(int id, bool completed, Date date, const std::string_view &new_description) : id(id),
                                                                                                 completed(completed),
                                                                                                 DueDate(date),
                                                                                                 description(
                                                                                                         new_description) {

}
//TodoItem::~TodoItem() = default;

int TodoItem::getId() const {
    return id;
}

std::string TodoItem::getDescription() const {
    return description;
}

bool TodoItem::isCompleted() const {
    return completed;
}

std::string TodoItem::getDueDate() const {
    std::string date = std::to_string(DueDate.getYear()) + "/" + std::to_string(DueDate.getMonth()) + "/" +
                       std::to_string(DueDate.getDay()) + "/" + std::to_string(DueDate.getHours()) + ":" +
                       std::to_string(DueDate.getMinutes());
    return date;
}

void TodoItem::setCompleted(bool val) { completed = val; }

void TodoItem::editDate(int index, int value) {
    switch (index) {
        case 1:
            DueDate.setYear(value, true);
            break;
        case 2:
            DueDate.setMonth(value, true);
            break;
        case 3:
            DueDate.setDay(value);
            break;
        case 4:
            DueDate.setHours(value);
            break;
        case 5:
            DueDate.setMinutes(value);
            break;
        default:
            throw std::invalid_argument("invalid option");
    }
}

bool TodoItem::create(const std::string_view &new_description, int count) {
    id = count;
    description = new_description;
    return true;
}

TodoItem::~TodoItem() = default;
