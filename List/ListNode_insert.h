#pragma once

#include "ListNode.h"

template <typename T>
Posi(T) ListNode<T> :: insertAsPred (T const &e) {
    Posi(T) x = new ListNode(e, pred, this);

    this->pred->succ = x;
    this->pred = x;
    // x->pred->succ = x;
    // x->succ->pred = x;

    return x;
}


template <typename T>
Posi(T) ListNode<T> :: insertAsSucc (T const &e) {
    Posi(T) x = new ListNode(e, this, succ);

    this.succ->pred = x;
    this.succ = x;

    return x;
}