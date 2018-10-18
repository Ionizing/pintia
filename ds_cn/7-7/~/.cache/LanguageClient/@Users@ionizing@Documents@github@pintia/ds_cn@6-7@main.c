#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
// typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */

int main()
{
    freopen("in.txt", "r", stdin);
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

Operation GetOp() {
    char str[10];
    fscanf(stdin, "%s", str);
    if ('u' == str[1]) return push;
    if ('o' == str[1]) return pop;
    return end;
}

void PrintStack( Stack S, int Tag ) {
    if (1 == Tag) {
        int i;
        for(i=S->Top1; i!=-1; --i) {
            printf(" %d", S->Data[i]);
        }
    } else {
        int i;
        for(i=S->Top2; i!=S->MaxSize; ++i){
            printf(" %d", S->Data[i]);
        }
    }
}

Stack CreateStack( int MaxSize ) {
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
    S->Top1 = -1;
    S->Top2 = MaxSize;
    S->MaxSize = MaxSize;
    return S;
}

bool Push( Stack S, ElementType X, int Tag ) {
    if(NULL == S) {
        return false;
    }

    if(S->Top2 - S->Top1 == 1){
        printf("Stack Full\n");
        return false;
    }

    if(1 == Tag) {
        ++(S->Top1);
        S->Data[S->Top1] = X;
    } else {
        --(S->Top2);
        S->Data[S->Top2] = X;
    }
    return true;
}

ElementType Pop( Stack S, int Tag ) {
    if(1 == Tag) {
        if (-1 == S->Top1) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        ElementType tmp = S->Data[S->Top1];
        --(S->Top1);
        return tmp;
    } else {
        if (S->MaxSize == S->Top2) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        ElementType tmp = S->Data[S->Top2];
        ++(S->Top2);
        return tmp;
    }
}