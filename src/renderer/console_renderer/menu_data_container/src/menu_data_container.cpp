#include "menu_data_container.h"

#include <iostream>

#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/parser/parser.h"
#include "polish_notation/renderer/console_renderer/console_renderer.h"
#include "polish_notation/renderer/field_generator.h"
#include "polish_notation/shunting_yard_alg/shunting_yard_alg.h"
#include "polish_notation/token/token.h"
#include "user_err_mess_printer.h"
#include "user_input.h"

namespace polish_notation::renderer::console::menu_data_container {
MenuDataContainer::MenuDataContainer() :
    funcStr_(),
    funcPostfixTokenQueue_(),
    fInfo_(),
    field_(),
    actionType_(ActionType::Select),
    arrowPos_() {
    try {
        pn_ui::setFunctionStr(funcStr_);
        regenerateFunction();

        pn_ui::setFieldInfo(fInfo_);
        field_ = getGeneratedField(funcPostfixTokenQueue_, fInfo_);
    } catch (const ::std::exception& e) {
        pn_uemp::printErrMess(e);
        exit(EXIT_FAILURE);
    }
}

void MenuDataContainer::regenerateFunction() {
    std::string funcLineWithoutSpaces =
        pn::parser::getLineWithoutSpaces(funcStr_);

    try {
        pn_ds::queue::Queue<pn::token::Token> qTokens;
        if (!pn::parser::trySetTokenQueueFromStr(qTokens,
                                                 funcLineWithoutSpaces))
            throw ::pn_e::InvalidFunction(
                ::pn_e::InvalidFunction::ErrType::InvalidToken,
                "invalid_function: Invalid token.");

        funcPostfixTokenQueue_ =
            pn::shunting_yard_alg::convertInfixTokenQueueToPostfix(qTokens);
    } catch (const ::std::exception& e) {
        pn_uemp::printErrMess(e);
        exit(EXIT_FAILURE);
    }
}

void MenuDataContainer::regenerateField() {
    try {
        field_ =
            pn::renderer::getGeneratedField(funcPostfixTokenQueue_, fInfo_);
    } catch (const ::std::exception& e) {
        pn_uemp::printErrMess(e);
        exit(EXIT_FAILURE);
    }
}

void MenuDataContainer::renderField() const {
    pn::renderer::console::renderField(field_);
}
} // namespace polish_notation::renderer::console::menu_data_container