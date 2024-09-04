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