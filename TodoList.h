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

    int count;

public:

    explicit TodoList();

    const std::list<TodoItem> &getTodoItems() const;

    void listTodos() const;

    void addTodo(int year, int month, int day, int hour, int minute, const std::string &input_description);

    void completeTodo(int id);

    int getTodosNumber() const;

    void editTodo(int id, int option, int value);

    TodoItem getTodo(int id);
};


#endif //LAB_MARINI_TODOLIST_H
