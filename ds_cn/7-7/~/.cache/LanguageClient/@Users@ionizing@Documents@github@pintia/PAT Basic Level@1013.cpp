#include <iostream>
#include <cmath>
//#include <fstream>

using namespace std;

bool IsPrime( const int n )
{
    if ( n == 2 ) return true;
    if ( n%2 == 0 ) return false;
    int i;
    for(i=3; i<=sqrt(n); i+=2){
        if ( n%i == 0 ) break;
    }
    if ( i > sqrt(n) ) return true;
    else return false;
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf(in.rdbuf());
    int M,N;
    cin >> M >> N;
    int PrimeIndex = 0;
    int cursor;
    int interval_length = N-M;
    int i;
    for(i=2; PrimeIndex<=10000; ++i){
        if( !IsPrime(i) ) continue;
        else{
            ++PrimeIndex;
            cursor = PrimeIndex - M;
            if( cursor<0 ) continue;
            else if ( cursor >= interval_length ) break;
            if( (cursor+1) % 10 == 0) cout << i << endl;
            else cout << i << " ";
        }
    }
//    if( (cursor+1) % 10 == 0 ) cout << i<< endl;
//    else cout << i << endl;
    cout << i << endl;
    return 0;
}
