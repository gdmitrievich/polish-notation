#ifndef NODE_H
#define NODE_H

namespace polish_notation::data_structures::node {
template <typename T>
struct Node {
    T data;
    Node* next;

    Node();
    Node(const Node<T>& node);
    explicit Node(const T& data, Node<T>* next = nullptr);
    Node<T> operator=(const Node<T>& node);
    ~Node();
};
} // namespace polish_notation::data_structures::node

#include "node.ipp"

#endif // NODE_H