#include "../../src/shunting_yard_alg/shunting_yard_alg.h"

#include <gtest/gtest.h>

#include <string>
#include <utility>

#include "../../tests/token/token_test/token_test.h"

using namespace polish_notation::shunting_yard_alg;

using polish_notation::data_structures::queue::Queue;
using polish_notation::tests::token_test::TokenTest;
using polish_notation::token::t_id;
using polish_notation::token::Token;

TEST(TryConvertInfixTokenQueueToPostfixTest, SequenceOfFunctions) {
    Queue<Token> src;
    src.enqueue(Token(t_id::sin));
    src.enqueue(Token(t_id::cos));
    src.enqueue(Token(t_id::ln));
    src.enqueue(Token(t_id::lBrace));
    src.enqueue(Token(t_id::x));
    src.enqueue(Token(t_id::plus));
    src.enqueue(Token(t_id::ln));
    src.enqueue(Token(t_id::x));
    src.enqueue(Token(t_id::rBrace));

    Queue<Token> expected;
    expected.enqueue(Token(t_id::x));
    expected.enqueue(Token(t_id::x));
    expected.enqueue(Token(t_id::ln));
    expected.enqueue(Token(t_id::plus));
    expected.enqueue(Token(t_id::ln));
    expected.enqueue(Token(t_id::cos));
    expected.enqueue(Token(t_id::sin));

    std::pair<bool, Queue<Token>> resultPair =
        tryConvertInfixTokenQueueToPostfix(src);

    Queue<Token> result = std::get<1>(resultPair);
    ASSERT_TRUE(std::get<0>(resultPair));
    ASSERT_EQ(result.size(), expected.size());
    while (!result.isEmpty())
        EXPECT_EQ((TokenTest) result.dequeue(), (TokenTest) expected.dequeue());
}

TEST(TryConvertInfixTokenQueueToPostfixTest, RandomCorrectCase) {
    Queue<Token> src;
    src.enqueue(Token(t_id::lBrace));
    src.enqueue(Token(55));
    src.enqueue(Token(t_id::plus));
    src.enqueue(Token(33));
    src.enqueue(Token(t_id::rBrace));
    src.enqueue(Token(t_id::mult));
    src.enqueue(Token(t_id::lBrace));
    src.enqueue(Token(3));
    src.enqueue(Token(t_id::plus));
    src.enqueue(Token(t_id::x));
    src.enqueue(Token(t_id::mult));
    src.enqueue(Token(t_id::sin));
    src.enqueue(Token(t_id::x));
    src.enqueue(Token(t_id::rBrace));

    Queue<Token> expected;
    expected.enqueue(Token(55));
    expected.enqueue(Token(33));
    expected.enqueue(Token(t_id::plus));
    expected.enqueue(Token(3));
    expected.enqueue(Token(t_id::x));
    expected.enqueue(Token(t_id::sin));
    expected.enqueue(Token(t_id::x));
    expected.enqueue(Token(t_id::mult));
    expected.enqueue(Token(t_id::plus));
    expected.enqueue(Token(t_id::mult));

    std::pair<bool, Queue<Token>> resultPair =
        tryConvertInfixTokenQueueToPostfix(src);

    Queue<Token> result = std::get<1>(resultPair);
    ASSERT_TRUE(std::get<0>(resultPair));
    ASSERT_EQ(result.size(), expected.size());
    while (!result.isEmpty())
        EXPECT_EQ((TokenTest) result.dequeue(), (TokenTest) expected.dequeue());
}
