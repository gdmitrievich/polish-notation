#include "shunting_yard_alg.h"

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
            getFunctionFromStackTopIfExists();
    }

    return status;
}
} // namespace polish_notation::shunting_yard_alg