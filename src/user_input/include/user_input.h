#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <iostream>
#include <string>

#include "polish_notation/renderer/field_info.h"

namespace polish_notation::user_input {
void setFunctionStr(::std::string& fStr);

void setFieldInfo(::polish_notation::renderer::FieldInfo& fInfo);

template <typename T>
void printActionAndSetAnswer(const char* action, T& data);
} // namespace polish_notation::user_input

namespace pn_ui = polish_notation::user_input;

#endif // USER_INPUT_H