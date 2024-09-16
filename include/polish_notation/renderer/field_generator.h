#ifndef FIELD_GENERATOR_H
#define FIELD_GENERATOR_H

#include <utility>
#include <vector>

#include "field_info.h"
#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/token/token.h"

namespace polish_notation::renderer {
::std::vector<::std::vector<char>> getGeneratedField(
    const ::polish_notation::data_structures::queue::Queue<
        ::polish_notation::token::Token>& qPostfix,
    FieldInfo fieldInfo);

void checkInputDataAndThrowExceptionIfNeeded(const FieldInfo& f);

void fillFieldByDefault(::std::vector<::std::vector<char>>& f, FieldInfo fInfo);
} // namespace polish_notation::renderer

#endif // FIELD_GENERATOR_H