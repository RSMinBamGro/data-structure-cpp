#pragma once

class Fib {
private :
    int f, g;
public:
    Fib (int n) {
        f = 1; g = 0;
        while (g < n)
            next(); // 初始化为不小于 n 的最小 Fibonacci 项
    }

    int get () { return g; } // 获取当前 Fibonacci 项
    
    int next () {
        g += f;
        f = g - f;
        return g;
    }

    int prev () {
        f = g - f;
        g -= f;
        return g;
    }
};