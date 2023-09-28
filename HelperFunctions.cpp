//
// Created by nick on 9/25/23.
//

#include "HelperFunctions.h"

void HelperFunctions::writeFile(std::list<TodoItem> todoItems) {
    std::ofstream file;
    std::list<TodoItem>::iterator it;
    file.open("./Todos.txt", std::ios::app);
    if (!file) {
        std::cout << "Error in opening file..";
    }
    for (it = todoItems.begin(); it != todoItems.end(); it++) {
        file.write((char *) &it, sizeof(it));
    }
    file.close();
}

void HelperFunctions::readFile(std::list<TodoItem> TodoItems) {

};