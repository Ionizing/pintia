#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

char Capitalize( const char C )
{
    if( C >= 'a' and C <= 'z' ){
        return ( C - 'a' + 'A' );
    }
    else return C;
}

char unCapitalize( const char C )
{
    if( C >= 'A' and C <= 'Z' ){
        return ( C - 'A' + 'a' );
    }
    else return C;
}

bool Type( const string invalid, const char C )
{
    for( char i : invalid ){
        if( C != unCapitalize(C) and i == '+' ) return false;
        else if ( i == Capitalize(C) ) return false;
    }
    return true;
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    string invalid, input;
//    cin >> invalid >> input;
    getline(cin,invalid);
    cin >> input;
    for( auto i : input ){
        if( Type(invalid,i) ) cout << i;
    }
    cout << endl;
    return 0;
}
