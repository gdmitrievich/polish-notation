#include "queue_tests.h"

namespace polish_notation::tests::data_structures::queue_tests {
template <typename T>
inline const Node<T>* QueueTests<T>::frontPtr() const {
    return Queue<T>::frontPtr();
}

template <typename T>
inline const Node<T>* QueueTests<T>::backPtr() const {
    return Queue<T>::backPtr();
}
} // namespace polish_notation::tests::data_structures::queue_tests