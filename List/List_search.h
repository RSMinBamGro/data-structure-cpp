#pragma once

#include "List.h"

template <typename T>
Posi(T) List<T> :: _search (T const &e, Posi(T) p, int n) const { // 在有序列表内节点 p 的 n 个前驱中，找到不大于 e 的最后者
    
    while(n-- >= 0)
    // 查找失败时，最后一次比较与区间左边界进行，此次比较无实际意义，本质上是为了执行语句 p = p->pred 以返回左边界的前驱，所以循环条件必须是 “>=”
        if(((p->pred)->data) <= e)
            break;
    
    return p;
}