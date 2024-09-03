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
} // namespace polish_notation::data_structures::stack