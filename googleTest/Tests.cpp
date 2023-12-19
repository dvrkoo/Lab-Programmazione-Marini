#include "gtest/gtest.h"
#include "../Date.h"
#include "../TodoItem.h"
#include "../TodoList.h"

TEST(Date, setDate) {

    Date d(2022, 12, 31, 14, 30);
    ASSERT_EQ(d.getDay(), 31);
    ASSERT_EQ(d.getMonth(), 12);
    ASSERT_EQ(d.getYear(), 2022);

    ASSERT_THROW(d.setMonth(9, true), std::invalid_argument);
    ASSERT_EQ(d.getMonth(), 12); //test passato perche rimane a marzo

    d.setDay(25);
    ASSERT_EQ(d.getDay(), 25);
    d.setYear(1900, true);
    ASSERT_EQ(d.getYear(), 1900);

}

TEST(TodoItem, Checktodo) {
    Date d(2022, 12, 31, 14, 30);
    TodoItem t(false, d, "festa");

    ASSERT_EQ(t.isCompleted(), false);
    t.setCompleted(true);
    ASSERT_EQ(t.isCompleted(), true);
    ASSERT_EQ(t.getDescription(), "festa");
    ASSERT_EQ(t.getDueDate(), "2022/12/31/14:30");
    ASSERT_EQ(t.getDescription(), "festa");
}

TEST(TodoList, howmanytodo) {
    TodoList a;
    ASSERT_EQ(a.getTodosNumber(), 0);
    a.addTodo(2022, 12, 31, 14, 30, "festa");
    ASSERT_EQ(a.getTodosNumber(), 1);
    a.editTodo("festa", 3, 12);
    ASSERT_EQ(a.getTodo("festa").getDueDate(), "2022/12/12/14:30");
}

TEST(HelperFunctions, Readandwrite) {
    TodoList a;
    ASSERT_EQ(a.getTodosNumber(), 0);
    a.addTodo(2022, 12, 31, 14, 30, "festa");
    ASSERT_EQ(a.getTodosNumber(), 1);
    TodoList::writeFile(a.getTodoItems());

    a.clearList();
    ASSERT_EQ(a.getTodosNumber(), 0);
    a.setList(TodoList::readFile());
    ASSERT_EQ(a.getTodosNumber(), 1);
    ASSERT_EQ(a.getTodo("festa").getDueDate(), "2022/12/31/14:30");
}
