#pragma once

template <typename T> void Vector<T>::shrink() {

   if ( _capacity < DEFAULT_CAPACITY << 1 ) return; //不致收缩到DEFAULT_CAPACITY以下

   if ( _size << 2 > _capacity ) return; //以25%为界

   T* oldElem = _elem;
    _elem = new T[_capacity >>= 1];
    
   for ( int i = 0; i < _size; i++ )
      _elem[i] = oldElem[i];

   delete [] oldElem;
}