#pragma once

#include "List.h"

template <typename T>
void List<T>::reverse () {
    Posi(T) p = header;
    Posi(T) q = trailer;

    while((p = p->succ) != (q = q->pred) && p->pred != q) {
        // exch()
        T tmp = p->data;
        p->data = q->data;
        q->data = tmp;
    }
}