#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct TNode* PtrToNode;
typedef PtrToNode BST;
typedef int ElementType;
struct TNode {
	ElementType Data;
	BST Left;
	BST Right;
};

BST CreateBST(const int num);
BST Insert(const BST T, const ElementType X);
bool isMorphic(const BST A, const BST B);
void InorderTraversal(const BST BT);
void DeleteTree(const BST BT);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int elem_num, rec_num;
	scanf("%d", &elem_num);
	while (0 != elem_num){
		scanf("%d", &rec_num);
		BST orig = CreateBST(elem_num);
		BST to_compare;
		for(int i=0; i!=rec_num; ++i) {
			to_compare = CreateBST(elem_num);
			puts(isMorphic(orig, to_compare) ? "Yes" : "No");
			DeleteTree(to_compare);
		}
		DeleteTree(orig);
		scanf("%d", &elem_num);
	}
	return 0;
}

BST CreateBST(const int num) {
	BST root = NULL;
	for (int i=0; i!=num; ++i) {
		int tmpData;
		scanf("%d", &tmpData);
		root = Insert(root, tmpData);
	}
	return root;
}

BST Insert(const BST T, const ElementType X) {
	if (NULL == T) {
		BST tmp = (BST)malloc(sizeof(struct TNode));
		tmp->Data = X;
		tmp->Left = tmp->Right = NULL;
		return tmp;
	} else if (X < T->Data) {
		T->Left = Insert(T->Left, X);
	} else {
		T->Right = Insert(T->Right, X);
	}
	return T;
}

bool isMorphic(const BST A, const BST B) {
	if (NULL == A && NULL == B) {
		return true;
	} else if (NULL == A || NULL == B) {
		return false;
	} else if (A->Data != B->Data) {
		return false;
	} else {
		return (isMorphic(A->Left, B->Left) && isMorphic(A->Right, B->Right))
			|| (isMorphic(A->Right, B->Left) && isMorphic(A->Left, B->Right));
	}
}

void InorderTraversal(const BST BT) {
	if (NULL == BT) {
		return;
	}
	InorderTraversal(BT->Left);
	printf(" %d", BT->Data);
	InorderTraversal(BT->Right);
}

void DeleteTree(const BST BT) {
	if (NULL == BT) {
		return;
	}
	DeleteTree(BT->Left);
	DeleteTree(BT->Right);
	free(BT);
}