cmake_minimum_required(VERSION 3.14)
project(LaboratorioProgrammazione)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(googleTest)


set(SOURCE_FILES main.cpp main.cpp TodoItem.cpp TodoItem.h
        Date.cpp
        Date.h
        TodoList.cpp
        TodoList.h
        googleTest/Tests.cpp
)
add_executable(LaboratorioProgrammazione main.cpp TodoItem.cpp TodoItem.h
        Date.cpp
        Date.h
        TodoList.cpp
        TodoList.h
)
add_library(core ${SOURCE_FILES}
        )
target_link_libraries(core gtest)
