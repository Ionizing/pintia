/*
二分查找
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    freopen("in.txt", "r", stdin);
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput() {
    List L = (List)malloc(sizeof(LNode));

    int N, i;
    scanf("%d", &N);
    for(i=1; i<=N; ++i) {
        scanf("%d", &(L->Data[i]));
    } L->Last = --i;
    return L;
}

Position BinarySearch( List L, ElementType X ) {
    if(0 == L->Last) {
        return NotFound;
    }

    int left  = 1,
        right = L->Last,
        mid = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if( L->Data[mid] == X ) {
            return mid;
        } else if ( X < L->Data[mid] ) {
            right = mid - 1;
            continue;
        } else if ( X > L->Data[mid] ) {
            left = mid + 1;
            continue;
        }
    }
    return NotFound;
}