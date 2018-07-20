#include <stdio.h>

#define MAX 10000 + 1

typedef enum {false, true} bool;

typedef struct Node* PtrToNode;
typedef PtrToNode List;
struct Node {
	int Index;
	PtrToNode Next;
};

PtrToNode G[MAX];

PtrToNode Insert(const List L, const int index);

int main(int argc, char* argc[]) {
	int nNodes, nEdges;
	scanf("%d%d", &nNodes, &nEdges);
	for (int i=0; i!=MAX; ++i) {
		G[i] = NULL;
	}

	for (int i=0; i!=nEdges; ++i) {

	}
	return 0;
}

