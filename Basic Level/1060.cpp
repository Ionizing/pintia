#include <iostream>
#include <algorithm>
//#include <fstream>

using namespace std;

inline bool cmp( const int A, const int B )
{
    return ( A > B );
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n;
    cin >> n;
    int *Arr = new int[n];
    for(int i=0; i!=n; ++i){
        cin >> Arr[i];
    }
    sort(Arr, Arr+n, cmp);
//    for(int i=0; i!=n; ++i){
//        cout << Arr[i] << " ";
//    }
    int cnt = 0;
    for(int i=0; i<n; ++i){
        if( Arr[i] > i+1 ){
            ++cnt;
        }else break;
    }
    cout << cnt;
    return 0;
}
