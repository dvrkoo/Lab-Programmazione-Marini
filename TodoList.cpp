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

void TodoList::searchTodo(const std::string &desc) const {
    bool found = false;
    std::cout << desc << std::endl;
    for (auto const &todoItem: TodoList::readFile()) {
        if (desc == todoItem.getDescription()) {
            found = true;
            std::cout << " | " << todoItem.getDescription() << " | " << todoItem.isCompleted() << " | Due to: "
                      << todoItem.getDueDate() << std::endl;
        }
    }
    if (!found) {
        throw std::invalid_argument("Invalid desc");
    }
}

void TodoList::editDescription(const std::string &desc, const std::string &new_description) {
    if (new_description.empty()) {
        throw std::invalid_argument("Invalid desc");
    }
    bool found = false;
    for (auto &todoItem: todoItems) {
        if (desc == todoItem.getDescription()) {
            todoItem.editDescription(new_description);
            found = true;
            break;
        }
    }
    if (!found) {
        throw std::invalid_argument("Invalid desc");
    }
}

void TodoList::editTodo(const std::string &desc, int option, int value) {
    bool found = false;
    for (auto &todoItem: todoItems) {
        if (desc == todoItem.getDescription()) {
            todoItem.editDate(option, value);
            found = true;
            break;
        }
    }
    if (!found) {
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

void TodoList::completeTodo(const std::string &desc) {
    bool found = false;
    for (auto &todoItem: todoItems) {
        if (desc == todoItem.getDescription()) {
            todoItem.setCompleted();
            found = true;
            if (todoItem.isCompleted()) {
                completedTodos += 1;
            } else {
                completedTodos -= 1;
            }
        }
    }
    if (!found) {
        throw std::invalid_argument("Invalid desc");
    }
}

const std::list<TodoItem> &TodoList::getTodoItems() const {
    return todoItems;
}

TodoItem TodoList::getTodo(const std::string &desc) const {
    for (auto const &todoItem: todoItems) {
        if (desc == todoItem.getDescription()) {
            return todoItem;
        }
    }
    throw std::invalid_argument("Invalid desc");
}

void TodoList::clearList() {
    todoItems.clear();
    completedTodos = 0;
}

int TodoList::getTodosNumber() const {
    return int(TodoList::todoItems.size());
}

void TodoList::deleteTodo(const std::string &desc) {
    auto it = std::find_if(todoItems.begin(), todoItems.end(),
                           [&desc](const TodoItem &todoItem) {
                               return desc == todoItem.getDescription();
                           });

    if (it != todoItems.end()) {
        todoItems.erase(it);
    } else {
        throw std::invalid_argument("Invalid desc");
    }
}

// Serialization method

void TodoList::writeFile() const {
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
    if (std::ifstream file("Todos.txt", std::ios::binary); file.is_open()) {
        Date Date(2020, 1, 1, 1, 1);
        TodoItem item(false, Date, "");
        while (file.peek() != EOF) {
            item.deserialize(file);
            items.push_back(item);
        }
        file.close();
        std::cout << "Todo items read from file successfully." << std::endl;
    } else {
        throw std::invalid_argument("Invalid file");
    }
    return items;
};

std::ostream &operator<<(std::ostream &os, const TodoItem &obj) {
    os << " " << obj.isCompleted() << " " << obj.getDueDate() << " " << obj.getDescription();
    return os;
}

int TodoList::getCompleted() const {
    return completedTodos;
}





