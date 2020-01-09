#pragma once 

#include "List.h"
#include "list_remove.h"

template <typename T>
int List<T>::clear () {
    int oldSize = _size;

    while (_size)
        _remove(header->succ);

    return oldSize;
}