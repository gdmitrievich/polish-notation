#include "node.h"

namespace polish_notation::data_structures::node {
template <typename T>
Node<T>::Node() : data(), next() {}

template <typename T>
Node<T>::Node(T data, Node* next) {
    this->data = data;
    this->next = next;
}
} // namespace polish_notation::data_structures::node