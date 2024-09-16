#include <stdexcept>

#include "polish_notation/data_structures/node/node.h"
#include "polish_notation/utility/utility.h"
#include "stack.h"

namespace polish_notation::data_structures::stack {
using ::polish_notation::data_structures::node::Node;

template <typename T>
Stack<T>::Stack() noexcept : size_(), topPtr_() {}

template <typename T>
Stack<T>::~Stack() noexcept {
    destroy();
}

template <typename T>
void Stack<T>::push(const T& item) {
    if (isEmpty()) {
        topPtr_ = new Node<T>(item);
    } else {
        Node<T>* tmp = new Node<T>(item);
        tmp->next = topPtr_;
        topPtr_ = tmp;
    }

    ++size_;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty())
        throw ::std::runtime_error(
            pn_u::debugTrace("runtime_error: Popping from an empty stack."));

    T tmpData = topPtr_->data;

    Node<T>* tmp = topPtr_;
    topPtr_ = topPtr_->next;
    delete tmp;

    --size_;
    return tmpData;
}

template <typename T>
inline T Stack<T>::top() const {
    if (isEmpty())
        throw ::std::runtime_error(
            pn_u::debugTrace("runtime_error: Extraction from an empty stack."));

    return topPtr_->data;
}

template <typename T>
void Stack<T>::destroy() noexcept {
    while (!isEmpty()) {
        Node<T>* tmp = topPtr_;
        topPtr_ = topPtr_->next;
        delete tmp;
    }

    size_ = 0;
}

template <typename T>
inline bool Stack<T>::isEmpty() const noexcept {
    return topPtr_ == nullptr;
}

template <typename T>
inline ::polish_notation::utility::size_t Stack<T>::size() const noexcept {
    return size_;
}
} // namespace polish_notation::data_structures::stack