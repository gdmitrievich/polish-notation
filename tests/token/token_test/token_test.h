#ifndef TOKEN_TEST_H
#define TOKEN_TEST_H

#include "polish_notation/token/token.h"

namespace polish_notation::tests::token_test {
using ::polish_notation::token::Token;

struct TokenTest : public Token {
    bool operator==(const TokenTest& t) const;
    bool operator!=(const TokenTest& t) const;
};
}

#endif // TOKEN_TEST_H