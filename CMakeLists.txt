cmake_minimum_required(VERSION 3.0)
project(Lab_Marini)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_Marini main.cpp TodoItem.cpp TodoItem.h
        Date.cpp
        Date.h
        HelperFunctions.cpp
        HelperFunctions.h
        TodoList.cpp
        TodoList.h
)
