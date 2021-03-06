#pragma once

template <typename T> //无序向量的顺序查找
Rank Vector<T>::find ( T const& e, Rank lo, Rank hi ) const { //assert: 0 <= lo < hi <= _size

   while ( ( lo < hi-- ) && ( e != _elem[hi] ) ); //从后向前，顺序查找

   return hi; //若 hi < lo ，则查找失败，放回 lo - 1 ；否则 hi 即命中元素的秩
}