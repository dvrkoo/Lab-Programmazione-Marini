#include <iostream>
#include <string>
#include <list>
#include "TodoItem.h"

int main() {
    std::string version = "v0.1.0";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;

    todoItems.clear();

    TodoItem test;
    test.create("this is a test");
    todoItems.push_back(test);

    while (true) {
        system("cls");
        std::cout << "Todo List Maker -- " << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {
            std::cout << it->getId() << " | " << it->getDescription() << " | " << it->isCompleted() << std::endl;
        }

        break;

    }
    return 0;


}
