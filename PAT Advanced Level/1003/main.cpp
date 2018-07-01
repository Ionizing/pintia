#include <iostream>
//#include <fstream>

const int INF = 0x7FFFFFFF;
const int MAXSIZE = 500;

using std::cin;
using std::cout;
using std::endl;

void Dijkstra( int** G, const int Teams[], const int &Start,
              const int &Destination, const int &N );
int FindMin( const int dist[], const bool collected[], const int &Size );

int main()
{
//    std::ifstream cin("in.txt");
    int N, M, Start, Destination;
    cin >> N >> M >> Start >> Destination;
    int **G = new int*[N];
    for(int i=0; i!=N; ++i){
        G[i] = new int[MAXSIZE];    // Initialize Graph
        for(int j=0; j!=N; ++j){
            G[i][j] = INF;
        }
    }

    int *Teams = new int[N];        // Initialize Weight Array
    for(int i=0; i!=N; ++i){        // Input Weight Data
        cin >> Teams[i];
    }

    for(int i=0; i!=M; ++i){        // Input map data
        int src, des, len;
        cin >> src >> des >> len;
        G[src][des] = len;
        G[des][src] = len;
    }

//    for(int i=0; i!=N; ++i){
//        for(int j=0; j!=N; ++j){
//            cout << G[i][j] << '\t';
//        }
//        cout << endl;
//    }

    Dijkstra( G, Teams, Start, Destination, N );

    delete[] Teams;                 // Recycle the trash
    for(int i=0; i!=N; ++i){
        delete[] G[i];
    }
    delete[] G;
    return 0;
}

void Dijkstra( int **G, const int Teams[], const int &Start,
              const int &Destination, const int &N )
{
//    cout << G[0][1] << " " << G[0][2] << " " << G[0][3] << " "
//        << G[1][2] << " " << G[2][4] << " " << G[3][4] << endl;
    bool collected[MAXSIZE];                // Flag to show whether current node was collected
    int num_of_paths[MAXSIZE];              // Number of paths to reach current node
    int dist[MAXSIZE];                      // Distance to Start
    int coll_teams[MAXSIZE];                // Collected teams to current node

    for(int i=0; i!=N; ++i){                // Initialization
        dist[i] = G[Start][i];
        coll_teams[i] = Teams[i];
        if( G[Start][i] != INF ){
            coll_teams[i] += Teams[Start];
        }
        num_of_paths[i] = 1;
        collected[i] = false;
    }

    coll_teams[Start] = Teams[Start];
    dist[Start] = 0;                        // Start -> Start takes no length
    collected[Start] = true;                // Start node processed
//    int cnt = 0;
    while( true ){
        int Current = FindMin(dist, collected, N);
        if( -1 == Current ){
            break;                          // Search process Over
        }
        collected[Current] = true;
//        cout << "@87 " << Current << endl;
        for(int i=0; i!=N; ++i){
            if( !collected[i] and G[Current][i] != INF ){
                if( G[Current][i] < 0 ){
                    cout << "Negative distance." << endl;
                    return;
                }
                if( dist[Current] + G[Current][i] < dist[i] ){
//                    cout << "@94" << (++cnt) << endl;
                    dist[i] = dist[Current] + G[Current][i];
                    num_of_paths[i] = num_of_paths[Current];
                    coll_teams[i] = coll_teams[Current] + Teams[i];
                }else if ( dist[Current] + G[Current][i] == dist[i] ){
                    num_of_paths[i] += num_of_paths[Current];
//                    cout << "@98" << (++cnt) << endl;
                    if( coll_teams[i] < coll_teams[Current] + Teams[i] ){
                        coll_teams[i] = coll_teams[Current] + Teams[i];
                    }
                }
            }
        } // end for
    } // end while
    cout << num_of_paths[Destination] << " " << coll_teams[Destination]
        << endl;
}

int FindMin( const int dist[], const bool collected[], const int &Size )
{
    int min_index = -1;
    int min_dist = INF;
    for(int i=0; i!=Size; ++i){
        if( !collected[i] and min_dist > dist[i] ){
            min_dist = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
