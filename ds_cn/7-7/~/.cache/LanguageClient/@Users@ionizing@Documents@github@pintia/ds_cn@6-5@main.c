#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    freopen("in.txt", "r", stdin);
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

Position Find( List L, ElementType X ) {
    PtrToLNode p = L;
    while(NULL != p) {
        if (p->Data == X) {
            return p;
        }
        p = p->Next;
    }
    return ERROR;
}

List Insert( List L, ElementType X, Position P ) {
    PtrToLNode p;

// Insert at position 0 (Head);
    if (L == P) {
        p = (PtrToLNode)malloc(sizeof(struct LNode));
        p->Next = L;
        p->Data = X;
        return p;
    }

// Else
    for(p=L; p->Next != P; p=p->Next) {
        if (NULL == p->Next) {
            puts("Wrong Position for Insertion");
            return ERROR;
        }
    }
    PtrToLNode tmp = p->Next;
    p->Next = (PtrToLNode)malloc(sizeof(struct LNode));
    p->Next->Next = tmp;
    p->Next->Data = X;
    return L;
}

List Delete( List L, Position P ) {
    if (NULL == P || NULL == L) {
        puts("Wrong Position for Deletion");
        return ERROR;
    }

    if (L == P){
        PtrToLNode tmp = L;
        L = L->Next;
        free(tmp);
        return L;
    }

    PtrToLNode p;
    for(p = L; p->Next != P; p=p->Next){
        if (NULL == p->Next) {
            puts("Wrong Position for Deletion");
            return ERROR;
        }
    }
    PtrToLNode tmp = p->Next;
    p->Next = tmp->Next;
    free(tmp);
    return L;
}