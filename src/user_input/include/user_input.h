#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <iostream>
#include <string>

#include "polish_notation/renderer/field_info.h"

namespace polish_notation::user_input {
void setFunctionStr(::std::string& fStr);
} // namespace polish_notation::user_input

namespace pn_ui = polish_notation::user_input;

#endif // USER_INPUT_H