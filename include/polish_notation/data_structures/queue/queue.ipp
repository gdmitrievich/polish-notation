#include "polish_notation/data_structures/queue/queue.h"

namespace polish_notation::data_structures::queue {
template <typename T>
inline const Node<T>* Queue<T>::frontPtr() const {
    return frontPtr_;
}

template <typename T>
inline const Node<T>* Queue<T>::backPtr() const {
    return backPtr_;
}

template <typename T>
Queue<T>::Queue() : frontPtr_(), backPtr_(), size_() {}

template <typename T>
void Queue<T>::enqueue(const T& item) {
    Node<T>* tmp = new Node<T>(item);
    if (isEmpty()) {
        backPtr_ = frontPtr_ = tmp;
    } else {
        frontPtr_->next = tmp;
        frontPtr_ = frontPtr_->next;
    }

    ++size_;
}

template <typename T>
inline T Queue<T>::peek() const {
    return backPtr_->data;
}

template <typename T>
inline bool Queue<T>::isEmpty() const {
    return frontPtr_ == nullptr;
}

template <typename T>
inline size_t Queue<T>::size() const {
    return size_;
}
} // namespace polish_notation::data_structures::queue