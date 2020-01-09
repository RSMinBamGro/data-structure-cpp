#include "Stack.h"
using namespace std;

int nCheck = 0, nSolu = 0;
void placeQueens (int N) {
    Stack<Queen> solu;
    Queen q(0, 0);

    do{
        if(solu._length() >= N || q.y >= N) {
        //若出界（即皆为冲突位置）
            q = solu._pop();  //回溯
            q.y++;            //并试探下一列
        }else {
            while((q.y < N) && (solu._find(q) >= 0)) {
            //与已有皇后对比检查是否冲突
                q.y++;        //尝试找到可供摆放下一皇后的列
                nCheck++;
            }
            if(q.y < N) {
            //若存在可供摆放的列
                solu._push(q); //放置皇后
                if(solu._length() >= N) nSolu++;

                q.x++;         //转入下一行
                q.y = 0;       //自第0列开始，试探下一皇后
            }
         }
    } while((q.x > 0) || (q.y < N));
      //待所有分支均已穷举或剪枝，算法结束
}