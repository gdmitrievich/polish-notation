#ifndef QUEUE_H
#define QUEUE_H

#include "polish_notation/utility/utility.h"

namespace polish_notation::data_structures::node {
template <typename T>
struct Node;
}

namespace polish_notation::data_structures::queue {
template <typename T>
class Queue {
   private:
    ::polish_notation::data_structures::node::Node<T>* frontPtr_;
    ::polish_notation::data_structures::node::Node<T>* backPtr_;
    ::polish_notation::utility::size_t size_;

    void deleteNodeAndMoveBackPtrToNextNode() noexcept;
    void copyNodesFrom(const Queue<T>& q);

   protected:
    const ::polish_notation::data_structures::node::Node<T>* frontPtr()
        const noexcept;
    const ::polish_notation::data_structures::node::Node<T>* backPtr()
        const noexcept;

   public:
    Queue() noexcept;
    Queue(const Queue& q);
    Queue<T> operator=(const Queue& q);
    ~Queue() noexcept;

    void enqueue(const T& item);
    T dequeue();
    T peek() const;
    void destroy() noexcept;

    bool isEmpty() const noexcept;
    ::polish_notation::utility::size_t size() const noexcept;
};
} // namespace polish_notation::data_structures::queue

#include "queue.ipp"

#endif // QUEUE_H