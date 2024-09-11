#include "polish_calculation.h"

namespace polish_notation::polish_calculation {
void replaceAllXWithNumInTokenQueue(Queue<Token>& q, double num) {
    size_t qSize = q.size();
    Token t;

    for (size_t i {}; i < qSize; ++i) {
        t = q.dequeue();
        if (t.id == t_id::x)
            q.enqueue(Token(num));
        else
            q.enqueue(t);
    }
}

::std::pair<bool, double> tryCalculatePostfixTokenQueue(Queue<Token> qPostfix) {
    Stack<Token> s;
    bool isOk = true;
    ::std::pair<bool, double> result(true, 0);

    while (!qPostfix.isEmpty() && isOk)
        isOk = tryCalculateRetrievedToken(qPostfix.dequeue(), s);

    if (isOk && s.size() == 1)
        result.second = s.pop().data.num;
    else
        result.first = false;

    return result;
}

bool tryCalculateRetrievedToken(const Token& t, Stack<Token>& s) {
    bool status = true;
    if (t.id == t_id::num) {
        s.push(t);
    } else if (t.isFunction()) {
        if (s.size() >= 1)
            s.push(calculateFunction(t.id, s.pop()));
        else
            status = false;
    } else if (t.isBinaryOperator()) {
        if (s.size() >= 2) {
            double first = s.pop().data.num;
            double second = s.pop().data.num;
            s.push(calculateBinaryOperator(t.id, first, second));
        } else {
            status = false;
        }
    }
    return status;
}
} // namespace polish_notation::polish_calculation