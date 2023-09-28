//
// Created by nick on 9/27/23.
//

#include "TodoList.h"

void TodoList::listTodos() {
    std::list<TodoItem>::iterator it;
    for (it = todoItems.begin(); it != todoItems.end(); it++) {

        std::string completed = it->isCompleted() ? "done" : "not done";
        std::cout << it->getId() << " | " << it->getDescription() << " | " << completed << " | Due to: "
                  << it->getDueDate() << std::endl;
    }

    if (todoItems.empty()) {
        std::cout << "Add your first todo!" << std::endl;
    }

}

void TodoList::editTodo(int id, int option, int value) {
    std::list<TodoItem>::iterator it;
    for (it = todoItems.begin(); it != todoItems.end(); it++) {
        if (id == it->getId()) {
            it->editDate(option, value);
            break;
        }
        throw std::invalid_argument("Invalid id ");
    }
}

void TodoList::addTodo(int year, int month, int day, int hour, int minute, std::string &input_description) {
    Date date(year, month, day, hour, minute);
    TodoItem newItem(date);
    newItem.create(input_description);
    todoItems.push_back(newItem);
}

void TodoList::completeTodo(int id) {
    std::list<TodoItem>::iterator it;
    for (it = todoItems.begin(); it != todoItems.end(); it++) {

        if (id == it->getId()) {
            it->setCompleted(true);
            break;
        }
        throw std::invalid_argument("Invalid id ");
    }
}

const std::list<TodoItem> &TodoList::getTodoItems() const {
    return todoItems;
}

int TodoList::getTodosNumber() {
    return TodoList::todoItems.size();
}



