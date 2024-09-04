#include "polish_notation/token/token.h"

namespace polish_notation::token {
Token::Token(double num) : id(Token::Id::num), data(num) {}
}