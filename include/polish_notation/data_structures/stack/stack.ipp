#include "stack.h"

namespace polish_notation::data_structures::stack {
template <typename T>
Stack<T>::Stack() : size_(), topPtr_();

template <typename T>
Stack<T>::~Stack() {
    destroy();
}

template <typename T>
inline T Stack<T>::top() const {
	return *topPtr_;
}

template <typename T>
inline bool Stack<T>::isEmpty() const {
    return topPtr_ == nullptr;
}

template <typename T>
inline size_t Stack<T>::size() const {
	return size_;
}
} // namespace polish_notation::data_structures::stack