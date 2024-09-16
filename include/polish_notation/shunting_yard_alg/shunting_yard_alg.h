#ifndef SHUNTING_YARD_ALG_H
#define SHUNTING_YARD_ALG_H

#include <utility>

#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/data_structures/stack/stack.h"
#include "polish_notation/token/token.h"

namespace polish_notation::shunting_yard_alg {
::polish_notation::data_structures::queue::Queue<
    ::polish_notation::token::Token>
convertInfixTokenQueueToPostfix(
    ::polish_notation::data_structures::queue::Queue<
        ::polish_notation::token::Token>& qInfix);

void operateNextTokenFromInfixQueue(
    ::polish_notation::data_structures::queue::Queue<
        ::polish_notation::token::Token>& qInfix,
    ::polish_notation::data_structures::queue::Queue<
        ::polish_notation::token::Token>& qPostfix,
    ::polish_notation::data_structures::stack::Stack<
        ::polish_notation::token::Token>& sOperators);

void moveGreaterOrEqualBinaryOperatorFromStackTopToQueueIfExists(
    const ::polish_notation::token::Token& t,
    ::polish_notation::data_structures::stack::Stack<
        ::polish_notation::token::Token>& sOperators,
    ::polish_notation::data_structures::queue::Queue<
        ::polish_notation::token::Token>& qPostfix);

bool hasFunctionArg(const ::polish_notation::data_structures::queue::Queue<
                    ::polish_notation::token::Token>& qInfix);

void retrieveStackItemsUntilLBrace(
    ::polish_notation::data_structures::stack::Stack<
        ::polish_notation::token::Token>& sOperators,
    ::polish_notation::data_structures::queue::Queue<
        ::polish_notation::token::Token>& qPostfix);

void setFunctionFromStackTopToQueueIfExists(
    ::polish_notation::data_structures::stack::Stack<
        ::polish_notation::token::Token>& sOperators,
    ::polish_notation::data_structures::queue::Queue<
        ::polish_notation::token::Token>& qPostfix);

void placeStackItemsToQueue(::polish_notation::data_structures::stack::Stack<
                                ::polish_notation::token::Token>& sOperators,
                            ::polish_notation::data_structures::queue::Queue<
                                ::polish_notation::token::Token>& qPostfix);
} // namespace polish_notation::shunting_yard_alg

#endif // SHUNTING_YARD_ALG_H