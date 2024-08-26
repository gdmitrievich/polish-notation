#include "stack.h"

namespace polish_notation::data_structures::stack {
template <typename T>
Stack<T>::Stack() : size_(), topPtr_();

template <typename T>
Stack<T>::~Stack() {
	destroy();
}
}