//
// Created by nick on 7/10/23.
//

#include "iostream"
#include "DateTime.h"
#include "Date.h"

#include "Date.h"

#ifndef LAB_MARINI_TODOITEM_H
#define LAB_MARINI_TODOITEM_H


class TodoItem {
private:

    int id;
    std::string description;
    bool completed;

    Date DueDate;

public:
    TodoItem(Date date);

    ~TodoItem();

    int getId() const;

    std::string getDescription();

    bool isCompleted();

    bool create(std::string new_description);

    void setCompleted(bool val);

    std::string getDueDate();

    void saveToFile(const std::string &filename) const;

    void readFromFile(const std::string &filename);

    std::string serialize() const;

    bool deserialize(const std::string &data);
};


#endif //LAB_MARINI_TODOITEM_H
