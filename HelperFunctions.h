//
// Created by nick on 9/25/23.
//
#include <iostream>
#include <fstream>
#include "TodoItem.h"
#include <list>

#ifndef LAB_MARINI_HELPERFUNCTIONS_H
#define LAB_MARINI_HELPERFUNCTIONS_H


class HelperFunctions {
public:
    static void writeFile(std::list<TodoItem> TodoItems);
    static void readFile(std::list<TodoItem> TodoItems);
};


#endif //LAB_MARINI_HELPERFUNCTIONS_H
