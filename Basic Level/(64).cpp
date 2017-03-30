#include <iostream>
#include <string>
#include <algorithm>
//#include <fstream>

using namespace std;

int FriendID( const string str )
{
    int len = str.length();
    int sum = 0;
    for(int i=0; i!=len; ++i){
        sum += str[i] - '0';
    }
    return sum;
}

bool IsUnique( const int num, int Arr[], const int Size )
{
    for(int i=0; i!=Size; ++i){
        if( num == Arr[i] ) return false;
    }
    return true;
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N;
    cin >> N;
    int Size(0);
    int *Arr = new int[N];
    for(int i=0; i!=N; ++i){
        string tmp;
        cin >> tmp;
        int id = FriendID( tmp );
        if( IsUnique(id, Arr, Size) ){
            Arr[Size++] = id;
        }
    }
    cout << Size << endl;
    sort(Arr, Arr+Size);
    for(int i=0; i!=Size; ++i){
        if( i != Size-1 ) cout << Arr[i] << " ";
        else cout << Arr[i] << endl;
    }
    return 0;
}
