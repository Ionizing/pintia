#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

const int INF = 0x6fffff;

using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef vector<vector<int> > MGraph;

void Dijkstra( const MGraph &graph, const int &Destination,
              const vector<int> &bikes_per_stat);
int Find_min( const vector<int> dist, const vector<bool> collected );

int main()
{
#ifndef ONLINE_JUDGE
   std::ifstream cin("in.txt");
#endif
    int Max_cap, Total_stat, Pro_stat, Edges;
    cin >> Max_cap >> Total_stat >> Pro_stat >> Edges;
    vector<int> bikes_per_stat(Total_stat + 1, 0);
    for(int i=1; i!=Total_stat+1; ++i){
        int tmp;
        cin >> tmp;
        bikes_per_stat[i] = tmp - Max_cap/2;
    }

//    cout << "@31";
//    for(int i=1; i!=Total_stat+1; ++i){
//        cout << " " << bikes_per_stat[i];
//    }cout << endl;


    MGraph graph(Total_stat + 1);
    for(int i=0; i!=Total_stat+1; ++i){
        graph[i].resize(Total_stat+1, INF);
    }

    for(int i=0; i!=Edges; ++i){
        int src, des, len;
        cin >> src >> des >> len;
        graph[src][des] = len;
        graph[des][src] = len;
    }
    Dijkstra( graph, Pro_stat, bikes_per_stat);
    return 0;
}

void Dijkstra( const MGraph &graph, const int &Destination,
              const vector<int> &bikes_per_stat)
{
    const int start = 0;
    const int Size = graph.size();
    vector<bool> collected(Size, false);
    vector<int> path(Size, -1);
    vector<int> dist(Size);
    vector<int> bikes_on_the_way(Size, 0);

    for(int i=0; i!=Size; ++i){
        dist[i] = graph[start][i];
        bikes_on_the_way[i] = bikes_per_stat[i];
        if( INF != graph[start][i] ){
            path[i] = start;
            bikes_on_the_way[i] += bikes_on_the_way[start];
        }
    }

    collected[start] = true;
    dist[start] = 0;

    while( true ){
        int current = Find_min(dist, collected);
        if( -1 == current ){
            break;
        }
        collected[current] = true;

//        cout << "@74";
//        for(int i=0; i!=Size; ++i){
//            cout << " " << bikes_on_the_way[i];
//        }   cout <<endl;

        for(int i=0; i!=Size; ++i){
            if( !collected[i] and INF != graph[current][i] ){
                if( graph[current][i] < 0 ){
                    std::cerr << "Negative distance." << endl;
                    return;
                }
                if( dist[current] + graph[current][i] < dist[i] ){
                    dist[i] = dist[current] + graph[current][i];
                    path[i] = current;
                    bikes_on_the_way[i] = bikes_per_stat[i]
                        + bikes_on_the_way[current];
                } else if( dist[current] + graph[current][i] == dist[i] ) {
                    dist[i] = dist[current] + graph[current][i];
                    if( bikes_on_the_way[current] + bikes_per_stat[i]
                       > bikes_on_the_way[i] ){
                        path[i] = current;
                        bikes_on_the_way[i] = bikes_on_the_way[current]
                            + bikes_per_stat[i];
                    }
                }
            }
        }/// end for
    }/// end while

    std::stack<int> S;
    int tmp = Destination;
    while( -1 != tmp ){
        S.push(tmp);
        tmp = path[tmp];
    }

    tmp = -bikes_on_the_way[Destination];
    /// tmp stores the remain bikes when travel to destination
    /// without taking bikes from PBMC
    if( tmp <= 0 ){
        cout << 0 << " ";
    }else{
        cout << tmp << " ";
    }
    cout << S.top();
    S.pop();
    while( !S.empty() ){
        cout << "->" << S.top();
        S.pop();
    }
    if( tmp >= 0 ){
        cout << " " << 0 << endl;
    } else {
        cout << " " << -tmp << endl;
    }
}

int Find_min( const vector<int> dist, const vector<bool> collected )
{
    const int Size = dist.size();
    int min_ind = -1;
    int min_dist = INF;
    for(int i=0; i!=Size; ++i){
        if( !collected[i] and dist[i] < min_dist ){
            min_dist = dist[i];
            min_ind = i;
        }
    }
    return min_ind;
}