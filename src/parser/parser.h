#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/token/token.h"

namespace polish_notation::parser {
::std::string getLineWithoutSpaces(const ::std::string& line);

bool trySetTokenQueueFromStr(::polish_notation::data_structures::queue::Queue<
                                 ::polish_notation::token::Token>& tokenQueue,
                             const ::std::string& str);

int trySetTokenFromStr(::polish_notation::token::Token& token, const char* str);
} // namespace polish_notation::parser

#endif // PARSER_H