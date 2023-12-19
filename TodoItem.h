//
// Created by nick on 7/10/23.
//

#include "Date.h"
#include "iostream"

#ifndef LAB_MARINI_TODOITEM_H
#define LAB_MARINI_TODOITEM_H

class TodoItem {
private:
  bool completed;

  Date DueDate;

  std::string description;

public:
    TodoItem();

    TodoItem(bool completed, Date date,
             const std::string_view &new_description);

    ~TodoItem();

    std::string getDescription() const;

    bool isCompleted() const;

    void setCompleted(bool val);

    std::string getDueDate() const;

    void editDate(int index, int value);

    bool create(const std::string_view &new_description);

    void serialize(std::ofstream &ofs) const;

    void deserialize(std::ifstream &ifs);
};

#endif // LAB_MARINI_TODOITEM_H
