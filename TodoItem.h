//
// Created by nick on 7/10/23.
//

#include "iostream"
#include "Date.h"

#ifndef LAB_MARINI_TODOITEM_H
#define LAB_MARINI_TODOITEM_H


class TodoItem {
private:

    int id;

    bool completed;

    Date DueDate;

    std::string description;
public:
    TodoItem(int id,bool completed, Date date, const std::string_view &new_description);

    ~TodoItem();

    int getId() const;

    std::string getDescription() const;

    bool isCompleted() const;

    void setCompleted(bool val);

    std::string getDueDate() const;

    void editDate(int index, int value);

    bool create(const std::string_view &new_description, int count);

};


#endif //LAB_MARINI_TODOITEM_H
