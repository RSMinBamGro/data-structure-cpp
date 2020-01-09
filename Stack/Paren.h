#pragma once
#include "Stack.h"

bool paren (const char exp[], int lo, int hi) {
    Stack<char> S;
    for(int i = lo; i <= hi; i++)
        switch(exp[i]) {
            case '(': case '[': case '{': S._push(exp[i]); break;
            case ')': if((S._empty()) || ('(' != S._pop())) return false; break;
            case ']': if((S._empty()) || ('[' != S._pop())) return false; break;
            case '}': if((S._empty()) || ('{' != S._pop())) return false; break;
            default: break;
        }
    return S._empty();
}