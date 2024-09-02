#include "node.h"

namespace polish_notation::data_structures::node {
template <typename T>
Node<T>::Node() : data(), next() {}

template <typename T>
Node<T>::Node(const Node<T>& node) {
    this->data = node.data;
    if (node.next) {
        this->next = new Node<T>();
        this->next->data = node.next->data;
        this->next->next = node.next->next;
    } else {
        this->next = nullptr;
    }
}

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

template <typename T>
Node<T>::~Node() {
    delete next;
}
} // namespace polish_notation::data_structures::node