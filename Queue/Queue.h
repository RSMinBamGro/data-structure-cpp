#pragma once
#include"..\List\List.h"

template <typename T> class Queue : public List<T> {
    void enqueue (T const &e) { this->insertAsLast(e);}
    T dequeue() { return this->_remove(head());}
    T &_front() { return this->head()->data;}
};
