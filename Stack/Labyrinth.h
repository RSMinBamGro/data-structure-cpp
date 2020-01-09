#pragma once
#include "Stack.h"

bool labyrinth (Cell Laby[LABY_MAX][LABY_MAX], Cell *s, Cell *t) {
    if((s->status != AVAILABLE) || (t->status != AVAILABLE)) return false;
    //�˻����
    Stack<Cell*> path;
    s->incoming = UNKNOW; s->status = ROUTE;
    path._push(s);

    do{
        Cell *c = path._top();
        if(c == t) return true; //�ִ��յ�
        while((c->outgoing = nextESWN(c->outgoing)) < NO_WAY)
        //ע�������з���
            if(neighbor(c)->status == AVAILABLE) break;
            //��ͼ�ҵ���δ��̽�ķ���
        if(c->outgoing >= NO_WAY) {
        //�����з�������̽��
            c->status = BACKTRACKED; //����
            c = path._pop();
        }else {
            path._push(c = advance(c)); //��ǰ��̽
            c->outgoing = UNKNOW;
            c->status = ROUTE;
         }
    } while(!path._empty());

    return false;
}
