#pragma once

#include "List.h"

// 在无序列表内节点 p 的 n 个前驱中查找等于 e 的最后者
template <typename T>
Posi(T) List<T> :: _find (T const &e, Posi(T) p, int n) const {
   
    while(n--)
        if(e == (p = p->succ)->data)
            return p;

    return nullptr;
}