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
} // namespace polish_notation::polish_calculation