#ifndef STACK_H
#define STACK_H

#include "polish_notation/utility/utility.h"

namespace polish_notation::data_structures::node {
template <typename T>
struct Node;
}

namespace polish_notation::data_structures::stack {
template <typename T>
class Stack {
   private:
    ::polish_notation::utility::size_t size_;
    ::polish_notation::data_structures::node::Node<T>* topPtr_;

   public:
    Stack() noexcept;
    ~Stack() noexcept;

    void push(const T& item);
    T pop();
    T top() const;
    void destroy() noexcept;

    bool isEmpty() const noexcept;
    ::polish_notation::utility::size_t size() const noexcept;
};
} // namespace polish_notation::data_structures::stack

#include "stack.ipp"

#endif // STACK_H