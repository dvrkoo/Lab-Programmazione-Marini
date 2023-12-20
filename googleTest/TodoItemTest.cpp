//
// Created by nick on 10/17/23.
//

#include "gtest/gtest.h"
#include "../TodoItem.h"
#include "../Date.h"

class TodoItemTest : public ::testing::Test {

protected:
    TodoItem todoItem;
};

TEST_F(TodoItemTest, TestConstructor) {
    ASSERT_EQ(todoItem.getDescription(), "");
    ASSERT_EQ(todoItem.isCompleted(), false);
}

TEST_F(TodoItemTest, TestSetCompleted) {
    todoItem.setCompleted();
    ASSERT_EQ(todoItem.isCompleted(), true);
    todoItem.setCompleted();
    ASSERT_EQ(todoItem.isCompleted(), false);
}

TEST_F(TodoItemTest, EditDate) {
    todoItem = TodoItem(false, Date(2022, 12, 31, 14, 30), "festa");
    todoItem.editDate(3, 11);
    ASSERT_EQ(todoItem.getDueDate(), "2022/12/11/14:30");
    ASSERT_THROW(todoItem.editDate(0, 11), std::invalid_argument);
    ASSERT_THROW(todoItem.editDate(2, 14), std::invalid_argument);
    todoItem.editDate(2, 2);
    ASSERT_THROW(todoItem.editDate(3, 29), std::invalid_argument);
    ASSERT_THROW(todoItem.editDate(4, 28), std::invalid_argument);
    ASSERT_THROW(todoItem.editDate(5, 61), std::invalid_argument);
}