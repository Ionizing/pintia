/*
本题要求实现一个函数，求链式表的表长。
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
	freopen("in.txt", "r", stdin);
    List L = Read();
    printf("%d\n", Length(L));
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

int Length( List L ) {
	int length = 0;
	while(NULL != L) {
		++length;
		L = L->Next;
	}
	return length;
}