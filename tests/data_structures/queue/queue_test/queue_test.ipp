#include "queue_test.h"

namespace polish_notation::tests::data_structures::queue_test {
template <typename T>
inline const Node<T>* QueueTest<T>::frontPtr() const {
    return Queue<T>::frontPtr();
}

template <typename T>
inline const Node<T>* QueueTest<T>::backPtr() const {
    return Queue<T>::backPtr();
}

template <typename T>
QueueTest<T>::QueueTest() : Queue<T>() {}

template <typename T>
QueueTest<T>::QueueTest(const ::std::initializer_list<T>& list) {
    const T* begin = list.begin();
    while (begin != list.end()) {
        Queue<T>::enqueue(*begin++);
    }
}
} // namespace polish_notation::tests::data_structures::queue_test