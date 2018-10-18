/* Paths in heap
  Wrong solution.
 */

#include <stdio.h>
#include <stdlib.h>

#define lchild(i) (i<<1)
#define rchild(i) ((i<<1) + 1)

typedef enum {false, true} bool;
typedef int ElementType;
typedef struct HeapNode* Heap;
struct HeapNode {
	ElementType Data[1001];
	int size;
};

void MinHeapify(const Heap h, const int ind);
Heap BuildHeap(const int num);
void PrintPath(const Heap h, const int ind);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int elem_num, paths;
	scanf("%d%d", &elem_num, &paths);
	Heap h = BuildHeap(elem_num);

	for (int i=0; i!=paths; ++i) {
		int ind;
		scanf("%d", &ind);
		PrintPath(h, ind);
	}

	return 0;
}

void MinHeapify(const Heap h, const int i) {
	int minimal;
	ElementType* arr = h->Data;
	if (lchild(i) <= h->size && arr[lchild(i)] < arr[i]) {
		minimal = lchild(i);
	} else {
		minimal = i;
	}

	if (rchild(i) <= h->size && arr[rchild(i)] < arr[minimal]) {
		minimal = rchild(i);
	}

	if (minimal != i) {
		ElementType tmp = arr[minimal];
		arr[minimal] = arr[i];
		arr[i] = tmp;
		MinHeapify(h, minimal);
	}
}

Heap BuildHeap(const int num) {
	Heap h = (Heap)malloc(sizeof(struct HeapNode));
	for (int i=0; i!=num; ++i) {
		scanf("%d", &(h->Data[i + 1]));
	}
	h->size = num;

	for (int i=h->size/2; i!=0; --i) {
		MinHeapify(h, i);
	}

	for (int i=0; i!=num; ++i) {
		printf(" %d", h->Data[i + 1]);
	}putchar('\n');
	return h;
}

void PrintPath(const Heap h, const int ind) {
	bool is_first = true;
	for (int i=ind; i!=0; i/=2) {
		if (true == is_first) {
			is_first = false;
		} else {
			putchar(' ');
		}
		printf("%d", h->Data[i]);
	}
	putchar('\n');
}