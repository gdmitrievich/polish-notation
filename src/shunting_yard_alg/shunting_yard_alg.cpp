#include "polish_notation/shunting_yard_alg/shunting_yard_alg.h"

#include "polish_notation/exceptions/invalid_function/invalid_function.h"

namespace polish_notation::shunting_yard_alg {
using ::polish_notation::data_structures::queue::Queue;
using ::polish_notation::data_structures::stack::Stack;
using ::polish_notation::token::t_id;
using ::polish_notation::token::Token;

Queue<Token> convertInfixTokenQueueToPostfix(Queue<Token>& qInfix) {
    Queue<Token> qPostfix;
    Stack<Token> sOperators;

    while (!qInfix.isEmpty())
        operateNextTokenFromInfixQueue(qInfix, qPostfix, sOperators);
    placeStackItemsToQueue(sOperators, qPostfix);

    return qPostfix;
}

void operateNextTokenFromInfixQueue(Queue<Token>& qInfix,
                                    Queue<Token>& qPostfix,
                                    Stack<Token>& sOperators) {
    Token t = qInfix.dequeue();
    if (t.isNumOrX()) {
        qPostfix.enqueue(t);
    } else if (t.isBinaryOperator()) {
        moveGreaterOrEqualBinaryOperatorFromStackTopToQueueIfExists(
            t, sOperators, qPostfix);
        sOperators.push(t);
    } else if (t.isFunction()) {
        if (!hasFunctionArg(qInfix))
            throw ::pn_e::InvalidFunction(
                ::pn_e::InvalidFunction::ErrType::FunctionWithoutArg,
                "invalid_function: Function without argument error.");

        sOperators.push(t);
    } else if (t.id == t_id::lBrace) {
        sOperators.push(t);
    } else if (t.id == t_id::rBrace) {
        retrieveStackItemsUntilLBrace(sOperators, qPostfix);
        setFunctionFromStackTopToQueueIfExists(sOperators, qPostfix);
    }
}

void moveGreaterOrEqualBinaryOperatorFromStackTopToQueueIfExists(
    const Token& t, Stack<Token>& sOperators, Queue<Token>& qPostfix) {
    if (!sOperators.isEmpty() && sOperators.top().isBinaryOperator() &&
        t.data.priority <= sOperators.top().data.priority)
        qPostfix.enqueue(sOperators.pop());
}

bool hasFunctionArg(const Queue<Token>& qInfix) {
    if (qInfix.isEmpty())
        return false;

    Token t = qInfix.peek();
    return t.isNumOrX() || t.isFunction() || t.id == t_id::lBrace;
}

void retrieveStackItemsUntilLBrace(Stack<Token>& sOperators,
                                   Queue<Token>& qPostfix) {
    bool isFound = false;
    Token t;

    while (!sOperators.isEmpty() && !isFound) {
        t = sOperators.pop();
        if (t.id != t_id::lBrace)
            qPostfix.enqueue(t);
        else
            isFound = true;
    }

    if (sOperators.isEmpty() && !isFound)
        throw ::pn_e::InvalidFunction(
            ::pn_e::InvalidFunction::ErrType::LBraceNotFound,
            "invalid_function: Left brace not found.");
}

void setFunctionFromStackTopToQueueIfExists(Stack<Token>& sOperators,
                                            Queue<Token>& qPostfix) {
    if (!sOperators.isEmpty() && sOperators.top().isFunction())
        qPostfix.enqueue(sOperators.pop());
}

void placeStackItemsToQueue(Stack<Token>& sOperators, Queue<Token>& qPostfix) {
    Token t;

    while (!sOperators.isEmpty()) {
        t = sOperators.pop();
        if (t.id != t_id::lBrace)
            qPostfix.enqueue(t);
        else
            throw ::pn_e::InvalidFunction(
                ::pn_e::InvalidFunction::ErrType::RBraceNotFound,
                "invalid_function: Right brace not found.");
    }
}
} // namespace polish_notation::shunting_yard_alg