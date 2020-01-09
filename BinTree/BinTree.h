#pragma once
#include "BinNode.h"
#include "functions.h"

using namespace std;

template <typename T>
class BinTree {
protected:
    int _size;
    Posi(T) _root;

    virtual int updateHeight (Posi(T));
    void updateHeightAbove (Posi(T));

public:
    BinTree () : _size(0), _root(nullptr) { }
    ~BinTree () { if(_size > 0) remove (_root); }

    int size () { return _size; }
    bool _empty () { return !_size; }

    Posi(T) root() { return _root; }

    Posi(T) insertAsRoot (T const &e);
    Posi(T) insertAsLChild (Posi(T), T const &);
    Posi(T) insertAsRChild (Posi(T), T const &);

    Posi(T) attachAsLSub (Posi(T), BinTree<T>* &);
    Posi(T) attachAsRSub (Posi(T), BinTree<T>* &);

    int _remove (Posi(T));
    BinTree<T>* secede (Posi(T));

    typedef void (*VST)(T &);
    
    void travPre(VST);
    void travIn(VST);
    void travPost(VST);

    bool operator== (BinTree<T> const &t) {
        return _root && t._root && ( _root == t._root ); 
    } 
};

template <typename T>
int BinTree<T> :: updateHeight(Posi(T) x) {
    return x->height = 1 + max( stature( x->lChild ), stature( x->rChild ) );
}

template <typename T>
void  BinTree<T> :: updateHeightAbove(Posi(T) x) {
    while(x) {
        updateHeight(x);
        x = x->parent;
    }
}

template <typename T>
Posi(T) BinTree<T> :: insertAsRoot (T const &e) {
    _size = 1;
    return _root = new BinNode<T> (e);
}

template <typename T>
Posi(T) BinTree<T> :: insertAsLChild (Posi(T) x, T const &e) {
    _size ++;
    x->insertAsLChild(e);

    updateHeightAbove(x);

    return x->lChild;
}

template <typename T>
Posi(T) BinTree<T> :: insertAsRChild (Posi(T) x, T const &e) {
    _size ++;
    x->insertAsRChild(e);

    updateHeightAbove(x);

    return x->rChild;
}

template <typename T>
Posi(T) BinTree<T> :: attachAsLSub (Posi(T) x, BinTree<T>* &S) {
    if(x->lChild = S->_root) x->lChild->parent = x;
    _size += S->_size;
    
    updateHeightAbove(x);

    S->_root = nullptr;
    S->_size = 0;
    //release(S);
    S = nullptr;

    return x;
}

template <typename T>
Posi(T) BinTree<T> :: attachAsRSub (Posi(T) x, BinTree<T>* &S) {
    if(x->rChild = S->_root) x->rChild->parent = x;
    _size += S->_size;
    
    updateHeightAbove(x);

    S->_root = nullptr;
    S->_size = 0;
    //release(S);
    S = nullptr;

    return x;
}

template <typename T>
int BinTree<T> :: _remove (Posi(T) x) {
    FromParentTo(*x) = nullptr;

    updateHeightAbove(x->parent);

    int n = removeAt(x);
    _size -= n;;

    return n;
}


template <typename T>
static int removeAt (Posi(T) x) {
    if(!x) return 0;

    int n =  1 + removeAt(x->lChild) + removeAt(x->rChild);
    //release(x);
    return n;
}


template <typename T>
BinTree<T>* BinTree<T> :: secede (Posi(T) x) {
    FromParentTo(*x) = nullptr;
    x->parent = nullptr;

    updateHeightAbove(x);

    BinTree<T>* S = new BinTree<T>;
    S->_root = x;
    S->_size = x->size();
    _size -= S->_size;

    return S;
}

template <typename T>
void BinTree<T> :: travPre(VST visit) {
    if(_root)
        _root->travPre(visit);
}

template <typename T>
void BinTree<T> :: travIn(VST visit) {
    if(_root)
        _root->travIn(visit);
}

template <typename T>
void BinTree<T> :: travPost(VST visit) {
    if(_root)
        _root->travPost(visit);
}