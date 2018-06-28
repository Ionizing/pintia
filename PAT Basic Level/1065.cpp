#include <iostream>
#include <iomanip>
//#include <fstream>

using namespace std;

const int MAXSIZE = 100000;

struct Couple
{
    int Cp = -1;
    int Arrive = 0;
};

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    struct Couple ID[MAXSIZE];
    int N;
    cin >> N;
    for(int i=0; i!=N; ++i){
        int tmpA, tmpB;
        cin >> tmpA >> tmpB;
        ID[tmpA].Cp = tmpB;
    }
    int M;
    cin >> M;
    int *Arrived = new int[M];
    for(int i=0; i!=M; ++i){
        cin >> Arrived[i];
        ID[ Arrived[i] ].Arrive = 1;
    }
    int cnt = M;
    for(int i=0; i!=M; ++i){
        int tmp = ID[ Arrived[i] ].Cp;
        if( -1 != tmp ){
            if( ID[tmp].Arrive == 1 ){
                ID[ tmp ].Arrive = 2;
                ID[ Arrived[i] ].Arrive = 2;
                cnt -= 2;
//                cout << "@41 " << Arrived[i] << "\t" << tmp << endl;
            }
        }
    }
    cout << cnt << endl;
    for(int i=0; i!=MAXSIZE; ++i){
        if( 1 == ID[i].Arrive ) {
            --cnt;
            if ( 0 == cnt ) cout << setfill('0') << setw(5) << i << "\n";
            else cout << setfill('0') << setw(5) << i << " ";
        }
    }
    return 0;
}
