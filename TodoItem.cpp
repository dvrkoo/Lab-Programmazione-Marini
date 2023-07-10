//
// Created by nick on 7/10/23.
//

#include "TodoItem.h"


TodoItem::TodoItem() : id(0), description(""), completed(false) {}

int TodoItem::getId() {
    return id;
}

std::string TodoItem::getDescription() {
    return description;
}

bool TodoItem::isCompleted() {
    return false;
}

bool TodoItem::create(std::string new_description) {
    //generiamo un random int tra 1 e 100
    id = rand() % 100 + 1;
    description = new_description;
    return true;
}

TodoItem::~TodoItem() = default;
