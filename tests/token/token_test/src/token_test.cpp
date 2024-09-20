#include "token_test.h"

namespace polish_notation::tests::token_test {
using ::polish_notation::token::Token;

TokenTest::TokenTest() : Token() {}
TokenTest::TokenTest(Id id) : Token(id) {}
TokenTest::TokenTest(double num) : Token(num) {}
TokenTest::TokenTest(const Token& t) : Token() {}

bool TokenTest::operator==(const TokenTest& t) const {
    bool isEqual = true;

    isEqual = this->id == t.id;
    isEqual = isEqual && this->id == Token::Id::num ?
                  this->data.num == t.data.num :
                  isEqual;

    return isEqual;
}

bool TokenTest::operator!=(const TokenTest& t) const {
    return !(*this == t);
}

std::string TokenTest::DebugString() const {
    std::string result;

    result += "id: " + std::to_string(int(id));
    if (id == Token::Id::num)
        result += ", data.num: " + std::to_string(data.num);

    return result;
}

std::ostream& operator<<(std::ostream& os, const TokenTest& t) {
    return os << t.DebugString();
}
} // namespace polish_notation::tests::token_test