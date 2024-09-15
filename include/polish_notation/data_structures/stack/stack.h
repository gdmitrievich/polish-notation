#ifndef STACK_H
#define STACK_H

#include "polish_notation/data_structures/node/node.h"
#include "polish_notation/utility.h"

namespace polish_notation::data_structures::stack {
using ::polish_notation::data_structures::node::Node;

template <typename T>
class Stack {
   private:
    ::polish_notation::utility::size_t size_;
    Node<T>* topPtr_;

   public:
    Stack();
    ~Stack();

    void push(const T& item);
    T pop();
    T top() const;
    void destroy();

    bool isEmpty() const;
    ::polish_notation::utility::size_t size() const;
};
} // namespace polish_notation::data_structures::stack

#include "stack.ipp"

#endif // STACK_H