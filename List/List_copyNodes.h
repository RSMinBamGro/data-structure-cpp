#pragma once

#include "List.h"
#include "list_insert.h"

template <typename T>
void List<T> :: copyNodes (Posi(T) p, int n) {
    init();
    while(n--) {
        insertAsLast(p->data);
        p = p->succ;
    }
}