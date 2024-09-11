#ifndef POLISH_CALCULATION_H
#define POLISH_CALCULATION_H

#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/token/token.h"

namespace polish_notation::polish_calculation {
namespace pn = polish_notation;
using pn::data_structures::queue::Queue;
using pn::data_structures::queue::size_t;
using pn::token::t_id;
using pn::token::Token;

void replaceAllXWithNumInTokenQueue(Queue<Token>& q, double num);
} // namespace polish_notation::polish_calculation

#endif // POLISH_CALCULATION_H