#pragma once

template <typename T> 
void Vector<T>::copyFrom (T const* A, Rank lo, Rank hi) { //以数组区间A[lo, hi)为蓝本复制向量
   
   _elem = new T[_capacity = 2 * ( hi - lo ) ];
   _size = 0;
   
   while (lo < hi)
      _elem[_size ++] = A[lo ++];
}