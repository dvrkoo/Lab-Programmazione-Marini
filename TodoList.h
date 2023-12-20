//
// Created by nick on 9/27/23.
//
#ifndef LAB_MARINI_TODOLIST_H
#define LAB_MARINI_TODOLIST_H

#include "TodoItem.h"
#include "list"
#include "Date.h"
#include <string>

class TodoList {
private:
    std::list<TodoItem> todoItems;

    int completedTodos;
public:
    void editDescription(const std::string &desc, const std::string &new_description);

    int getCompleted() const;

    void deleteTodo(const std::string &desc);

    const std::list<TodoItem> &getTodoItems() const;

    void listTodos() const;

    void addTodo(int year, int month, int day, int hour, int minute, const std::string &input_description);

    void completeTodo(const std::string &desc);

    int getTodosNumber() const;

    void editTodo(const std::string &desc, int option, int value);

    TodoItem getTodo(const std::string &desc) const;

    void setList(std::list<TodoItem> list);

    void clearList();

    void writeFile() const;

    void searchTodo(const std::string &desc) const;

    static std::list<TodoItem> readFile();

    friend std::ostream &operator<<(std::ostream &os, const TodoItem &obj);
};


#endif //LAB_MARINI_TODOLIST_H
