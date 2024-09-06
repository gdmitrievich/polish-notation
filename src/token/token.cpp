#include "polish_notation/token/token.h"

namespace polish_notation::token {
Token::Token() : id(Token::Id::x), data() {}
Token::Token(Token::Id i) : id(i), data() {}
Token::Token(double num) : id(Token::Id::num), data(num) {}
Token::Token(Token::Id binary, Token::Priority p) : id(binary), data(p) {}
} // namespace polish_notation::token