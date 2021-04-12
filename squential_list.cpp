//
// Created by qinlipeng on 2021/4/12.
//

#include <iostream>

#define MAXSIZE 100
using namespace std;
typedef struct{
    string name;
    int no;
}ElemType;

typedef struct{
    ElemType *elem;
    int length;
}SqList;

bool InitList_Sq(SqList &L) {
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem)
        return false;
    L.length = 0;
    return true;
}


bool ListInsert_Sq(SqList &L, const ElemType& e, int pos){
    if (pos < 1 || pos > L.length+1 || L.length == MAXSIZE)
        return false;
    for (int i = L.length-1; i > pos-1; i--){
        L.elem[i+1] = L.elem[i];
    }
    L.elem[pos-1] = e;
    ++L.length;
    return true;
}
int LocateElem_Sq(SqList L, const ElemType& e){
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i].name == e.name && L.elem[i].no == e.no)
            return i+1;
    }
    return 0;
}

bool ListDelete_Sq(SqList &L, int pos, ElemType &e){
    if (pos < 1 || pos > L.length) {
        return false;
    }
    e = L.elem[pos-1];
    for (int i = pos; i < L.length; i++) {
        L.elem[i-1] = L.elem[i];
    }
    --L.length;
    return true;
}
int main(){

    SqList L;
    if (InitList_Sq(L))
        cout << "Initial successfully.\n";
    ElemType e, e1, e2;
    e1.name= "test";
    e1.no = 1;
    e2.name = "Test";
    e2.no = 2;
    if (ListInsert_Sq(L, e1, 1))
        ListInsert_Sq(L, e2, 2);
    cout << LocateElem_Sq(L, e2) << endl;
    if(ListDelete_Sq(L,2,e))
        cout << "Delete successfully.\n";
    return 0;
}
