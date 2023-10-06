//
// Created by nick on 9/25/23.
//
#include <iostream>
#include <fstream>
#include "TodoItem.h"
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#ifndef LAB_MARINI_HELPERFUNCTIONS_H
#define LAB_MARINI_HELPERFUNCTIONS_H


class HelperFunctions {
public:
    static void writeFile(std::list<TodoItem> TodoItems);
    static std::list<TodoItem> readFile();

    friend std::ostream& operator<<(std::ostream& os, const TodoItem& obj) {
        os << obj.getId() << " " << obj.isCompleted() << " " <<  obj.getDueDate() << " " << obj.getDescription();
        return os;
    }

// Deserialization method
};


#endif //LAB_MARINI_HELPERFUNCTIONS_H
