#include <iostream>
#include <queue>
#include <vector>
#include <set>
//#include <fstream>

using std::cin;
using std::cout;
using std::endl;

typedef struct Node* PtrtoNode;
typedef PtrtoNode* Graph;

struct Node
{
	int ID = -1;
	PtrtoNode next = nullptr;
};

void InsertEdge( const Graph G, const int src, const int des );
int is_linked( const Graph G, const int N );
std::vector<int> BFS( const Graph G, const int &N, const int &root,
		bool *visited , const bool &clrtmp );

int main()
{
//	std::ifstream cin("in.txt");
	int N;
	cin >> N;
	Graph G = new PtrtoNode[N];
	for(int i=0; i!=N; ++i){
		G[i] = nullptr;
	}

	for(int i=0; i!=N-1; ++i){
		int src, des;
		cin >> src >> des;
		--src, --des;
		InsertEdge( G, src, des );
	}

	int components = is_linked(G, N);
	if( 1 != components ){
        cout << "Error: " << components << " components" << endl;
        return 0;
    }

    bool *visited = new bool[N];
	int max_level = 0;
	std::vector<int> node_level = BFS(G, N, 0, visited, true);
	for(int i=0; i!=N; ++i){
		max_level = ( max_level > node_level[i] ) ? max_level : node_level[i];
	}
	std::set<int> far_nodes;
	for(int i=0; i!=N; ++i){
		if( max_level == node_level[i] ){
			far_nodes.insert(i);
		}
	}
	if( far_nodes.empty() ){
		cout << "No farthest nodes." << endl;
		return 0;
	}
	auto tmp = far_nodes.begin();
	int root = *tmp;
	node_level = BFS(G, N, root, visited, true);

	max_level = 0;
	for(int i=0; i!=N; ++i){
		max_level = ( max_level > node_level[i] ) ? max_level : node_level[i];
	}
	for(int i=0; i!=N; ++i){
		if( max_level == node_level[i] ){
			far_nodes.insert(i);
		}
	}

	for( auto i : far_nodes ){
		cout << i + 1 << endl;
	}

	delete[] visited;
	return 0;
}

void InsertEdge( const Graph G, const int src, const int des )
{
	PtrtoNode p = G[src];
	PtrtoNode tmp = new Node;
	tmp->ID = des;
	tmp->next = p;
	G[src] = tmp;
//	cout << "@91 " << p << " " << src << " " << des << endl;
	p = G[des];
	tmp = new Node;
	tmp->ID = src;
	tmp->next = p;
	G[des] = tmp;

	return;
}

int is_linked( const Graph G, const int N )
{
	bool *visited = new bool[N];
	for(int i=0; i!=N; ++i){
		visited[i] = false;
	}
	int cnt = 0;
	for(int i=0; i!=N; ++i){
		if( !visited[i] ){
			BFS( G, N, i, visited, false );
			++cnt;
		}
	}
	delete[] visited;

	return cnt;
}

std::vector<int> BFS( const Graph G, const int &N, const int &root,
		bool *visited , const bool &clrtmp )
{	// This function returns a list contains the depths of each node
	if( clrtmp ){
		for(int i=0; i!=N; ++i){
			visited[i] = false;
		}
	}

	std::queue<int> Q;
	visited[root] = true;
	Q.push(root);
	std::vector<int> node_level(N, 0);
	node_level[root] = 1;

	while( !Q.empty() ){
		int current = Q.front();
		Q.pop();
		PtrtoNode p = G[current];

		while( nullptr != p ){
			if( !visited[p->ID] ){
				visited[p->ID] = true;
				Q.push( p->ID );
				node_level[p->ID] = node_level[current] + 1;
//                cout << "@140 " << p->ID << endl;
			}
			p = p->next;
		}
	}
	return node_level;
}
