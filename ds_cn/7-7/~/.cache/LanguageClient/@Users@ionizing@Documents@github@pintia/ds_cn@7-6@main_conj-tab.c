#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 10
typedef enum {false, true} bool;

typedef struct AdjVNode* PtrToVNode;
struct AdjVNode {
	int AdjV;
	PtrToVNode AdjVNext;
};

typedef struct VNode* Graph;
struct VNode {
	int nVertex;
	int nEdges;
	PtrToVNode Head[MAX_VERTEX_NUM];
	bool visited[MAX_VERTEX_NUM];
};

void InsertGraph(const Graph, const int src, const int des);
PtrToVNode _insert_edge(const PtrToVNode pCurr, const int des);
Graph BuildGraph(const int nVertex, const int nEdges, FILE* fp);
void DFS(const Graph G, const int Vertex);
void BFS(const Graph G, const int Vertex);
void PrintGraph(const Graph G);

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	int nVertex, nEdges;
	scanf("%d%d", &nVertex, &nEdges);
	Graph G = BuildGraph(nVertex, nEdges, stdin);
	// PrintGraph(G);
	for (int i=0; i!=nVertex; ++i) {
		// printf(" @38 G->visited[] state: ");
		// for (int i=0; i!=nVertex; ++i) {
		// 	printf(" %d", G->visited[i]);
		// } puts("");

		if (false == G->visited[i]) {
			putchar('{');
			DFS(G, i);
			puts(" }");
		}
	}

	for (int i=0; i!=nVertex; ++i) {
		G->visited[i] = false;
	}
	for (int i=0; i!=nVertex; ++i) {
		// printf(" @38 G->visited[] state: ");
		// for (int i=0; i!=nVertex; ++i) {
		// 	printf(" %d", G->visited[i]);
		// } puts("");

		if (false == G->visited[i]) {
			putchar('{');
			BFS(G, i);
			puts(" }");
		}
	}

	return 0;
}

void InsertGraph(const Graph G, const int src, const int des) {
	 ++(G->nEdges);
	 G->Head[src] = _insert_edge(G->Head[src], des);
	 G->Head[des] = _insert_edge(G->Head[des], src);
}

PtrToVNode _insert_edge(const PtrToVNode pCurr, const int des) {
	if (NULL == pCurr) {
		PtrToVNode res = (PtrToVNode)malloc(sizeof(struct AdjVNode));
		res->AdjV = des;
		res->AdjVNext = NULL;
		return res;
	} else if (des < pCurr->AdjV) {
		PtrToVNode res = (PtrToVNode)malloc(sizeof(struct AdjVNode));
		res->AdjV = des;
		res->AdjVNext = pCurr;
		return res;
	} else if (des == pCurr->AdjV) {
		return pCurr;
	} else {
		pCurr->AdjVNext = _insert_edge(pCurr->AdjVNext, des);
		return pCurr;
	}
}

Graph BuildGraph(const int nVertex, const int nEdges, FILE* fp) {
	Graph G = (Graph)malloc(sizeof(struct VNode));
	for (int i=0; i!=nVertex; ++i) {
		G->Head[i] = NULL;
	}
	G->nVertex = nVertex;
	G->nEdges = 0;
	
	int src, des;
	for (int i=0; i!=nEdges; ++i) {
		fscanf(fp, "%d%d", &src, &des);
		// printf(" @BuildGraph ");
		InsertGraph(G, src, des);
		// printf("Edge %d - %d inserted\n", src, des);
	}

	for (int i=0; i!=nVertex; ++i) {
		G->visited[i] = false;
	}
	return G;
}

void DFS(const Graph G, const int Vertex) {
	// printf(" @DFS visited[] state: ");
	// for (int i=0; i!=G->nVertex; ++i) {
	// 	printf("%d", G->visited[i]);
	// } puts("");

	if (true == G->visited[Vertex]) {
		return;
	}
	PtrToVNode p = G->Head[Vertex];
	G->visited[Vertex] = true;
	printf(" %d", Vertex);
	while (NULL != p) {
		if (false == G->visited[p->AdjV]) {
			DFS(G, p->AdjV);
		}
		p = p->AdjVNext;
	}
}

void PrintGraph(const Graph G) {
	puts("Graph is :");

	PtrToVNode p;
	for (int i=0; i!=G->nVertex; ++i) {
		printf("Node %d:", i);
		p = G->Head[i];
		while (NULL != p) {
			printf(" %d", p->AdjV);
			p = p->AdjVNext;
		} puts("");
	}
	puts("    End of graph");
}

void BFS(const Graph G, const int Vertex) {
	if (true == G->visited[Vertex]) {
		return;
	}

	int queue[1000];
	int head, tail;
	head = tail = 0;

	queue[tail++] = Vertex;
	int VCurr;
	PtrToVNode p;
	while (head != tail) {
		VCurr = queue[head++];
		printf(" %d", VCurr);
		G->visited[VCurr] = true;

		p = G->Head[VCurr];
		while (NULL != p) {
			if (false == G->visited[p->AdjV]) {
				queue[tail++] = p->AdjV;
				G->visited[p->AdjV] = true;
			}
			p = p->AdjVNext;
		}
	}
}