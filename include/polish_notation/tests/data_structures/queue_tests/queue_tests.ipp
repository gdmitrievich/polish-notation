#include "queue_tests.h"

namespace polish_notation::tests::data_structures::queue_tests {
template <typename T>
inline const Node<T>* QueueTests<T>::frontPtr() const {
	return frontPtr_;
}

template <typename T>
inline const Node<T>* QueueTests<T>::backPtr() const {
	return backPtr_;
}
}