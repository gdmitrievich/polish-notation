#ifndef NODE_H
#define NODE_H

namespace polish_notation::data_structures::node {
template <typename T>
struct Node {
	T data;
	Node *next;

	void Node();
	void Node(T data, Node* next = nullptr);
};
} // namespace polish_notation::data_structures::node

#include "node.ipp"

#endif // NODE_H