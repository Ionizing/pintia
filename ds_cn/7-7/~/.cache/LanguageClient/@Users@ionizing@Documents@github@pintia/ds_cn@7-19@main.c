#include <stdio.h>
#include <stdlib.h>

typedef struct LNode* PtrToNode;
typedef int ElementType;
struct LNode {
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode List;

List BuildList(FILE* fp);
void GetKthElem(const List L, const int K);
void PrintList(const List L);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int K;
	scanf("%d", &K);
	List L = BuildList(stdin);
	// PrintList(L);
	GetKthElem(L, K);
	return 0;
}

List BuildList(FILE* fp) {
	PtrToNode L = NULL;
	PtrToNode p;
	int tmpData;
	fscanf(fp, "%d", &tmpData);
	while (tmpData >= 0) {
		p = (PtrToNode)malloc(sizeof(struct LNode));
		p->Data = tmpData;
		p->Next = L;
		L = p;
		fscanf(fp, "%d", &tmpData);
	}

	return L;
}

void GetKthElem(const List L, const int K) {
	PtrToNode p = L;
	int cnt = 1;
	while (NULL != p) {
		if (K == cnt) {
			printf("%d\n", p->Data);
			return;
		}
		++cnt;
		p = p->Next;
	}
	puts("NULL");
}

void PrintList(const List L) {
	PtrToNode p = L;
	while (NULL != p) {
		printf(" %d", p->Data);
		p = p->Next;
	}
}