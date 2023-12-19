//
// Created by nick on 9/27/23.
//

#include "TodoList.h"

#include <string>
#include <utility>

void TodoList::listTodos() const {
    for (auto const &todoItem: todoItems) {
        std::string completed = todoItem.isCompleted() ? "done" : "not done";
        std::cout << " | " << todoItem.getDescription() << " | " << completed << " | Due to: "
                  << todoItem.getDueDate() << std::endl;
    }
    if (todoItems.empty()) {
        std::cout << "Add your first todo!" << std::endl;
    }

}

void TodoList::editTodo(std::string desc, int option, int value) {
    for (auto &todoItem: todoItems) {
        if (desc == todoItem.getDescription()) {
            todoItem.editDate(option, value);
            break;
        }
        throw std::invalid_argument("Invalid desc");
    }
}

void TodoList::setList(std::list<TodoItem> list) {
    todoItems = std::move(list);
}

void TodoList::addTodo(int year, int month, int day, int hour, int minute, const std::string &input_description) {
    Date date(year, month, day, hour, minute);
    TodoItem newItem(false, date, input_description);
    todoItems.push_back(newItem);
}

void TodoList::completeTodo(std::string desc) {
    for (auto &todoItem: todoItems) {
        if (desc == todoItem.getDescription() && !todoItem.isCompleted()) {
            todoItem.setCompleted(true);
            completedTodos += 1;
        }
    }
}

const std::list<TodoItem> &TodoList::getTodoItems() const {
    return todoItems;
}

TodoItem TodoList::getTodo(std::string desc) {
    for (auto &todoItem: todoItems) {
        if (desc == todoItem.getDescription()) {
            return todoItem;
        }
    }
}

void TodoList::clearList() {
    todoItems.clear();
}

int TodoList::getTodosNumber() const {
    return int(TodoList::todoItems.size());
}

TodoList::TodoList() {
}

void TodoList::deleteTodo(std::string desc) {
    auto it = std::find_if(todoItems.begin(), todoItems.end(),
                           [desc](const TodoItem &todoItem) {
                               return desc == todoItem.getDescription();
                           });

    if (it != todoItems.end()) {
        todoItems.erase(it);
    } else {
        throw std::invalid_argument("Invalid desc");
    }
}

// Serialization method

void TodoList::writeFile(std::list<TodoItem> todoItems) {
    std::ofstream file("Todos.txt", std::ios::binary);

    if (file.is_open()) {
        for (const TodoItem &item: todoItems) {
            item.serialize(file);
        }
        file.close();
        std::cout << "Todo items written to file successfully." << std::endl;
    } else {
        std::cerr << "Failed to open the file for writing." << std::endl;
    }
}

std::list<TodoItem> TodoList::readFile() {
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

std::ostream &operator<<(std::ostream &os, const TodoItem &obj) {
    os << " " << obj.isCompleted() << " " << obj.getDueDate() << " " << obj.getDescription();
    return os;
}

int TodoList::getCompleted() const {
    return completedTodos;
};





