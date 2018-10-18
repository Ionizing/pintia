/*
	二叉树的遍历
*/

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
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
	freopen("in.txt", "r", stdin);
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
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

void InorderTraversal( BinTree BT ) {
	if (NULL == BT) {
		return;
	}
	InorderTraversal(BT->Left);
	printf(" %c", BT->Data);
	InorderTraversal(BT->Right);
}

void PreorderTraversal( BinTree BT ) {
	if (NULL == BT){
		return;
	}
	printf(" %c", BT->Data);
	PreorderTraversal(BT->Left);
	PreorderTraversal(BT->Right);
}

void PostorderTraversal( BinTree BT ) {
	if (NULL == BT) {
		return;
	}
	PostorderTraversal(BT->Left);
	PostorderTraversal(BT->Right);
	printf(" %c", BT->Data);
}

void LevelorderTraversal( BinTree BT ) {
	BinTree q[100]; // queue;
	if (NULL == BT) {
		return;
	}
	int head = 0, tail = 0;
	q[tail++] = BT;
	while(head != tail) {
		if(NULL != q[head]->Left) {
			q[tail++] = q[head]->Left;
		}
		if(NULL != q[head]->Right) {
			q[tail++] = q[head]->Right;
		}
		printf(" %c", q[head++]->Data);
	}
}