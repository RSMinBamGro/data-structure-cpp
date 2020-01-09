#pragma once

#include "List.h"
#include "list_find.h"
#include "list_remove.h"

template <typename T>
int List<T>::deduplicate () {
    if (_size < 2) return 0;

    int oldSize = _size;
    Posi(T) p = header;
    Rank r = 0;

    while ((p = p->succ) != trailer) {
        Posi(T) q = _find(p->data, p, r);
        q ? _remove(q) : r ++;
    } // 复杂度 O(n ^ 2)
    
    return oldSize - _size;
}