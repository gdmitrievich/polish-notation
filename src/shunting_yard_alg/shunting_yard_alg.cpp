#include "polish_notation/shunting_yard_alg/shunting_yard_alg.h"

namespace polish_notation::shunting_yard_alg {
::std::pair<bool, Queue<Token>> tryConvertInfixTokenQueueToPostfix(
    Queue<Token>& qInfix) {
    Queue<Token> qPostfix;
    Stack<Token> sOperators;
    bool isOk = true;

    while (!qInfix.isEmpty() && isOk)
        isOk = tryMakeOperationWithDequeuedToken(qInfix.dequeue(), qPostfix,
                                                 sOperators);
    if (isOk)
        isOk = tryPlaceStackItemsToQueue(sOperators, qPostfix);
    if (!isOk)
        qPostfix.destroy();

    return ::std::pair(isOk, qPostfix);
}

bool tryMakeOperationWithDequeuedToken(const Token& t, Queue<Token>& qPostfix,
                                       Stack<Token>& sOperators) {
    bool status = true;

    if (t.isNumOrX()) {
        qPostfix.enqueue(t);
    } else if (t.isBinaryOperator()) {
        moveGreaterOrEqualBinaryOperatorFromStackTopToQueueIfExists(
            t, sOperators, qPostfix);
        sOperators.push(t);
    } else if (t.isFunction() || t.id == t_id::lBrace) {
        sOperators.push(t);
    } else if (t.id == t_id::rBrace) {
        status = tryRetrieveStackItemsUntilLBrace(sOperators, qPostfix);
        if (status)
            setFunctionFromStackTopToQueueIfExists(sOperators, qPostfix);
    }

    return status;
}

void moveGreaterOrEqualBinaryOperatorFromStackTopToQueueIfExists(
    const Token& t, Stack<Token>& sOperators, Queue<Token>& qPostfix) {
    if (!sOperators.isEmpty() && sOperators.top().isBinaryOperator() &&
        t.data.priority <= sOperators.top().data.priority)
        qPostfix.enqueue(sOperators.pop());
}

bool tryRetrieveStackItemsUntilLBrace(Stack<Token>& sOperators,
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

    return !(sOperators.isEmpty() && !isFound);
}

void setFunctionFromStackTopToQueueIfExists(Stack<Token>& sOperators,
                                            Queue<Token>& qPostfix) {
    if (!sOperators.isEmpty() && sOperators.top().isFunction())
        qPostfix.enqueue(sOperators.pop());
}

bool tryPlaceStackItemsToQueue(Stack<Token>& sOperators,
                               Queue<Token>& qPostfix) {
    Token t;
    bool lBraceFound = false;

    while (!sOperators.isEmpty() && !lBraceFound) {
        t = sOperators.pop();
        if (t.id != t_id::lBrace)
            qPostfix.enqueue(t);
        else
            lBraceFound = true;
    }

    return lBraceFound == false;
}
} // namespace polish_notation::shunting_yard_alg