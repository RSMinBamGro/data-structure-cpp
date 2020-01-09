#pragma once

#include "List.h"

template <typename T>
T List<T> :: _remove (Posi(T) p) {
    T e = p->data;

    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;

    _size--;
    
    return e;
}