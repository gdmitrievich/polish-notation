#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>

#include "polish_notation/parser/parser.h"
#include "polish_notation/data_structures/queue/queue.h"
#include "polish_notation/token/token.h"
#include "polish_notation/renderer/console_renderer/console_renderer.h"
#include "polish_notation/renderer/field_generator.h"
#include "polish_notation/renderer/field_info.h"
#include "polish_notation/shunting_yard_alg/shunting_yard_alg.h"

namespace pn = polish_notation;
namespace pn_ds = polish_notation::data_structures;

int main(void) {
    std::cout << "Write function: ";
    std::string funcLine;
    getline(std::cin, funcLine);

    std::string funcLineWithoutSpaces =
        pn::parser::getLineWithoutSpaces(funcLine);
    pn_ds::queue::Queue<pn::token::Token> qTokens;
    bool status =
        pn::parser::trySetTokenQueueFromStr(qTokens, funcLineWithoutSpaces);

    std::pair<bool, pn_ds::queue::Queue<pn::token::Token>>
        postfixTokenQueuePair =
            pn::shunting_yard_alg::tryConvertInfixTokenQueueToPostfix(qTokens);
    status = postfixTokenQueuePair.first;
    if (status) {
        pn_ds::queue::Queue<pn::token::Token> postfixTokenQueue(
            postfixTokenQueuePair.second);
        std::pair<bool, std::vector<std::vector<char>>> generatedFieldPair =
            pn::renderer::tryGetGeneratedField(postfixTokenQueue, pn::renderer::FieldInfo({
				150,
				30,
				{-2 * M_PI, 2 * M_PI},
				{-1, 1},
				{74, 15}
			}));
        status = generatedFieldPair.first;
        if (status)
            pn::renderer::console::renderField(generatedFieldPair.second);
    }

    return 0;
}