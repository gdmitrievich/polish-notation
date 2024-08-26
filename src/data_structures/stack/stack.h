#ifndef STACK_H
#define STACK_H

namespace polish_notation::data_structures::stack {
using size_t = decltype(sizeof(1));

template <typename T>
struct Node;

template <typename T>
class Stack {
   private:
    size_t size_;
	Node<T>* topPtr_;

	public:
	Stack();
	~Stack();

	bool push(const Node<T>& item);
	T pop();
	T top() const;
	void destroy();

	bool isEmpty() const;
	size_t size() const;
};
} // namespace polish_notation::data_structures::stack

#endif // STACK_H