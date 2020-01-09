#include "list_all.h"


template <typename T>
void visit (T& e) {
    cout << e << endl;
}

int main () {

    List<int> list;
    list.insertAsLast(1);
    list.insertAsLast(2);
    list.insertAsLast(3);
    list.insertAsLast(4);

    list.traverse(visit);

    list.reverse();

    list.traverse(visit);

    return 0;
}