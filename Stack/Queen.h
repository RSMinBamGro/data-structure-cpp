#pragma once

struct Queen{
    int x, y;
    Queen()
        : x(0), y(0) {}
    Queen (int xx, int yy)
        : x(xx), y(yy) {}
    bool operator== (Queen const &another) const {
        return (x == another.x)
               || (y == another.y)
               || (x + y == another.x + another.y)  // k = -1
               || (x - y == another.x - another.y); // k = 1
    }
    bool operator!= (Queen const &another) const {
        return !(*this == another);
    }
};

