#include "../include/ClassStack.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(StackTests, DefaultConstructor)
{
    Stack stack;

    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(stack.getSize(), 0);
}

TEST(StackTests, InitializerListConstructor)
{
    Stack stack{1, 2, 3};

    EXPECT_EQ(stack.getSize(), 3);

    EXPECT_EQ(stack[0], 1);
    EXPECT_EQ(stack[1], 2);
    EXPECT_EQ(stack[2], 3);
}

TEST(StackTests, PushTest)
{
    Stack stack;

    stack.push(10);
    stack.push(20);

    EXPECT_EQ(stack.getSize(), 2);
    EXPECT_EQ(stack.peek(), 20);
}

TEST(StackTests, PopTest)
{
    Stack stack{1, 2, 3};

    stack.pop();

    EXPECT_EQ(stack.getSize(), 2);
    EXPECT_EQ(stack.peek(), 2);
}

TEST(StackTests, PeekTest)
{
    Stack stack{5, 10, 15};

    EXPECT_EQ(stack.peek(), 15);
}

TEST(StackTests, CopyConstructor)
{
    Stack first{1, 2, 3};

    Stack second(first);

    EXPECT_EQ(first, second);
}

TEST(StackTests, AssignmentOperator)
{
    Stack first{4, 5, 6};

    Stack second;

    second = first;

    EXPECT_EQ(first, second);
}

TEST(StackTests, OutputOperator)
{
    Stack stack{1, 2, 3};

    stringstream stream;

    stream << stack;

    EXPECT_EQ(stream.str(), "{1, 2, 3}");
}

TEST(StackTests, InputOperator)
{
    Stack stack;

    stringstream stream("3 7 8 9");

    stream >> stack;

    EXPECT_EQ(stack.getSize(), 3);

    EXPECT_EQ(stack[0], 7);
    EXPECT_EQ(stack[1], 8);
    EXPECT_EQ(stack[2], 9);
}
