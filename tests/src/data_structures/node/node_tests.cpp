#include "polish_notation/data_structures/node/node.h"

#include <gtest/gtest.h>

using polish_notation::data_structures::node::Node;

TEST(TwoParamsCtorTests, CopyEmptyObj) {
    Node<int> empty;

    Node<int> nonEmpty(empty.data, empty.next);

    EXPECT_EQ(nonEmpty.data, 0);
    EXPECT_EQ(nonEmpty.next, nullptr);
}

TEST(TwoParamsCtorTests, CopyNonEmptyObj) {
    Node<int> tmp(5, new Node<int>(4));

    Node<int> nonEmpty(tmp.data, tmp.next);

    EXPECT_EQ(nonEmpty.data, 5);
    EXPECT_NE(tmp.next, nonEmpty.next);
    EXPECT_EQ(tmp.data, nonEmpty.data);
    EXPECT_EQ(tmp.next->data, nonEmpty.next->data);
    EXPECT_EQ(tmp.next->next, nonEmpty.next->next);
    EXPECT_EQ(tmp.next->next, nullptr);
}

TEST(CopyCtorTests, CopyNonEmptyObj) {
    Node<int> tmp(5, new Node<int>(4));

    Node<int> nonEmpty(tmp);

    EXPECT_EQ(nonEmpty.data, 5);
    EXPECT_NE(tmp.next, nonEmpty.next);
    EXPECT_EQ(tmp.data, nonEmpty.data);
    EXPECT_EQ(tmp.next->data, nonEmpty.next->data);
    EXPECT_EQ(tmp.next->next, nonEmpty.next->next);
    EXPECT_EQ(tmp.next->next, nullptr);
}
