#include <stdio.h>
#include <stdlib.h>

// typedef enum {false, true} bool;
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree();
bool isSame(BinTree A, BinTree B);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUEGE
	freopen("in.txt", "r", stdin);
#endif

	BinTree A = CreatBinTree();
	BinTree B = CreatBinTree();
	if (isSame(A, B)){
		puts("Yes");
	} else {
		puts("No");
	}

	return 0;
}

BinTree CreatBinTree() {
	int N;
	scanf("%d", &N);
	getchar();
	if (0 == N) {
		return NULL;
	}

	int check[N];
	for(int i=0; i!=N; ++i) {
		check[i] = 0;
	}

	BinTree Root = (BinTree)malloc(N * sizeof(struct TNode));

	ElementType data;
	char lchild, rchild;
	for(int i=0; i!=N; ++i){
		scanf("%c %c %c", &data, &lchild, &rchild);
		getchar();

		if ('-' != lchild) {
			check[lchild - '0'] = 1;
		}
		if ('-' != rchild) {
			check[rchild - '0'] = 1;
		}

		Root[i].Data = data;
		Root[i].Left = ('-' == lchild) ? NULL : &Root[lchild - '0'];
		Root[i].Right = ('-' == rchild) ? NULL : &Root[rchild - '0'];
	}
	for(int i=0; i!=N; ++i) {
		if (!check[i]) {
			return Root + i;
		}
	}
	return Root;
}

bool isSame(BinTree A, BinTree B) {
	if (NULL == A && NULL == B) {
		return true;
	} else if (NULL == A || NULL == B) {
		return false;
	} else if (A->Data != B->Data) {
		return false;
	} else {
		return (isSame(A->Left, B->Left) && isSame(A->Right, B->Right)) ||
			(isSame(A->Left, B->Right) && isSame(A->Right, B->Left));
	}
}