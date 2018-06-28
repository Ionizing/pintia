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
void PreorderPrintLeaves( BinTree BT );

int main()
{
	freopen("in.txt", "r", stdin);
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

    return 0;
}

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

void PreorderPrintLeaves( BinTree BT ) {
	if (NULL == BT) {
		return;
	}
	if (NULL == BT->Left && NULL == BT->Right) {
		printf(" %c", BT->Data);
		return;
	} else {
		PreorderPrintLeaves(BT->Left);
		PreorderPrintLeaves(BT->Right);
	}
}