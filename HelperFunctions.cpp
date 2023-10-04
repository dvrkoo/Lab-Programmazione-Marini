//
// Created by nick on 9/25/23.
//

#include "HelperFunctions.h"

void HelperFunctions::writeFile(std::list<TodoItem> todoItems) {
    std::ofstream file;
    file.open("./Todos.txt", std::ios::app);
    if (!file) {
        throw std::invalid_argument("Error in opening file..");
    }
    for (auto &todoItem: todoItems) {
        file.write((char *) &todoItem, sizeof(todoItem));
    }
    file.close();
}

void HelperFunctions::readFile(std::list<TodoItem> TodoItems) {
};