#include "stack.h"

namespace polish_notation::data_structures::stack {
template <typename T>
Stack<T>::Stack() : size_(), topPtr_();

template <typename T>
Stack<T>::~Stack() {
    destroy();
}

template <typename T>
inline bool Stack<T>::isEmpty() const {
    return topPtr_ == nullptr;
}
} // namespace polish_notation::data_structures::stack