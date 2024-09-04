#include "polish_notation/tests/data_structures/queue_tests/queue_tests.h"

#include <gtest/gtest.h>

using polish_notation::tests::data_structures::queue_tests::QueueTests;

TEST(EnqueueTests, EnqueueOneItem) {
    QueueTests<int> q;

    q.enqueue(1);

    EXPECT_EQ(q.peek(), 1);
    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(q.isEmpty(), false);

    EXPECT_EQ(q.frontPtr()->next, nullptr);
    EXPECT_EQ(q.frontPtr(), q.backPtr());
}

TEST(EnqueueTests, EnqueueThreeItems) {
    QueueTests<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    EXPECT_EQ(q.peek(), 1);
    EXPECT_EQ(q.size(), 3);
    EXPECT_EQ(q.isEmpty(), false);

    EXPECT_EQ(q.backPtr()->data, 1);
    EXPECT_EQ(q.frontPtr()->data, 3);
    EXPECT_EQ(q.backPtr()->next->next, q.frontPtr());
    EXPECT_NE(q.frontPtr(), q.backPtr());
}

TEST(DequeueTests, DequeueOneItem) {
    QueueTests<int> q;
    q.enqueue(1);

    int dequeuedValue = q.dequeue();

    EXPECT_EQ(q.size(), 0);
    EXPECT_EQ(q.isEmpty(), true);

    EXPECT_EQ(q.frontPtr(), q.backPtr());
    EXPECT_EQ(q.frontPtr(), nullptr);

    EXPECT_EQ(dequeuedValue, 1);
}

TEST(DequeueTests, DequeueTwoItems) {
    QueueTests<int> q;
    q.enqueue(1);
    q.enqueue(2);

    int dequeuedValue = q.dequeue();

    EXPECT_EQ(q.frontPtr(), q.backPtr());
    EXPECT_NE(q.frontPtr(), nullptr);

    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(dequeuedValue, 1);

    dequeuedValue = q.dequeue();
    EXPECT_EQ(q.frontPtr(), q.backPtr());
    EXPECT_EQ(q.frontPtr(), nullptr);

    EXPECT_EQ(q.size(), 0);
    EXPECT_EQ(dequeuedValue, 2);
}