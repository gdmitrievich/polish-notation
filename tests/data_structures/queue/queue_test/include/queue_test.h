#ifndef QUEUE_TEST_H
#define QUEUE_TEST_H

namespace std {
template <typename T>
class initializer_list;
} // namespace std

#include "polish_notation/data_structures/queue/queue.h"

namespace polish_notation::tests::data_structures::queue_test {
template <typename T>
class QueueTest : public ::polish_notation::data_structures::queue::Queue<T> {
   public:
    const ::polish_notation::data_structures::node::Node<T>* frontPtr() const;
    const ::polish_notation::data_structures::node::Node<T>* backPtr() const;

    QueueTest();
    QueueTest(const ::std::initializer_list<T>& list);
};
} // namespace polish_notation::tests::data_structures::queue_test

#include "queue_test.ipp"

#endif // QUEUE_TEST_H