//
// Created by nick on 7/10/23.
//

#include "TodoItem.h"
#include "ctime"

//TODO add date and time
//TODO save on memory
TodoItem::TodoItem() : id(0),  completed(false) {}
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

void TodoItem::setCompleted(bool val) {completed = val;}

bool TodoItem::create(std::string new_description) {
    //generiamo un random int tra 1 e 100
    id = rand() % 100 + 1;
    description = new_description;
    return true;
}

TodoItem::~TodoItem() = default;
