#pragma once

template <typename T> T & Vector<T>::operator[] ( Rank r ) { //下标运算符的重载
    return _elem[r]; //assert: 0 <= r < _size
}

template <typename T> const T & Vector<T>::operator[] ( Rank r ) const { //仅限于做右值
    return _elem[r]; //assert: 0 <= r < _size
} 