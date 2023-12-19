//
// Created by nick on 9/27/23.
//
#ifndef LAB_MARINI_TODOLIST_H
#define LAB_MARINI_TODOLIST_H

#include "TodoItem.h"
#include "list"
#include <string>

class TodoList {
private:
    std::list<TodoItem> todoItems;

    int completedTodos;
public:
    int getCompleted() const;

    void deleteTodo(std::string desc);

    TodoList();

    const std::list<TodoItem> &getTodoItems() const;

    void listTodos() const;

    void addTodo(int year, int month, int day, int hour, int minute, const std::string &input_description);

    void completeTodo(std::string desc);

    int getTodosNumber() const;

    void editTodo(std::string desc, int option, int value);

    TodoItem getTodo(std::string desc);

    void setList(std::list<TodoItem> list);

    void clearList();

    static void writeFile(std::list<TodoItem> TodoItems);

    static std::list<TodoItem> readFile();

    friend std::ostream &operator<<(std::ostream &os, const TodoItem &obj);
};


#endif //LAB_MARINI_TODOLIST_H
