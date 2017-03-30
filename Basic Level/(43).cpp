#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    string str;
    cin >> str;
    int P(0), A(0), T(0), e(0), s(0), t(0);
    for(size_t i=0; i!=str.length(); ++i){
        if( 'P' == str[i] ) ++P;
        if( 'A' == str[i] ) ++A;
        if( 'T' == str[i] ) ++T;
        if( 'e' == str[i] ) ++e;
        if( 's' == str[i] ) ++s;
        if( 't' == str[i] ) ++t;
    }
//    cout << P+A+T+e+s+t << endl;
    while( P+A+T+e+s+t > 0 ){
        if( P > 0 ) { cout << 'P'; --P; }
        if( A > 0 ) { cout << 'A'; --A; }
        if( T > 0 ) { cout << 'T'; --T; }
        if( e > 0 ) { cout << 'e'; --e; }
        if( s > 0 ) { cout << 's'; --s; }
        if( t > 0 ) { cout << 't'; --t; }
    }
    cout << endl;
    return 0;
}
