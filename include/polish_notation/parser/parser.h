#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/token/token.h"
#include "polish_notation/utility/utility.h"

namespace polish_notation::parser {
::std::string getLineWithoutSpaces(const ::std::string& line);

bool trySetTokenQueueFromStr(::polish_notation::data_structures::queue::Queue<
                                 ::polish_notation::token::Token>& tokenQueue,
                             const ::std::string& str);

int trySetTokenFromStr(::polish_notation::token::Token& token, const char* str);

int setNumberFromStr(double& number, const char* str);

bool hasFractPart(const char* str,
                  ::polish_notation::utility::size_t intPartLen);

::polish_notation::utility::size_t getLenOfNumberStr(const char* str);

double convertStrPartToDouble(const char* str,
                              ::polish_notation::utility::size_t count = -1);

int convertStrPartToInt(const char* str,
                        ::polish_notation::utility::size_t count = -1);
} // namespace polish_notation::parser

#endif // PARSER_H