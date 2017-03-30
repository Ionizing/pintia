#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    size_t N;
    cin >> N;
    vector<int> Arr(N);
    vector<int> Tmp(N, 0);
    for(size_t i=0; i!=N; ++i){
        cin >> Arr[i];
    }
    int Max = Arr[0];
    for(size_t i=0; i!=N; ++i){
        if( Max <= Arr[i] ){
            Max = Arr[i];
            ++Tmp[i];
        }
    }
    int Min = Arr[N-1];
    for(size_t i=N-1; i!=-1; --i){
        if( Min >= Arr[i] ){
            Min = Arr[i];
            ++Tmp[i];
        }
    }
    vector<int> Res;
    for(size_t i=0; i!=N; ++i){
        if( 2 == Tmp[i] ){
            Res.push_back( Arr[i] );
        }
    }
    cout << Res.size() << endl;
    if( 0 == Res.size() ) { cout << endl; return 0; }
    for(size_t i=0; i!=Res.size(); ++i){
        if( i!= Res.size()-1 ) cout << Res[i] << " ";
        else cout << Res[i] << endl;
    }
    return 0;
}
