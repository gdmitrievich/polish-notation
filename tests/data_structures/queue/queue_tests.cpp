#include "queue_test/queue_test.h"

#include <gtest/gtest.h>

using polish_notation::tests::data_structures::queue_test::QueueTest;

TEST(EnqueueTests, EnqueueOneItem) {
    QueueTest<int> q;

    q.enqueue(1);

    EXPECT_EQ(q.peek(), 1);
    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(q.isEmpty(), false);

    EXPECT_EQ(q.frontPtr()->next, nullptr);
    EXPECT_EQ(q.frontPtr(), q.backPtr());
}

TEST(EnqueueTests, EnqueueThreeItems) {
    QueueTest<int> q;

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
    QueueTest<int> q;
    q.enqueue(1);

    int dequeuedValue = q.dequeue();

    EXPECT_EQ(q.size(), 0);
    EXPECT_EQ(q.isEmpty(), true);

    EXPECT_EQ(q.frontPtr(), q.backPtr());
    EXPECT_EQ(q.frontPtr(), nullptr);

    EXPECT_EQ(dequeuedValue, 1);
}

TEST(DequeueTests, DequeueTwoItems) {
    QueueTest<int> q;
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

TEST(DestroyTests, DestroyThreeItemsQueue) {
    QueueTest<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.destroy();

    EXPECT_EQ(q.size(), 0);
    EXPECT_EQ(q.isEmpty(), true);

    EXPECT_EQ(q.frontPtr(), q.backPtr());
    EXPECT_EQ(q.frontPtr(), nullptr);
}

TEST(QueueTest, RemoveTwoItemsAndAddTwo) {
    QueueTest<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    int dequeuedValue = q.dequeue();
    EXPECT_EQ(dequeuedValue, 1);
    EXPECT_EQ(q.peek(), 2);
    EXPECT_EQ(q.size(), 2);

    dequeuedValue = q.dequeue();
    EXPECT_EQ(dequeuedValue, 2);
    EXPECT_EQ(q.peek(), 3);
    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(q.frontPtr(), q.backPtr());

    q.enqueue(4);
    EXPECT_EQ(q.peek(), 3);
    EXPECT_EQ(q.size(), 2);
    EXPECT_EQ(q.backPtr()->next, q.frontPtr());

    q.enqueue(5);
    EXPECT_EQ(q.peek(), 3);
    EXPECT_EQ(q.size(), 3);
    EXPECT_EQ(q.backPtr()->next->next, q.frontPtr());
    EXPECT_EQ(q.frontPtr()->data, 5);
}