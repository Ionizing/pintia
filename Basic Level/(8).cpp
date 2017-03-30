#include<iostream>
//#include<fstream>

using namespace std;

void ArrRev( int Arr[], const int n )
{
    int beg = 0, end = n-1;
    while( beg < end ){
        Arr[beg] ^= Arr[end];
        Arr[end] ^= Arr[beg];
        Arr[beg] ^= Arr[end];
        ++beg; --end;
    }
}

void ArrShift( int Arr[], const int n, const int Length )
{
    ArrRev( Arr, Length-n );
    ArrRev( Arr+Length-n, n );
    ArrRev( Arr, Length );
}

int main()
{
//    ifstream in( "in.txt" );
//    cin.rdbuf( in.rdbuf() );
    int Length, Shift;
    cin >> Length >> Shift;
    Shift %= Length;
    int *Arr = new int[Length];
    for(int i=0; i<Length; ++i){
        cin >> Arr[i];
    }
    ArrShift(Arr, Shift, Length);
    for(int i=0; i<Length-1; ++i){
        cout << Arr[i] << " ";
    }cout << Arr[Length-1] << endl;
    return 0;
}
