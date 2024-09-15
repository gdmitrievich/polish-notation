#include "polish_notation/data_structures/node/node.h"
#include "stack.h"

namespace polish_notation::data_structures::stack {
using ::polish_notation::data_structures::node::Node;

template <typename T>
Stack<T>::Stack() : size_(), topPtr_() {}

template <typename T>
Stack<T>::~Stack() {
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
    T tmpData = topPtr_->data;

    Node<T>* tmp = topPtr_;
    topPtr_ = topPtr_->next;
    delete tmp;

    --size_;
    return tmpData;
}

template <typename T>
inline T Stack<T>::top() const {
    return topPtr_->data;
}

template <typename T>
void Stack<T>::destroy() {
    while (!isEmpty()) {
        Node<T>* tmp = topPtr_;
        topPtr_ = topPtr_->next;
        delete tmp;
    }

    size_ = 0;
}

template <typename T>
inline bool Stack<T>::isEmpty() const {
    return topPtr_ == nullptr;
}

template <typename T>
inline ::polish_notation::utility::size_t Stack<T>::size() const {
    return size_;
}
} // namespace polish_notation::data_structures::stack