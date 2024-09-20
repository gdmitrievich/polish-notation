#include "polish_notation/token/token.h"

namespace polish_notation::token {
Token::Data::Data() : num() {}
Token::Data::Data(double n) : num(n) {}
Token::Data::Data(Priority p) : priority(p) {}
} // namespace polish_notation::token