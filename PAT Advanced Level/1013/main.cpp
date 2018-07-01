#include <iostream>
#include <vector>
//#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef vector<vector<bool> > Graph;

void DFS(const Graph &G, vector<bool> &visited,
         const int start);

int main()
{
//    std::ifstream cin("in.txt");
    int N, M, L;
    cin >> N >> M >> L;

    Graph G(N);
    for(int i=0; i!=N; ++i){
        G[i].resize(N,false);
    }
    for(int i=0; i!=M; ++i){
        int src, des;
        cin >> src >> des;
        --src; --des;
        G[src][des] = true;
        G[des][src] = true;
    }
    for(int i=0; i!=L; ++i){
        int cnt = 0;
        vector<bool> visited(N,false);
        int tmp;
        cin >> tmp;
        --tmp;
        visited[tmp] = true;
//        for(int i=0; i!=N; ++i){
//            cout << visited[i] << "\t";
//        }cout << endl;

        for(int j=0; j!=N; ++j){
            if( !visited[j] ){
                DFS(G, visited, j);
                ++cnt;
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}

void DFS(const Graph &G, vector<bool> &visited,
         const int start)
{
    visited[start] = true;
    const int N = G.size();
    for(int i=0; i!=N; ++i){
        if( !visited[i] and true == G[i][start] ){
            DFS(G, visited, i);
        }
    }
}
