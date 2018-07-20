#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

const int INF = (1 << 30) - 1;

using std::vector;

struct Vertex {
	int index;
	int bikes_origin;
	int bikes_add;
	int bikes_sub;
	Vertex(const int &a, const int &b) : 
		index(a), bikes_origin(b), bikes_add(0), bikes_sub(0) {};
	bool operator<(const Vertex &a) const {return this->bikes_origin < a.bikes_origin;};
	bool operator>(const Vertex &a) const {return this->bikes_origin < a.bikes_origin;};
};

using MGraph = vector<vector<int>>;
using min_heap = std::priority_queue<Vertex, vector<Vertex>, std::greater<Vertex>>;

vector<Vertex> V;
MGraph G;

void Dijkstra(const MGraph& G, const int& Destination,
	const vector<Vertex>& V);
void DFS();

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::cin.rdbuf(in.rdbuf());
#endif

	int Max_capacity, Total_station, Problem_station, Edges;
	std::cin >> Max_capacity >> Total_station >> Problem_station >> Edges;
	V.resize(Total_station + 1, Vertex(0, -1, 0, 0));
	G.resize(Total_station + 1, vector<int>(Total_station + 1, INF));


// 输入节点信息，包括节点拥有的自行车数，初始化节点借出、借入的自行车数为 0；
	for (int i=1; i!=Total_station + 1; ++i) {
		int tmp;
		std::cin >> tmp;
		V[i] = Vertex(i, tmp, 0, 0);
	}

// 输入图的 Edges;
	for (int i=0; i!=Edges; ++i) {
		int src, des, len;
		std::cin >> src >> des >> len;
		G[src][des] = len;
		G[des][src] = len;
	}

	Dijkstra(G, Problem_station, V);

	return 0;
}

void Dijkstra(const MGraph& G, const int& Destination,
	const vector<Vertex>& V) {
	const int start = 0;
	const int Size = G.size();
	vector<bool> collected(Size, false);
	vector<int> 
}