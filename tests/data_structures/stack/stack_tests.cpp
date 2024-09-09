#include "polish_notation/data_structures/stack/stack.h"

#include <gtest/gtest.h>

namespace polish_notation::data_structures::stack {
TEST(PushTests, PushToEmptyStack) {
    Stack<int> empty;

    empty.push(5);

    EXPECT_EQ(empty.isEmpty(), false);
    EXPECT_EQ(empty.size(), 1);
    EXPECT_EQ(empty.top(), 5);
}

TEST(PushTests, PushToStackWithOneItem) {
    Stack<int> nonEmpty;
    nonEmpty.push(1);

    nonEmpty.push(5);

    EXPECT_EQ(nonEmpty.isEmpty(), false);
    EXPECT_EQ(nonEmpty.size(), 2);
    EXPECT_EQ(nonEmpty.top(), 5);
}

TEST(PopTests, PopStackWithTwoItems) {
    Stack<int> nonEmpty;
    nonEmpty.push(1);
    nonEmpty.push(3);

    int poppedValue = nonEmpty.pop();

    EXPECT_EQ(nonEmpty.isEmpty(), false);
    EXPECT_EQ(nonEmpty.size(), 1);
    EXPECT_EQ(poppedValue, 3);

    poppedValue = nonEmpty.pop();

    EXPECT_EQ(nonEmpty.isEmpty(), true);
    EXPECT_EQ(nonEmpty.size(), 0);
    EXPECT_EQ(poppedValue, 1);
}

TEST(DestroyTests, DestroyStackWithTwoItems) {
    Stack<int> nonEmpty;
    nonEmpty.push(1);
    nonEmpty.push(3);

    nonEmpty.destroy();

    EXPECT_EQ(nonEmpty.isEmpty(), true);
    EXPECT_EQ(nonEmpty.size(), 0);
}

TEST(CommonStackTests, PushAndPopItemsWithoutCompleteRemoval) {
    Stack<int> nonEmpty;
    nonEmpty.push(1);
    nonEmpty.push(2);
    nonEmpty.push(3);

    int poppedValue = nonEmpty.pop();
    EXPECT_EQ(poppedValue, 3);
    EXPECT_EQ(nonEmpty.size(), 2);

    poppedValue = nonEmpty.pop();
    EXPECT_EQ(poppedValue, 2);
    EXPECT_EQ(nonEmpty.size(), 1);
    EXPECT_EQ(nonEmpty.isEmpty(), false);

    nonEmpty.push(4);
    EXPECT_EQ(nonEmpty.top(), 4);
    EXPECT_EQ(nonEmpty.size(), 2);
    nonEmpty.push(5);
    EXPECT_EQ(nonEmpty.top(), 5);
    EXPECT_EQ(nonEmpty.size(), 3);
}

TEST(CommonStackTests, PushAndPopItemsWithCompleteRemoval) {
    Stack<int> nonEmpty;
    nonEmpty.push(1);
    nonEmpty.push(2);
    nonEmpty.push(3);

    int poppedValue = nonEmpty.pop();
    EXPECT_EQ(poppedValue, 3);
    EXPECT_EQ(nonEmpty.size(), 2);

    poppedValue = nonEmpty.pop();
    EXPECT_EQ(poppedValue, 2);
    EXPECT_EQ(nonEmpty.size(), 1);

    poppedValue = nonEmpty.pop();
    EXPECT_EQ(poppedValue, 1);
    EXPECT_EQ(nonEmpty.size(), 0);
    EXPECT_EQ(nonEmpty.isEmpty(), true);

    nonEmpty.push(4);
    EXPECT_EQ(nonEmpty.top(), 4);
    EXPECT_EQ(nonEmpty.size(), 1);
    EXPECT_EQ(nonEmpty.isEmpty(), false);
}
} // namespace polish_notation::data_structures::stack