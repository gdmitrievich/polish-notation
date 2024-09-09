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
    using id_t = Token::Id;
    return id == id_t::plus || id == id_t::minus || id == id_t::mult ||
           id == id_t::div;
}

Token::Priority Token::getBinaryOperatorPriority() const {
    using id_t = Token::Id;
    Priority pr;

    switch (id) {
        case id_t::plus:
            pr = Priority::plus;
            break;
        case id_t::minus:
            pr = Priority::minus;
            break;
        case id_t::mult:
            pr = Priority::mult;
            break;
        case id_t::div:
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