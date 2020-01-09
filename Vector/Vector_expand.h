#pragma once

template <typename T> void Vector<T>::expand() {

   if ( _size < _capacity ) return; //尚未满员时不必扩容

   if ( _capacity < DEFAULT_CAPACITY ) _capacity = DEFAULT_CAPACITY; //容量不低于最小值

   T* oldElem = _elem; /** 创建新指针 *oldElem 指向原空间 */
   _elem = new T[_capacity <<= 1]; //容量加倍
   /** 新数据区地址由操作系统分配，与原空间没有关系 */

   for ( int i = 0; i < _size; i++ )
      _elem[i] = oldElem[i];

   /*DSA*/ //printf("\n_ELEM [%x]*%d/%d expanded and shift to [%x]*%d/%d\n", oldElem, _size, _capacity/2, _elem, _size, _capacity);
   delete [] oldElem; /** 释放原空间 */
}