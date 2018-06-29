#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
// typedef enum {false, true} bool;
typedef struct LNode* PtrToNode;
struct LNode {
	int Coefficient;
	int Index;
	PtrToNode Next;
};
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty();
List ReadList(List L);
void PrintList(List L);
List Add(List a, List b);
List Mul(List a, List b);
bool Insert(List L, Position Pos, const int Coeff, const int Index);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	List L1, L2;
	L1 = ReadList(MakeEmpty());
	L2 = ReadList(MakeEmpty());

	// PrintList(L1);
	// PrintList(L2);

	// puts("L1 + L2 = ");
	PrintList(Mul(L1, L2));
	PrintList(Add(L1, L2));
	return 0;
}

List MakeEmpty() {
	List L = (List)malloc(sizeof(struct LNode));
	L->Coefficient = L->Index = 0;
	L->Next = NULL;
	return L;
}

List ReadList(List L) {
	PtrToNode p = L;
	int N, coeff, ind;
	scanf("%d", &N);
	for(int i=0; i!=N; ++i) {
		scanf("%d%d", &coeff, &ind);
		p->Next = (PtrToNode)malloc(sizeof(struct LNode));
		p->Next->Next = NULL;
		p->Next->Coefficient = coeff;
		p->Next->Index = ind;
		p = p->Next;
	}
	return L;
}

void PrintList(List L) {
	if (NULL == L) {
		puts("\t@49 NULL == L, in void PrintList(List L)");
	}

	bool is_head = true;;
	/*	Empty Polynomial  */
	if (NULL == L->Next || L->Next->Coefficient == 0) {
		puts("0 0");
		return;
	}

	PtrToNode p = L->Next;
	while (NULL != p) {
		if (0 != p->Coefficient) {
			if (false == is_head) {
				putchar(' ');
			}
			printf("%d %d", p->Coefficient, p->Index);
			is_head = false;
		}
		p = p->Next;
	}
	putchar('\n');

	return;
}

bool Insert(List L, Position Pos, const int Coeff, const int Index) {
	PtrToNode p;
	for(p = L; NULL != p; p = p->Next) {
		if (p->Next == Pos) {
			PtrToNode tmp = p->Next;
			p->Next = (PtrToNode)malloc(sizeof(struct LNode));
			p->Next->Coefficient = Coeff;
			p->Next->Index = Index;
			p->Next->Next = tmp;
			return true;
		}
	}
	return false;
}

List Add(List a, List b) { /* Add b to a, b would be destroyed */
	if (NULL == a || NULL == b) {
		puts("\t@154, a or b is NULL, in List Add(List a, List b)");
	}

	List pa, pb;
	pa = a;
	pb = b->Next;

	PtrToNode paNext, pbNext;
	while (NULL != pa->Next && NULL != pb) {
		pbNext = pb->Next;
		if (pb->Index > pa->Next->Index) {
			/* insert pb to current pa */
			paNext = pa->Next;
			pa->Next = pb;
			pb->Next = paNext;
			pb = pbNext;
		} else if (pb->Index == pa->Next->Index) {
			/* "Merge" term to pa */
			pa->Next->Coefficient += pb->Coefficient;
			pb = pb->Next;			
		} else {
			pa = pa->Next;
		}
	}

	if (NULL == pa->Next && a == pa) {
		/* a is an empty nomial */
		return b;
	} else if (NULL == pa->Next) {
		/* pa is the tail of a */
		pa->Next = pb;
	}
	return a;
}

List Mul(List a, List b) {
	List l[1000];

	int i = 0;
	for (PtrToNode pa=a->Next; NULL != pa; pa=pa->Next) {
		l[i] = MakeEmpty();
		PtrToNode tmpA = l[i];
		for(PtrToNode pb=b->Next; NULL != pb; pb=pb->Next) {
			PtrToNode tmpB = MakeEmpty();
			tmpB->Coefficient = pa->Coefficient * pb->Coefficient;
			tmpB->Index = pa->Index + pb->Index;
			tmpA->Next = tmpB;
			tmpA = tmpA->Next;
		}
		++i;
	}

	List res = MakeEmpty();
	for (int j=0; j!=i; ++j) {
		res = Add(res, l[j]);
	}

	return res;
}