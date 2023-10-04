#include <iostream>
#include <string>
#include "TodoItem.h"
#include "HelperFunctions.h"
#include <fstream>
#include "TodoList.h"

int main() {
    char input_option;
    int input_id;
    std::string version = "v0.5.0";
    TodoList todos;
    std::string input_description;
    std::ofstream file;

    while (true) {
        //system("cls"); NOTE: Clion doesn't really allow you to clear console :(
        std::cout << "Todo List Maker -- " << version << std::endl;
        std::cout << std::endl << std::endl;
        std::cout << "Todo number: " << todos.getTodosNumber() << std::endl;
        todos.listTodos();

        std::cout << std::endl;

        std::cout << "[a]dd a new Todo " << std::endl;
        std::cout << "[c]omplete a Todo " << std::endl;
        std::cout << "[e]dit a Todo " << std::endl;
        std::cout << "[s]ave to file" << std::endl;
        std::cout << "[r]ead from file" << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "choice: ";

        std::cin >> input_option;

        if (input_option == 'q') {
            std::cout << "GoodBye!" << std::endl;
            break;
        } else if (input_option == 'a') {
            std::cout << "Add a new description:";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_description);

            std::cout << "Enter a custom Date and time (YYYY MM DD HH MM): ";
            int year, month, day, hour, minute;
            std::cin >> year >> month >> day >> hour >> minute;
            std::cin.clear();
            std::cin.ignore();
            todos.addTodo(year, month, day, hour, minute, input_description);
        } else if (input_option == 'c') {
            std::cout << "Enter id to mark completed: ";
            std::cin >> input_id;
            todos.completeTodo(input_id);
            std::cin.clear();
            std::cin.ignore();
        } else if (input_option == 's') {
            std::cin.clear();
            std::cin.ignore();
            HelperFunctions::writeFile(todos.getTodoItems());
            std::cout << "Saving to file ";
        } else if (input_option == 'r') {
            HelperFunctions::readFile(todos.getTodoItems());
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Reading from file ";
        } else if (input_option == 'e') {
            std::cout << "Enter ID OPTION VALUE" << std::endl;
            std::cout << "1 edit year" << std::endl;
            std::cout << "2 edit month" << std::endl;
            std::cout << "3 edit day" << std::endl;
            std::cout << "4 edit hour" << std::endl;
            std::cout << "5 edit minutes" << std::endl;
            int id, option, value;
            std::cin >> id >> option >> value;
            todos.editTodo(id, option, value);
            std::cin.clear();
            std::cin.ignore();
        }
    }
    return 0;
}