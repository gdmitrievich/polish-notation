#include "node.h"

namespace polish_notation::data_structures::node {
template <typename T>
Node<T>::Node() : data(), next() {}

template <typename T>
Node<T>::Node(T data, Node<T>* next) {
    this->data = data;
    if (next) {
        this->next = new Node<T>();
        this->next->data = next->data;
        this->next->next = next->next;
    } else {
        this->next = nullptr;
    }
}
} // namespace polish_notation::data_structures::node