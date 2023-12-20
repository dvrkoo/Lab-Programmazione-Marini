//
// Created by nick on 10/17/23.
//
#include "gtest/gtest.h"
#include "../TodoList.h"

class TodoListTest : public ::testing::Test {
protected:
    TodoList TodoList;
};

TEST_F(TodoListTest, TestConstructor) {
    ASSERT_EQ(TodoList.getTodosNumber(), 0);
}

TEST_F(TodoListTest, TestAddTodo) {
    ASSERT_EQ(TodoList.getTodosNumber(), 0);
    TodoList.addTodo(2022, 12, 31, 14, 30, "festa");
    ASSERT_EQ(TodoList.getTodosNumber(), 1);
    ASSERT_EQ(TodoList.getTodo("festa").getDueDate(), "2022/12/31/14:30");
}

TEST_F(TodoListTest, TestEditTodo) {
    TodoList.addTodo(2022, 12, 31, 14, 30, "festa");
    ASSERT_EQ(TodoList.getTodosNumber(), 1);
    TodoList.editTodo("festa", 3, 12);
    ASSERT_EQ(TodoList.getTodo("festa").getDueDate(), "2022/12/12/14:30");
    TodoList.editDescription("festa", "festa di compleanno");
    ASSERT_EQ(TodoList.getTodoItems().front().getDescription(), "festa di compleanno");
    ASSERT_THROW(TodoList.editDescription("festa", ""), std::invalid_argument);
    ASSERT_THROW(TodoList.editDescription("", "festa"), std::invalid_argument);
}

TEST_F(TodoListTest, CompleteTodo) {
    TodoList.addTodo(2022, 12, 31, 14, 30, "festa");
    ASSERT_EQ(TodoList.getTodosNumber(), 1);
    TodoList.completeTodo("festa");
    ASSERT_EQ(TodoList.getCompleted(), 1);
    TodoList.completeTodo("festa");
    ASSERT_EQ(TodoList.getCompleted(), 0);
    ASSERT_EQ(TodoList.getTodosNumber(), 1);
    ASSERT_THROW(TodoList.completeTodo("dentista"), std::invalid_argument);
}

TEST_F(TodoListTest, TestDeleteTodo) {
    TodoList.addTodo(2022, 12, 31, 14, 30, "festa");
    ASSERT_EQ(TodoList.getTodosNumber(), 1);
    TodoList.deleteTodo("festa");
    ASSERT_EQ(TodoList.getTodosNumber(), 0);
    ASSERT_THROW(TodoList.deleteTodo("dentista"), std::invalid_argument);
}

TEST_F(TodoListTest, TestClearList) {
    TodoList.addTodo(2022, 12, 31, 14, 30, "festa");
    ASSERT_EQ(TodoList.getTodosNumber(), 1);
    TodoList.clearList();
    ASSERT_EQ(TodoList.getTodosNumber(), 0);
}

TEST_F(TodoListTest, ReadWrite) {
    TodoList.addTodo(2022, 12, 31, 14, 30, "festa");
    ASSERT_EQ(TodoList.getTodosNumber(), 1);
    TodoList.writeFile();
    TodoList.clearList();
    ASSERT_EQ(TodoList.getTodosNumber(), 0);
    TodoList.setList(TodoList::readFile());
    ASSERT_EQ(TodoList.getTodosNumber(), 1);
    ASSERT_EQ(TodoList.getTodoItems().front().getDueDate(), "2022/12/31/14:30");
}

TEST_F(TodoListTest, SearchTodo) {
    TodoList.addTodo(2022, 12, 31, 14, 30, "festa");
    ASSERT_EQ(TodoList.getTodosNumber(), 1);
    ASSERT_THROW(TodoList.searchTodo("dentista"), std::invalid_argument);
}