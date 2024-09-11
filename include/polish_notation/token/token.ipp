#include <algorithm>
#include <initializer_list>

#include "token.h"

namespace polish_notation::token {
inline bool Token::isBinaryOperator() const {
    return isEqualToOneOfTheIdList(
        {t_id::plus, t_id::minus, t_id::mult, t_id::div});
}

inline bool Token::isFunction() const {
    return isEqualToOneOfTheIdList(
        {t_id::sin, t_id::cos, t_id::tan, t_id::ctg, t_id::sqrt, t_id::ln});
}

inline bool Token::isNumOrX() const {
    return isEqualToOneOfTheIdList({t_id::num, t_id::x});
}

inline bool Token::isEqualToOneOfTheIdList(
    const ::std::initializer_list<Token::Id>& idList) const {
    return ::std::any_of(idList.begin(), idList.end(), [this](Token::Id tId) {
        return id == tId;
    });
}
} // namespace polish_notation::token