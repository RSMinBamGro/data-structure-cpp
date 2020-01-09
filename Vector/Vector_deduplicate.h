#pragma once

template <typename T> int Vector<T>::deduplicate() { //无序向量唯一化

   int oldSize = _size; //记录原规模

   Rank i = 1; //从_elem[1]开始
   while ( i < _size ) //自前向后逐一考查各元素_elem[i]
      ( find ( _elem[i], 0, i ) < 0 ) ? //在其前缀中寻找与之雷同者（至多一个）
         i++ : remove ( i ); //若无雷同则继续考查其后继，否则删除雷同者

   /** 错误版
     for ( Rank i = 1; i < _size; i++ ) { //逐一考查_elem[i]
        Rank j = find ( _elem[i], 0, i ); //在_elem[i]的前驱中寻找与之雷同者（至多一个）
        if ( 0 <= j ) remove ( j ); //若存在，则删除之，但在此种情况下会有元素的整体前移，下一迭代不必做 i++
     }
    */

   return oldSize - _size; //向量规模变化量
}