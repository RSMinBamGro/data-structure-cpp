#pragma once

template <typename T> Vector<T>& Vector<T>::operator= ( Vector<T> const& V ) { //深拷贝

   if ( _elem ) delete [] _elem; //释放原有内容

   copyFrom ( V._elem, 0, V.size() );
   
   return *this;
}