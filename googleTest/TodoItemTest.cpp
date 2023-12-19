//
// Created by nick on 10/17/23.
//

#include "gtest/gtest.h"
#include "../TodoItem.h"

class TodoItemTest : public ::testing::Test {
protected:
    TodoItem TodoItem;
};
TEST_F(TodoItemTest, TestConstructor) {
    ASSERT_EQ(TodoItem.getDescription(), "");
    ASSERT_EQ(TodoItem.isCompleted(), false);
}

TEST_F(TodoItemTest, TestSetCompleted) {
    TodoItem.setCompleted(true);
    ASSERT_EQ(TodoItem.isCompleted(), true);
}

TEST_F(TodoItemTest, EditDate) {
    TodoItem.editDate(3, 11);
    ASSERT_EQ(TodoItem.getDueDate(), "2020/12/11/12:12");
}