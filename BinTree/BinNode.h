#pragma once

#include <iostream>
#include "..\Stack\Stack.h"

#define Posi(T) BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1)


typedef enum {RB_RED, RB_BLACK} RBColor;

template <typename T>
struct BinNode {
    T data;
    Posi(T) parent;
    Posi(T) lChild;
    Posi(T) rChild;
    int height;
    int npl;
    RBColor color;

    BinNode () :
        parent(nullptr), lChild(nullptr), rChild(nullptr),
        height(0), npl(1), color(RB_RED) { }
    BinNode (T e, Posi(T) p = nullptr, Posi(T) lc = nullptr, Posi(T) rc = nullptr, 
            int h =  0, int l = 1, RBColor c = RB_RED) :
        data(e), parent(p), lChild(lc), rChild(rc), height(h), npl(l), color(c) { }

    ~BinNode () {
        if(parent) delete parent;
        if(lChild) delete lChild;
        if(rChild) delete rChild;
    }

    int size ();
    Posi(T) insertAsLChild (T const &);
    Posi(T) insertAsRChild (T const &);
    Posi(T) succ ();

    
    typedef void (*VST)(T &);
    void travLevel (VST);

    void travPre (VST);
    void travIn (VST);
    void travPost (VST);


    bool operator< (BinNode const &bn) { return data < bn.data; }
    bool operator== (BinNode const &bn) { return data == bn.data; }
};

template <typename T>
Posi(T) BinNode<T> :: insertAsLChild (T const &e) {
    return lChild = new BinNode (e, this);
}

template <typename T>
Posi(T) BinNode<T> :: insertAsRChild (T const &e) {
    return rChild = new BinNode (e, this);
}


template <typename T>
void visit (T &e) { cout << e << endl; }

template <typename T>
void BinNode<T> :: travPre (VST visit) {
    switch (rand() % 2) {
        case 1: travPre_recursion (this, visit); break;
        default: travPre_iteration (this, visit); break;
    }
}


template <typename T>
void travPre_recursion (Posi(T) x,  void (*visit) (T &)) {
    if(!x) return ;

    visit(x->data);
    travPre_R(x->lChild);
    travPre_R(x->rChild);
}


template <typename T>
void visitAlongLeftBranch (Posi(T) x,  void (*visit) (T &), Stack<Posi(T)> &S) {
    while(x) {
        visit(x->data);
        S._push(x->rChild);
        x = x->lChild;
    }
}

template <typename T>
void travPre_iteration (Posi(T) x, void (*visit) (T &)) {
    Stack<Posi(T)> S;
    while(true) {
        visitAlongLeftBranch(x, visit, S);
        if(S._empty()) break;
        x = S._pop();
    }
}

template <typename T>
void BinNode<T> :: travIn (VST visit) {
    switch (rand() % 2) {
        case 1: travIn_recursion(this, visit); break;
        default: raveIn_iteration(this, visit); break;
    }
}

template <typename T>
void travIn_recursion (Posi(T) x, void (*visit) (T &)) {
    if(!x) return ;

    travIn(x->lChild);
    visit(x->data);
    travIn(x->rChild);
}

template <typename T>
void goAlongLeftBranch (Posi(T) x, Stack<Posi(T)> S) {
    while(x) {
        S._push(x);
        x = x->lChild;
    }
}

template <typename T>
void travIn_iteration (Posi(T) x, void (*visit) (T &)) {
    Stack<Posi(T)> S;
    while(true) {
        goAlongLeftBranch(x, S);

        if(S._empty()) break;

        x = S._pop();
        visit(x->data);
        x = x->rChild;
    }
    
}

template <typename T>
void BinNode<T> :: travPost (VST visit) {
    if(!this) return ;

    travPost(this->lChild);
    travPost(this->rChild);
    visit(this->data);
}