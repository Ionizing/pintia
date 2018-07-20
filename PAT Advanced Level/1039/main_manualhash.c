#include <stdio.h>
#include <stdlib.h>

#define _MAX_STUDENTS 26 * 26 * 26 * 10
#define _STR_LENGTH 5
#define _HASH(x) int(\
	(x[0] - 'A') * 26 * 26 * 10 + \
	(x[1] - 'A') * 26 * 10 + \
	(x[2] - 'A') * 10 + \
	(x[3] - '0')\
)

typedef struct Node* PtrToNode;
struct Node {
	int CourInd;
	PtrToNode Next;
};

typedef struct HeadNode* PtrToHead;
struct HeadNode {
	int size;
	PtrToNode Next;
};

void InsertHead(PtrToHead H, const int val);
PtrToNode _insert(PtrToNode p, const int val);
void Print(PtrToHead H);


struct HeadNode H[_MAX_STUDENTS];
char tmpStr[_STR_LENGTH];


int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int i=0; i!=_MAX_STUDENTS; ++i) {
		H[i].size = 0;
	}

	// char str[] = "AAA2";
	// printf("%d\n", _HASH(str));
	// for (int i=200; i!=0; --i) {
	// 	InsertHead(H + _HASH(str), i);
	// }
	// Print(H + _HASH(str));

	int nStu, nCour;
	scanf("%d%d", &nStu, &nCour);

	int courind, num/*, stuind*/;
	for (int i=0; i!=nCour; ++i) {
		scanf("%d%d", &courind, &num);
		for (int j=0; j!=num; ++j) {
			scanf("%s", tmpStr);
			// printf("\t\t @57 %d\n", _HASH(tmpStr));
			InsertHead(&H[_HASH(tmpStr)], courind);
		}
	}

	for (int i=0; i!=nStu; ++i) {
		scanf("%s", tmpStr);
		printf("%s %d", tmpStr, H[_HASH(tmpStr)].size);
		Print(H + _HASH(tmpStr));
	}
	return 0;
}

void InsertHead(PtrToHead H, const int val) {
	H->Next = _insert(H->Next, val);
	++(H->size);
}

PtrToNode _insert(PtrToNode p, const int val) {
	if (NULL == p) {
		p = (PtrToNode)malloc(sizeof(struct Node));
		p->Next = NULL;
		p->CourInd = val;
		return p; 
	} else if (val > p->CourInd) {
		p->Next = _insert(p->Next, val);
		return p;
	} else {
		PtrToNode tmp = (PtrToNode)malloc(sizeof(struct Node));
		tmp->CourInd = val;
		tmp->Next = p;
		return tmp;
	}
}

void Print(PtrToHead H) {
	PtrToNode p = H->Next;
	for (int i=0; i!=H->size; ++i) {
		printf(" %d", p->CourInd);
		p = p->Next;
	}
	puts("");
}