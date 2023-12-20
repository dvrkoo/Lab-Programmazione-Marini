#include <iostream>
#include <string>
#include "TodoItem.h"
#include <fstream>
#include "TodoList.h"

int main() {
    char input_option;
    std::string input_desc;
    std::string version = "v0.5.0";
    TodoList todos;
    std::string input_description;
    std::ofstream file;

    while (true) {
        //system("cls"); NOTE: Clion doesn't really allow you to clear console :(
        std::cout << "Todo List Maker -- " << version << std::endl;
        std::cout << std::endl << std::endl;
        std::cout << "Todo number: " << todos.getTodosNumber() << std::endl;
        std::cout << "Completed Todos: " << todos.getCompleted() << std::endl;
        todos.listTodos();

        std::cout << std::endl;

        std::cout << "[a]dd a new Todo " << std::endl;
        std::cout << "[c]omplete a Todo " << std::endl;
        std::cout << "[d]elete a Todo " << std::endl;
        std::cout << "[e]dit a Todo " << std::endl;
        std::cout << "[f]ind a Todo " << std::endl;
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

            if (!(std::cin >> year >> month >> day >> hour >> minute)) {
                std::cerr << "Invalid input for Date and time." << std::endl;
                std::cin.clear();
                while (std::cin.get() != '\n'); // Clear the input buffer
                continue; // Skip the current iteration of the loop
            }
            while (std::cin.get() != '\n'); // Clear the input buffer
            std::cin.clear();
            std::cin.ignore();
            todos.addTodo(year, month, day, hour, minute, input_description);
        } else if (input_option == 'c') {
            std::cout << "Enter description to mark completed: ";
            std::cin >> input_desc;
            todos.completeTodo(input_desc);
            std::cin.clear();
            std::cin.ignore();
        } else if (input_option == 's') {
            std::cin.clear();
            std::cin.ignore();
            todos.writeFile();
            std::cout << "Saving to file ";
        } else if (input_option == 'r') {
            todos.setList(TodoList::readFile());
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
            std::cout << "6 edit description" << std::endl;
            std::string desc;
            int option;
            int value;
            while (true) {
                if (!(std::cin >> desc >> option >> value)) {
                    std::cerr << "Invalid input for description, option, or value. Please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character
                    break; // Break the loop if the input is valid
                }
            }
            if (option == 6) {
                std::cout << "Enter new description: ";
                std::string new_desc;
                std::getline(std::cin, new_desc);
                todos.editDescription(desc, new_desc);
            }
            else{
                todos.editTodo(desc, option, value);
            }
        }
        else if (input_option == 'd'){
            std::cout << "Enter description to delete: ";
            std::cin >> input_desc;
            todos.deleteTodo(input_desc);
            std::cin.clear();
            std::cin.ignore();
        }
        else if (input_option == 'f'){
            std::cout << "Enter description to search: ";
            std::cin >> input_desc;
            todos.searchTodo(input_desc);
            std::cin.clear();
            std::cin.ignore();
        }
        else {
            std::cout << "Invalid option" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }

    }
    return 0;
}
