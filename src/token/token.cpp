#include "polish_notation/token/token.h"

namespace polish_notation::token {
Token::Token() : id(Token::Id::x), data() {}
Token::Token(Token::Id i) : id(i), data() {}
Token::Token(double num) : id(Token::Id::num), data(num) {}
Token::Token(Token::Id binary, Token::Priority p) : id(binary), data(p) {}

bool Token::operator==(const Token& t) const {
    bool isEqual = true;

    isEqual = this->id == t.id;
    isEqual = isEqual && this->id == Token::Id::num ?
                  this->data.num == t.data.num :
                  false;

    return isEqual;
}
} // namespace polish_notation::token