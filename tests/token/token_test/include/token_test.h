#ifndef TOKEN_TEST_H
#define TOKEN_TEST_H

#include <iostream>
#include <string>

#include "polish_notation/token/token.h"

namespace polish_notation::tests::token_test {
struct TokenTest : public ::polish_notation::token::Token {
    TokenTest();
    explicit TokenTest(Id id);
    explicit TokenTest(double num);
    TokenTest(const ::polish_notation::token::Token& t);

    bool operator==(const TokenTest& t) const;
    bool operator!=(const TokenTest& t) const;

    ::std::string DebugString() const;

    friend ::std::ostream& operator<<(::std::ostream& os, const TokenTest& t);
    friend void printTo(const TokenTest& t, ::std::ostream* os);
};
} // namespace polish_notation::tests::token_test

#endif // TOKEN_TEST_H