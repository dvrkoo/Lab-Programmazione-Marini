#include <iostream>
#include <string>
#include <list>
#include "TodoItem.h"


int main() {
    //TODO Code refactoring
    char input_option;
    int input_id;
    std::string version = "v0.3.0";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;
    std::string input_description;

    srand(time(NULL));
    todoItems.clear();

    //TodoItem test;
    //test.create("this is a test");
    //todoItems.push_back(test);
    while (true) {
        //system("cls"); NOTE: Clion doesn't really allow you to clear console :(
        std::cout << "Todo List Maker -- " << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            std::string completed = it->isCompleted() ? "done" : "not done";
            std::cout << it->getId() << " | " << it->getDescription() << " | " << completed << " | Due to: "<< it->getDueDate() << std::endl;
        }

        if (todoItems.empty() ){
            std::cout << "Add your first todo!" << std::endl;
        }

        std::cout << std::endl;

        std::cout << "[a]dd a new Todo " << std::endl;
        std::cout << "[c]omplete a Todo " << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "choice: " ;

        std::cin >> input_option;

        if (input_option == 'q'){
            std::cout << "GoodBye!" << std::endl;
            break;
        }
        else if (input_option == 'a') {
            std::cout << "Add a new description:";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_description);

            std::cout << "Enter a custom Date and time (YYYY MM DD HH MM): ";
            int year, month, day, hour, minute, second;
            std::cin >> year >> month >> day >> hour >> minute ;
            std::cin.clear();
            std::cin.ignore();
            Date date(year,month,day,hour,minute) ;
            TodoItem newItem(date);
            newItem.create(input_description);
            todoItems.push_back(newItem);
        }
        else if (input_option == 'c') {
            //TODO handle better invalid id
            std::cout << "Enter id to mark completed: ";
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {

                if (input_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }
            std::cout << "Invalid Id" << std::endl;

        }
        else if (input_option == 's'){

        }
    }
    return 0;


}

