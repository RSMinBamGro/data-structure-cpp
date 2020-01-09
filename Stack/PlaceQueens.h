#include "Stack.h"
using namespace std;

int nCheck = 0, nSolu = 0;
void placeQueens (int N) {
    Stack<Queen> solu;
    Queen q(0, 0);

    do{
        if(solu._length() >= N || q.y >= N) {
        //�����磨����Ϊ��ͻλ�ã�
            q = solu._pop();  //����
            q.y++;            //����̽��һ��
        }else {
            while((q.y < N) && (solu._find(q) >= 0)) {
            //�����лʺ�Աȼ���Ƿ��ͻ
                q.y++;        //�����ҵ��ɹ��ڷ���һ�ʺ����
                nCheck++;
            }
            if(q.y < N) {
            //�����ڿɹ��ڷŵ���
                solu._push(q); //���ûʺ�
                if(solu._length() >= N) nSolu++;

                q.x++;         //ת����һ��
                q.y = 0;       //�Ե�0�п�ʼ����̽��һ�ʺ�
            }
         }
    } while((q.x > 0) || (q.y < N));
      //�����з�֧������ٻ��֦���㷨����
}