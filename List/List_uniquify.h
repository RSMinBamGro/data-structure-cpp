#pragma once

#include "List.h"
#include "list_remove.h"

template <typename T>
int List<T> :: uniquify() { // 与有序向量的唯一化类似，批量剔除重复元素
    if(_size < 2) return 0;

    int oldSize = _size;

    Posi(T) p = head(); Posi(T) q;
    while((q = p ->succ) != trailer) // 反复考察紧邻的节点对 (p, q)
        if(p->data != q->data)
            p = q; // 互异则转向下一区段
        else {
            _remove(q); // 雷同则删除后者
            // q = nullptr; 
        }
    
    return oldSize - _size;
}