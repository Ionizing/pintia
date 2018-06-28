#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

int Convert( const char C )
{
    if( C <= '9' and C >= '0' ) return ( C - '0' );
    else if ( C <= 'z' and C >= 'a' ) return ( C - 'a' + 10 );
    else return ( C - 'A' + 36 );
}

char Revert( const int i )
{
    if ( i >= 0 and i <= 9 ) return ( i + '0' );
    else if ( i >= 10 and i <= 35 ) return ( i - 10 + 'a' );
    else return ( i - 36 + 'A' );
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    string S1, S2;
    cin >> S1 >> S2;
    int Perl[10 + 26*2] = {0};
    for(size_t i=0; i!=S1.size(); ++i){
        ++Perl[ Convert( S1[i] ) ];
    }
    for(size_t i=0; i!=S2.size(); ++i){
        --Perl[ Convert( S2[i] ) ];
    }
    int sumPlus = 0, sumMinus = 0;
    for(int i=0; i!=62; ++i){
        if( Perl[i] > 0 ) sumPlus += Perl[i];
        if( Perl[i] < 0 ) sumMinus -= Perl[i];
    }
    if( sumMinus != 0 ){
        cout << "No " << sumMinus << endl;
    }else{
        cout << "Yes " << sumPlus << endl;
    }
//    for(int i=0; i!=62; ++i){
//        cout << Revert(i) << " " << Perl[i] << endl;
//    }
    return 0;
}
