#pragma once
#include "Stack.h"

static char digit[]
    = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
void convert_recursion (Stack<char> &S, int n, int base) {
    if(n > 0) {
        S._push(digit[n % base]);
        convert_recursion(S, n / base, base);
    }
}

void convert_iteration (Stack<char> &S, int n, int base) {
    while(n > 0) {
        int remainder = (int) (n % base);
        S._push(digit[remainder]);
        n /= base;
    }
}