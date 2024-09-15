#ifndef QUEUE_H
#define QUEUE_H

#include "polish_notation/data_structures/node/node.h"
#include "polish_notation/utility.h"

namespace polish_notation::data_structures::queue {
using ::polish_notation::data_structures::node::Node;

template <typename T>
class Queue {
   private:
    Node<T>* frontPtr_;
    Node<T>* backPtr_;
    ::polish_notation::utility::size_t size_;

    void deleteNodeAndMoveBackPtrToNextNode();

   protected:
    const Node<T>* frontPtr() const;
    const Node<T>* backPtr() const;

   public:
    Queue();
    Queue(const Queue& q);
    Queue<T> operator=(const Queue& q) = delete;
    ~Queue();

    void enqueue(const T& item);
    T dequeue();
    T peek() const;
    void destroy();

    bool isEmpty() const;
    ::polish_notation::utility::size_t size() const;
};
} // namespace polish_notation::data_structures::queue

#include "queue.ipp"

#endif // QUEUE_H