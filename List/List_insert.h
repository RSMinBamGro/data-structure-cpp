#pragma once

#include "List.h"

template <typename T>
Posi(T) List<T> :: insertAsFirst (T const &e) {
    _size++;
    return header->insertAsSucc(e);
}

template <typename T>
Posi(T) List<T> :: insertAsLast (T const &e) {
    _size++;
    return trailer->insertAsPred(e);
}

template <typename T>
Posi(T) List<T> :: insertBefore (Posi(T) p, T const &e) {
    _size++;
    return p->insertAsPred(e);
}

template <typename T>
Posi(T) List<T> :: insertAfter (Posi(T) p, T const &e) {
    _size++;
    return p->insertAsSucc(e);
}