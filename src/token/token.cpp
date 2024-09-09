#include "polish_notation/token/token.h"

#include <algorithm>
#include <initializer_list>

namespace polish_notation::token {
Token::Token() : id(Token::Id::x), data() {}
Token::Token(Token::Id i) : id(i) {
    if (isBinaryOperator())
        data.priority = getBinaryOperatorPriority();
}
Token::Token(double num) : id(Token::Id::num), data(num) {}

bool Token::isBinaryOperator() const {
    return isEqualToOneOfTheIdList(
        {t_id::plus, t_id::minus, t_id::mult, t_id::div});
}

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

inline bool Token::isEqualToOneOfTheIdList(
    const ::std::initializer_list<Token::Id>& idList) const {
    return ::std::any_of(idList.begin(), idList.end(), [this](Token::Id tId) {
        return id == tId;
    });
}
} // namespace polish_notation::token