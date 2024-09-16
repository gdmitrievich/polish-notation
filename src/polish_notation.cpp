#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/exceptions/invalid_field_info_exception/invalid_field_info_exception.h"
#include "polish_notation/exceptions/invalid_function/invalid_function.h"
#include "polish_notation/parser/parser.h"
#include "polish_notation/renderer/console_renderer/console_renderer.h"
#include "polish_notation/renderer/field_generator.h"
#include "polish_notation/renderer/field_info.h"
#include "polish_notation/shunting_yard_alg/shunting_yard_alg.h"
#include "polish_notation/token/token.h"
#include "user_err_mess_printer.h"
#include "user_input.h"

namespace pn = polish_notation;
namespace pn_ds = polish_notation::data_structures;

int main(void) {
    std::string funcStr;
    pn_ui::setFunctionStr(funcStr);

    std::string funcLineWithoutSpaces =
        pn::parser::getLineWithoutSpaces(funcStr);

    try {
        pn_ds::queue::Queue<pn::token::Token> qTokens;
        if (!pn::parser::trySetTokenQueueFromStr(qTokens,
                                                 funcLineWithoutSpaces))
            throw ::pn_e::InvalidFunction(
                ::pn_e::InvalidFunction::ErrType::InvalidToken,
                "invalid_function: Invalid token.");

        pn_ds::queue::Queue<pn::token::Token> postfixTokenQueue =
            pn::shunting_yard_alg::convertInfixTokenQueueToPostfix(qTokens);

        pn::renderer::FieldInfo fInfo;
        pn_ui::setFieldInfo(fInfo);
        pn::renderer::checkInputDataAndThrowExceptionIfNeeded(fInfo);
        pn::renderer::console::renderField(
            pn::renderer::getGeneratedField(postfixTokenQueue, fInfo));
    } catch (const ::std::exception& e) {
        pn_uemp::printErrMess(e);
        exit(EXIT_FAILURE);
    }

    return 0;
}