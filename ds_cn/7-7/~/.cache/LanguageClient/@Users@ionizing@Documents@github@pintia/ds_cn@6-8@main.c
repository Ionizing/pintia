#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight( BinTree BT );

int main()
{
	freopen("in.txt", "r", stdin);
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

// CreatBinTree() may have bugs.
BinTree CreatBinTree() {
	int N;
	scanf("%d", &N);
	getchar();
	BinTree Root = (BinTree)malloc(N * sizeof(TNode));
	
	ElementType data;
	char lchild, rchild;
	for(int i=0; i!=N; ++i){
		scanf("%c %c %c", &data, &lchild, &rchild);
		getchar();
		Root[i].Data = data;
		Root[i].Left = ('-' == lchild) ? NULL : &Root[lchild - '0'];
		Root[i].Right = ('-' == rchild) ? NULL : &Root[rchild - '0'];
	}
	return Root;
}

int GetHeight( BinTree BT ) {
	if (NULL == BT) {
		return 0;
	}
	int ltreeH, rtreeH;
	ltreeH = GetHeight(BT->Left);
	rtreeH = GetHeight(BT->Right);
	return ltreeH > rtreeH ? ltreeH + 1 : rtreeH + 1;
}