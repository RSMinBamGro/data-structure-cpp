#pragma once
#include "..\Vector\Vector.h"

template <typename T> class Stack : public Vector<T> {
public:

    void _push (T const &e) { this->_insert(this->_length(), e);}
    T _pop() { return this->_remove(this->_length() - 1);}
    T &_top() { return (*this)[this->_length() - 1];}
};
