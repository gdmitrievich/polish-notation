#ifndef STACK_H
#define STACK_H

#include "polish_notation/data_structures/node/node.h"

namespace polish_notation::data_structures::stack {
using ::polish_notation::data_structures::node::Node;
using size_t = decltype(sizeof(1));

template <typename T>
struct Node;

template <typename T>
class Stack {
   private:
    size_t size_;
    Node<T>* topPtr_;

   public:
    Stack();
    ~Stack();

    void push(const T& item);
    T pop();
    T top() const;
    void destroy();

    bool isEmpty() const;
    size_t size() const;
};
} // namespace polish_notation::data_structures::stack

#include "stack.ipp"

#endif // STACK_H