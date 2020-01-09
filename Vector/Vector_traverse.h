#pragma once

template <typename T> void Vector<T>::traverse ( Vector<T>::VST_pointer visit ) {//函数指针
    for ( int i = 0; i < _size; i++ )
        visit ( _elem[i] );
}

template <typename T> template <typename VST_object> /** 元素类型、操作器 */
void Vector<T>::traverse ( VST_object& visit ) { //函数对象

    /**
     * 函数对象机制中，在定义类的时候重载操作符 “()” 
     * 该类创建的对象即可做函数使用
     */

    for ( int i = 0; i < _size; i++ )
        visit ( _elem[i] );
}
