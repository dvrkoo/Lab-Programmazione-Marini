//
// Created by nick on 9/27/23.
//

#include "TodoList.h"

#include <utility>

void TodoList::listTodos() const{
    for (auto const &todoItem: todoItems) {
        std::string completed = todoItem.isCompleted() ? "done" : "not done";
        std::cout << todoItem.getId() << " | " << todoItem.getDescription() << " | " << completed << " | Due to: "
                  << todoItem.getDueDate() << std::endl;
    }
    if (todoItems.empty()) {
        std::cout << "Add your first todo!" << std::endl;
    }

}

void TodoList::editTodo(int id, int option, int value) {
    for (auto &todoItem: todoItems) {
        if (id < 0 || id >= todoItems.size()) {
            throw std::invalid_argument("Invalid id ");
        }
        if (id == todoItem.getId()) {
            todoItem.editDate(option, value);
        }
    }
}

void TodoList::setList(std::list<TodoItem> list){
    todoItems = std::move(list);
}

void TodoList::addTodo(int year, int month, int day, int hour, int minute, const std::string &input_description) {
    Date date(year, month, day, hour, minute);
    TodoItem newItem(count, false, date, input_description);
    todoItems.push_back(newItem);
    count +=1;
}

void TodoList::completeTodo(int id) {
    for (auto &todoItem: todoItems) {
        if (id < 0 || id >= todoItems.size()) {
            throw std::invalid_argument("Invalid id ");
        }
        if (id == todoItem.getId()) {
            todoItem.setCompleted(true);
        }
    }
}

const std::list<TodoItem> &TodoList::getTodoItems() const {
    return todoItems;
}

TodoItem TodoList::getTodo(int id){
    for (auto &todoItem: todoItems) {
        if (id < 0 || id >= todoItems.size()) {
            throw std::invalid_argument("Invalid id ");
        }
        else if (id == todoItem.getId()) {
            return todoItem;
        }
    }
}

void TodoList::clearList(){
    todoItems.clear();
}
int TodoList::getTodosNumber() const {
    return int(TodoList::todoItems.size());
}

TodoList::TodoList() {
    count = 0;
}



