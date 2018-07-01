#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
typedef struct GraphMatrix* Graph;
struct GraphMatrix {
	bool Data[10][10];
	int nVertex;
	int nEdge;
};

Graph BuildGraph(const int nVertex, const int nEdge, FILE* fp);
void DFS(const Graph G, const int Vertex, bool visited[]);
void BFS(const Graph G, const int Vertex, bool visited[]);
void PrintGraph(const Graph G);

int main () {
freopen("in.txt", "r", stdin);

	int nVertex, nEdge;
	scanf("%d%d", &nVertex, &nEdge);

	Graph G = BuildGraph(nVertex, nEdge, stdin);
	// PrintGraph(G);

	bool visited[10];
	for (int i=0; i!=nVertex; ++i) {
		visited[i] = false;
	}

	for (int i=0; i!=nVertex; ++i) {
		if (false == visited[i]) {
			putchar('{');
			DFS(G, i, visited);
			puts(" }");
		}
	}

	for (int i=0; i!=nVertex; ++i) {
		visited[i] = false;
	}
	for (int i=0; i!=nVertex; ++i) {
		if (false == visited[i]) {
			putchar('{');
			BFS(G, i, visited);
			puts(" }");
		}
	}

	return 0;
}

Graph BuildGraph(const int nVertex, const int nEdge, FILE* fp) {
	Graph G = (Graph)malloc(sizeof(struct GraphMatrix));
	G->nVertex = nVertex;
	G->nEdge = nEdge;

	/* Initialize GraphMatrix */
	for (int i=0; i!=nVertex; ++i) {
		for (int j=0; j!=nVertex; ++j) {
			G->Data[i][j] = false;
		}
	}

	int src, des;
	for (int i=0; i!=nEdge; ++i) {
		fscanf(fp, "%d%d", &src, &des);
		if (src >= nVertex || des >= nVertex 
				|| src < 0 || des < 0) {
			puts(" @BuildGraph() Index access outrange");
			exit(EXIT_FAILURE);
		}

		G->Data[src][des] = true;
		G->Data[des][src] = true;
	}

	return G;
}

void DFS(const Graph G, const int Vertex, bool visited[]) {
	if (Vertex >= G->nVertex) {
		puts(" @DFS() Index access outrange");
		exit(EXIT_FAILURE);
	}

	if (false == visited[Vertex]) {
		visited[Vertex] = true;
		printf(" %d", Vertex);
		for (int i=0; i!=G->nVertex; ++i) {
			if (true == G->Data[Vertex][i] && false == visited[i]) {
				DFS(G, i, visited);
			}
		}
	}
}

void BFS(const Graph G, const int Vertex, bool visited[]) {
	int queue[100];
	int head = 0, tail = 0;

	if (false == visited[Vertex]) {
		queue[tail++] = Vertex;
	}

	int curr;
	while (head != tail) {
		curr = queue[head++];
		printf(" %d", curr);
		visited[curr] = true;
		for (int i=0; i!=G->nVertex; ++i) {
			if (true == G->Data[curr][i] && false == visited[i]) {
				queue[tail++] = i;
				visited[i] = true;
			}
		}

		// printf(" @BFS() queue state: ");
		// for (int i=head; i!=tail; ++i) {
		// 	printf(" %d", queue[i]);
		// }puts("");
	}
}

void PrintGraph(const Graph G) {
	puts("Graph G is ");
	for (int i=0; i!=G->nVertex; ++i) {
		for (int j=0; j!=G->nVertex; ++j) {
			printf(" %d", G->Data[i][j]);
		}puts("");
	}
}