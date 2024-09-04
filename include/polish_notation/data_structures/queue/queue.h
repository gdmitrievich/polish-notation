#ifndef QUEUE_H
#define QUEUE_H

#include "polish_notation/data_structures/node/node.h"

namespace polish_notation::data_structures::queue {
using ::polish_notation::data_structures::node::Node;
using size_t = decltype(sizeof(1));

template <typename T>
class Queue {
   private:
    Node<T>* frontPtr_;
    Node<T>* backPtr_;
    size_t size_;

   protected:
    const Node<T>* frontPtr() const;

   public:
    Queue();

    void enqueue(const T& item);
    T dequeue();
    T peek() const;
    void destroy();

    bool isEmpty() const;
    size_t size() const;
};
} // namespace polish_notation::data_structures::queue

#include "queue.ipp"

#endif // QUEUE_H