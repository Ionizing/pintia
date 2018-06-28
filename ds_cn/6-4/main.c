/*
本题要求实现一个函数，找到并返回链式表的第K个元素。
*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    freopen("in.txt", "r", stdin);
    int N, K;
    ElementType X;
    List L = Read();

    PtrToLNode p = L;
    while (NULL != p) {
        printf("%d ", p->Data);
        p = p->Next;
    } puts("");

    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

List Read() {
    List Head = NULL;
    PtrToLNode p = Head;
    int is_head = 1;

    ElementType n;
    scanf("%d", &n);
    
    while(-1 != n) {
        if(1 == is_head) {
            Head = (List)malloc(sizeof(struct LNode));
            p = Head;
            is_head = 0;
        } else {
            p->Next = (List)malloc(sizeof(struct LNode));
            p = p->Next;
        }
        p->Data = n;
        p->Next = NULL;
        scanf("%d", &n);
    }
    return Head;
}

ElementType FindKth( List L, int K ) {
    int i;
    PtrToLNode p;
    for(i=1, p=L; i!=K && NULL!=p; ++i, p=p->Next) {}
    if(NULL == p){
        return ERROR;
    }

    return p->Data;
}