#pragma once

#include "List.h"

template <typename T>
Posi(T) List<T> :: operator[] (Rank r) const {
    Posi(T) p = header->succ;
    while(r--)
        p = p->succ;
    return p;
}