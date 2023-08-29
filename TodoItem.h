//
// Created by nick on 7/10/23.
//

#include "iostream"

#ifndef LAB_MARINI_TODOITEM_H
#define LAB_MARINI_TODOITEM_H


class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem();

    ~TodoItem();

    int getId() const;

    std::string getDescription();

    bool isCompleted();

    bool create(std::string new_description);

    void setCompleted(bool val);
};


#endif //LAB_MARINI_TODOITEM_H
