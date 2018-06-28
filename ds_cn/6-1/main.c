#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
	freopen("in.txt", "r", stdin);
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
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

void Print(List L) {
	printf("List is:\n");
	while(NULL != L) {
		printf("%d ", L->Data);
		L = L->Next;
	}
	puts("");
}

List Reverse(List L) {
	if(NULL != L) {
		PtrToNode p, q, pr;
		p = L;
		q = p->Next;
		L->Next = NULL;
		while(NULL != q){
			pr = q->Next;
			q->Next = p;
			p = q;
			q = pr;
		}
	return p;
	}
	return L;
}