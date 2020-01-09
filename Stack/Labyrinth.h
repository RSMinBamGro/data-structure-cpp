#pragma once
#include "Stack.h"

bool labyrinth (Cell Laby[LABY_MAX][LABY_MAX], Cell *s, Cell *t) {
    if((s->status != AVAILABLE) || (t->status != AVAILABLE)) return false;
    //退化情况
    Stack<Cell*> path;
    s->incoming = UNKNOW; s->status = ROUTE;
    path._push(s);

    do{
        Cell *c = path._top();
        if(c == t) return true; //抵达终点
        while((c->outgoing = nextESWN(c->outgoing)) < NO_WAY)
        //注意检查所有方向
            if(neighbor(c)->status == AVAILABLE) break;
            //视图找到尚未试探的方向
        if(c->outgoing >= NO_WAY) {
        //若所有方向都已试探过
            c->status = BACKTRACKED; //回溯
            c = path._pop();
        }else {
            path._push(c = advance(c)); //向前试探
            c->outgoing = UNKNOW;
            c->status = ROUTE;
         }
    } while(!path._empty());

    return false;
}
