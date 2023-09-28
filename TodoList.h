//
// Created by nick on 9/27/23.
//
#ifndef LAB_MARINI_TODOLIST_H
#define LAB_MARINI_TODOLIST_H

#include "TodoItem.h"
#include "list"

class TodoList {
private:
    std::list<TodoItem> todoItems;
public:
    const std::list<TodoItem> &getTodoItems() const;

    void setTodoItems(const std::list<TodoItem> &todoItems);

public:
    void listTodos();

    void addTodo(int year, int month, int day, int hour, int minute, std::string &input_description);

    void completeTodo(int id);

    int getTodosNumber();

    void editTodo(int id, int option, int value);
};


#endif //LAB_MARINI_TODOLIST_H
