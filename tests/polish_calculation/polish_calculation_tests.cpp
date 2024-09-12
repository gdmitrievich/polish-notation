#include "../../src/polish_calculation/polish_calculation.h"

#include <gtest/gtest.h>

using namespace polish_notation::polish_calculation;

TEST(TryCalculatePostfixTokenQueueTest, SequenceOfFunctions) {
    Queue<Token> src;
    src.enqueue(Token(M_PI / 6));
    src.enqueue(Token(t_id::sqrt));
    src.enqueue(Token(t_id::cos));
    src.enqueue(Token(t_id::sin));

    ::std::pair<bool, double> resultPair = tryCalculatePostfixTokenQueue(src);

    ASSERT_TRUE(resultPair.first);
    EXPECT_NEAR(resultPair.second, 0.6812, 0.0001);
}

TEST(TryCalculatePostfixTokenQueueTest, SqrtOfThe25) {
    Queue<Token> src;
    src.enqueue(Token(1));
    src.enqueue(Token(3));
    src.enqueue(Token(8));
    src.enqueue(Token(t_id::mult));
    src.enqueue(Token(t_id::plus));
    src.enqueue(Token(t_id::sqrt));

    ::std::pair<bool, double> resultPair = tryCalculatePostfixTokenQueue(src);

    ASSERT_TRUE(resultPair.first);
    EXPECT_DOUBLE_EQ(resultPair.second, 5);
}

TEST(TryCalculatePostfixTokenQueueTest, FuncWithoutArgError) {
    Queue<Token> src;
    src.enqueue(Token(t_id::sin));
    src.enqueue(Token(t_id::cos));

    ::std::pair<bool, double> resultPair = tryCalculatePostfixTokenQueue(src);

    ASSERT_FALSE(resultPair.first);
}