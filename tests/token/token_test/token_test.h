#ifndef TOKEN_TEST_H
#define TOKEN_TEST_H

#include <iostream>
#include <string>

#include "polish_notation/token/token.h"

namespace polish_notation::tests::token_test {
using ::polish_notation::token::Token;

struct TokenTest : public Token {
    bool operator==(const TokenTest& t) const;
    bool operator!=(const TokenTest& t) const;

    std::string DebugString() const;

	friend std::ostream& operator<<(std::ostream& os, const TokenTest& t);
	friend void printTo(const TokenTest& t, std::ostream* os);
};
} // namespace polish_notation::tests::token_test

#endif // TOKEN_TEST_H