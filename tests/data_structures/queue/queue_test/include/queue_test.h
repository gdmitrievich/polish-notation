#ifndef QUEUE_TEST_H
#define QUEUE_TEST_H

#include <initializer_list>

#include "polish_notation/data_structures/queue/queue.h"

namespace polish_notation::tests::data_structures::queue_test {
using ::polish_notation::data_structures::queue::Queue;

template <typename T>
class QueueTest : public Queue<T> {
   public:
    const ::polish_notation::data_structures::node::Node<T>* frontPtr() const;
    const ::polish_notation::data_structures::node::Node<T>* backPtr() const;

    QueueTest();
    QueueTest(const ::std::initializer_list<T>& list);
};
} // namespace polish_notation::tests::data_structures::queue_test

#include "queue_test.ipp"

#endif // QUEUE_TEST_H