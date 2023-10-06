//
// Created by nick on 9/25/23.
//

#include "HelperFunctions.h"
// Serialization method

void HelperFunctions::writeFile(std::list<TodoItem> todoItems) {
    std::ofstream file("Todos.txt", std::ios::binary);

    if (file.is_open()) {
        for (const TodoItem& item : todoItems) {
            item.serialize(file);
        }
        file.close();
        std::cout << "Todo items written to file successfully." << std::endl;
    } else {
        std::cerr << "Failed to open the file for writing." << std::endl;
    }
}

std::list<TodoItem> HelperFunctions::readFile() {
    std::list<TodoItem> items;
    std::ifstream file("Todos.txt", std::ios::binary);

    if (file.is_open()) {
        TodoItem item;
        while (file.peek() != EOF) {
            item.deserialize(file);
            items.push_back(item);
        }
        file.close();
        std::cout << "Todo items read from file successfully." << std::endl;
    } else {
        std::cerr << "Failed to open the file for reading." << std::endl;
    }
    return items;
};