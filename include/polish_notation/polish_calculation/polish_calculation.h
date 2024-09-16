#ifndef POLISH_CALCULATION_H
#define POLISH_CALCULATION_H

#include <utility>

#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/data_structures/stack/stack.h"
#include "polish_notation/token/token.h"

namespace polish_notation::polish_calculation {
void replaceAllXWithNumInTokenQueue(
    ::polish_notation::data_structures::queue::Queue<
        ::polish_notation::token::Token>& q,
    double num);

::std::pair<bool, double> tryCalculatePostfixTokenQueue(
    ::polish_notation::data_structures::queue::Queue<
        ::polish_notation::token::Token>
        qPostfix);

void calculateRetrievedToken(const ::polish_notation::token::Token& t,
                             ::polish_notation::data_structures::stack::Stack<
                                 ::polish_notation::token::Token>& s);

double calculateFunction(::polish_notation::token::Token::Id funcId, double v);

double calculateBinaryOperator(::polish_notation::token::Token::Id binId,
                               double first, double second);
} // namespace polish_notation::polish_calculation

#endif // POLISH_CALCULATION_H