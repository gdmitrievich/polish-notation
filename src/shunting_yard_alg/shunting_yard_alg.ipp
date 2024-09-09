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
} // namespace polish_notation::shunting_yard_alg