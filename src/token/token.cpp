#include "polish_notation/token/token.h"

namespace polish_notation::token {
Token::Token() : id(Token::Id::x), data() {}
Token::Token(Token::Id i) : id(i) {
    if (isBinaryOperator())
        data.priority = getBinaryOperatorPriority();
}
Token::Token(double num) : id(Token::Id::num), data(num) {}

Token::Priority Token::getBinaryOperatorPriority() const {
    Priority pr;

    switch (id) {
        case t_id::plus:
            pr = Priority::plus;
            break;
        case t_id::minus:
            pr = Priority::minus;
            break;
        case t_id::mult:
            pr = Priority::mult;
            break;
        case t_id::div:
            pr = Priority::div;
            break;
    }

    return pr;
}
} // namespace polish_notation::token