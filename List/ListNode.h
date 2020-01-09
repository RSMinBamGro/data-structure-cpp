#pragma once

typedef int Rank;
#define Posi(T) ListNode<T>*

template <typename T> struct ListNode {
    T data;
    Posi(T) pred; Posi(T) succ;

    ListNode () {}
    ListNode (T e, Posi(T) p = nullptr, Posi(T) s = nullptr)
        : data(e), pred(p), succ(s) {}

    Posi(T) insertAsPred (T const &e);
    Posi(T) insertAsSucc (T const &e);
};
