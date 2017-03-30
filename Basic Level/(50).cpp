#include <iostream>
#include <vector>
#include <algorithm>
//#include <fstream>

using namespace std;

inline bool cmp(int a, int b)
{
    return ( a > b );
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N;
    cin >> N;
    vector<int> Fact;
    for(int i=1; i<=N; ++i){
        if( N % i == 0 ) Fact.push_back(i);
    }
    int col, row;
    if( Fact.size() % 2 == 1 ){
        col = row = Fact[ Fact.size()/2 ];
    }else{
        col = Fact[ Fact.size()/2 ];
        row = Fact[ Fact.size()/2 - 1 ];
    }
    vector< vector<int> > Arr(col);
    for(int i=0; i<col; ++i){
        Arr[i].resize(row);
    }
    vector<int> Input(N,0);
    for(int i=0; i<N; ++i){
        cin >> Input[i];
//        Input[i] = i;
    }
    sort(Input.begin(), Input.end(), cmp);
    int Cmin = 0, Cmax = col - 1;
    int Rmin = 0, Rmax = row - 1;
    int t = 0;
    while( Cmin <= Rmax and Rmin < Rmax ){
        for(int j=Rmin, i=Cmin; j<=Rmax; ++j) Arr[i][j] = Input[t++];
        for(int i=Cmin+1, j=Rmax; i<=Cmax; ++i) Arr[i][j] = Input[t++];
        for(int i=Cmax, j=Rmax-1; j>=Rmin; --j) Arr[i][j] = Input[t++];
        for(int i=Cmax-1, j=Rmin; i>=Cmin+1; --i) Arr[i][j] = Input[t++];
        ++Cmin, --Cmax;
        ++Rmin, --Rmax;
    }
//    cout << "********" << endl;
//    cout << Rmin << " " << Rmax << endl;
//    cout << Cmin << " " << Cmax << endl;
//    cout << "********" << endl;
    if( row % 2 == 1 ){
        for(int i=Cmin, j=row/2; i<=Cmax; ++i) Arr[i][j] = Input[t++];
    }

    for(int i=0; i!=col; ++i){
        for(int j=0; j!=row; ++j){
            cout << Arr[i][j];
            if( j != row - 1 ) cout << " ";
        }
        cout << endl;
    }

//    cout << col << " " << row << endl;
}
