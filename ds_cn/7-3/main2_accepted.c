/* isMorphic */

#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
typedef struct TNode* PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode Tree;
typedef char ElementType;
struct TNode {
	ElementType Data;
	Tree Left, Right;
};

Tree CreateBinTree();
bool isMorphic(Tree A, Tree B);
void InorderTraversal(Tree A);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	Tree A = CreateBinTree();
	Tree B = CreateBinTree();

	if (isMorphic(A, B)) {
		puts("Yes");
	} else {
		puts("No");
	}
	return 0;
}

Tree CreateBinTree() {
	int line_num;
	scanf("%d", &line_num); getchar();
	if (0 == line_num) {
		return NULL;
	}

	int check[10];
	for(int i=0; i!=10; ++i) {
		check[i] = 0;
	}

	Tree Root = (Tree)malloc(line_num * sizeof(struct TNode));
	ElementType tmpData, left, right;
	for (int i=0; i!=line_num; ++i) {
		scanf("%c %c %c", &tmpData, &left, &right); getchar();
		Root[i].Data = tmpData;
		if ('-' != left) {
			Root[i].Left = &Root[left - '0'];
			check[left - '0'] = 1;
		} else {
			Root[i].Left = NULL;
		}

		if ('-' != right) {
			Root[i].Right = &Root[right - '0'];
			check[right - '0'] = 1;
		} else {
			Root[i].Right = NULL;
		}
		// printf("@68 %c %c %c\n", tmpData, left, right);
	}

	for(int i=0; i!=line_num; ++i) {
		if (!check[i]) {
			return Root + i;
		}
	}
	puts("@70");
	return Root;
}

bool isMorphic(Tree A, Tree B) {
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

void InorderTraversal(Tree A) {
	if (NULL == A) {
		return;
	}
	InorderTraversal(A->Left);
	printf(" %c", A->Data);
	InorderTraversal(A->Right);
}