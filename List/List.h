#pragma once

#include <iostream>
#include <cstdlib>

#include "ListNode.h"
#include "listNode_insert.h"

using namespace std;

template <typename T> class List {
private:
    int _size;
    Posi(T) header;
    Posi(T) trailer;

protected:
    // 初始化
    void init ();

    // 清除所有节点
    int clear ();

    // 复制列表中自位置 p 始的 n 项
    void copyNodes (Posi(T), int);

public:
    // 默认构造函数，针对 header 和 trailer 的初始化
    List () {
        init();
    }

    // 复制列表中自位置 p 始的 n 项
    List (Posi(T) p, int n) {
        copyNodes(p, n);
    }

    // 整体复制列表 L
    List (List<T> const &L) {
        copyNodes(L.head(), L._length());
    }

    // 复制列表中自第 r 项始的 n 项
    List (List<T> const &L, Rank r, int n) {
        Posi(T) p = L.head();
        while(r--)
            p = p->succ;

        copyNodes(p, n);
    }
    

    ~List () {
        clear();

        delete header;
        delete trailer;
    }


    int _length() const { return _size; }
    bool _empty() const { return !_size; }

    Posi(T) head() const { return header->succ;}
    Posi(T) tail() const { return trailer;}


    // 循秩访问
    Posi(T) operator[] (Rank r) const;


    // 无序向量查找
    Posi(T) _find (T const &, Posi(T), int) const;
    Posi(T) _find (T const &e) const {
        return _find(e, trailer, _size);
    }


    // 插入
    Posi(T) insertAsFirst (T const &);
    Posi(T) insertAsLast (T const &);
    Posi(T) insertBefore (Posi(T), T const &);
    Posi(T) insertAfter (Posi(T), T const &);


    // 删除
    T _remove (Posi(T));


    // 无序列表的去重复化
    int deduplicate ();


    // 遍历
    typedef void (*VST_pointerFunc) (T &); void traverse (VST_pointerFunc);
    template <typename VST_objectFunc> void traverse (VST_objectFunc&);


    // 有序列表唯一化
    int uniquify();


    // 有序向量查找
    Posi(T) _search (T const &, Posi(T), int) const;
    Posi(T) _search (T const &e) const {
        return _search(e, trailer, _size);
    }


    // 倒置
    void reverse ();


    void _sort (Posi(T) p, int n) {
        switch(rand() % 3) {
            case 1: insertSort(p, n); break;
            case 2: selectionSort(p, n); break;
            default: mergeSort(p, n); break;
        }
    }

    /** sort functions has not been complicated yet **/
    void insertSort (Posi(T), int);
    void selectionSort (Posi(T), int);
    void mergeSort (Posi(T), int);
};
