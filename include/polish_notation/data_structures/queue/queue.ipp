#include "polish_notation/data_structures/queue/queue.h"

namespace polish_notation::data_structures::queue {
template <typename T>
inline bool Queue<T>::isEmpty() const {
	return frontPtr_ == nullptr;
}

template <typename T>
inline size_t Queue<T>::size() const {
	return size_;
}
}