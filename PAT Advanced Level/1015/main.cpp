#include <iostream>
#include <cmath>
//#include <fstream>

using namespace std;

bool IsPrime( const int &n );
int Convert( int n, const int &Radix );

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N, D;
    cin >> N >> D;
    while( N >= 0 ){
        if( IsPrime(N) and IsPrime( Convert(N, D) ) )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cin >> N >> D;
    }
    return 0;
}

bool IsPrime( const int &n )
{
    if( n < 2 ) return false;
    if( 2 == n or 3 == n ) return true;
    if( n % 2 == 0 ) return false;
    int i = 3;
    double k = sqrt(n);
    for(; i<=k; ++i){
        if( n % i == 0 ) break;
    }
    if( i > k ) return true;
    else return false;
}

int Convert( int n, const int &Radix )
{
    int Res(0);
    while( n != 0 ){
        int tmp = n % Radix;
        Res = Res*Radix + tmp;
        n /= Radix;
    }
    return Res;
}
