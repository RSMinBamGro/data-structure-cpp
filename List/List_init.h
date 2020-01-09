#pragma once

#include "List.h"

template <typename T>
void List<T> :: init() {
    header = new ListNode<T>();
    trailer = new ListNode<T>();

    header->pred = nullptr;
    header->succ = trailer;

    trailer->pred = header;
    trailer->succ = nullptr;

    _size = 0;
}