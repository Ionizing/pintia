#include <stdio.h>
#include <stdlib.h>
#define INF -999999999

typedef enum {false, true} bool;
typedef struct HNode* Heap;
typedef int ElementType;
struct HNode {
	ElementType Data[1001];
	int size;
};

void Insert(const Heap h, const ElementType X);
void PrintPath(const Heap h, const int ind);
Heap CreateEmptyHeap();

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	Heap h = CreateEmptyHeap();
	int elem_num, paths;
	scanf("%d%d", &elem_num, &paths);
	for(int i=0; i!=elem_num; ++i) {
		ElementType tmp;
		scanf("%d", &tmp);
		Insert(h, tmp);
		// puts("@28");
	}
	for(int i=0; i!=paths; ++i) {
		int ind;
		scanf("%d", &ind);
		PrintPath(h, ind);
	}
	return 0;
}

void Insert(const Heap h, const ElementType X) {
	++(h->size);
	ElementType* arr = h->Data;
	int i;
	for (i=h->size; X<arr[i/2]; i/=2) {
		arr[i] = arr[i/2];
		// printf("X = %d, arr[%d/2] = %d\n", X, i, arr[i/2]);
		// printf("@45 arr[%d] = arr[%d/2]\n", i, i);
	}
	arr[i] = X;
}

void PrintPath(const Heap h, const int ind) {
	bool is_first = true;
	for (int i=ind; i!=0; i/=2) {
		if (is_first) {
			is_first = false;
		} else {
			putchar(' ');
		}
		printf("%d", h->Data[i]);
	}putchar('\n');
}

Heap CreateEmptyHeap() {
	Heap h = (Heap)malloc(sizeof(struct HNode));
	h->size = 0;
	h->Data[0] = INF;
	return h;
}