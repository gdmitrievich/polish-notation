#ifndef SHUNTING_YARD_ALG_H
#define SHUNTING_YARD_ALG_H

#include <utility>

#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/data_structures/stack/stack.h"
#include "polish_notation/token/token.h"

namespace polish_notation::shunting_yard_alg {
using ::polish_notation::data_structures::queue::Queue;
using ::polish_notation::data_structures::stack::Stack;
using ::polish_notation::token::t_id;
using ::polish_notation::token::Token;

::std::pair<bool, Queue<Token>> tryConvertInfixTokenQueueToPostfix(
    Queue<Token>& qInfix);

bool tryMakeOperationWithDequeuedToken(const Token& t, Queue<Token>& qPostfix,
                                       Stack<Token>& sOperators);
} // namespace polish_notation::shunting_yard_alg

#endif // SHUNTING_YARD_ALG_H