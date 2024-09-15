#ifndef POLISH_CALCULATION_H
#define POLISH_CALCULATION_H

#include <cmath>
#include <utility>

#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/data_structures/stack/stack.h"
#include "polish_notation/token/token.h"

namespace polish_notation::polish_calculation {
namespace pn = polish_notation;
using pn::data_structures::queue::Queue;
using pn::data_structures::stack::Stack;
using pn::token::t_id;
using pn::token::Token;

void replaceAllXWithNumInTokenQueue(Queue<Token>& q, double num);

::std::pair<bool, double> tryCalculatePostfixTokenQueue(Queue<Token> qPostfix);

bool tryCalculateRetrievedToken(const Token& t, Stack<Token>& s);

double calculateFunction(Token::Id funcId, double v);

double calculateBinaryOperator(Token::Id binId, double first, double second);
} // namespace polish_notation::polish_calculation

#endif // POLISH_CALCULATION_H