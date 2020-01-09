#pragma once

#include "List.h"

template <typename T>
void List<T> :: traverse (List<T>::VST_pointerFunc visit) {
    for (Posi(T) p = header->succ; p != trailer; p = p->succ)
        visit(p->data);
}

template <typename T> template <typename VST_objectFunc>
void List<T> :: traverse (VST_objectFunc& visit) {
    for(Posi(T) p = header->succ; p != trailer; p = p->succ)
        visit(p->data);
}