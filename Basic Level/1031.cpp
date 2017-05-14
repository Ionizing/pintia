#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

bool fun( const string str );
inline bool IsDigit( const char C );

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n;
    cin >> n;
    int numpassed = 0;
    for(int i=0; i!=n; ++i){
        string tmp;
        cin >> tmp;
        if( fun(tmp) ) ++numpassed;
    }
    if( numpassed == n ) cout << "All passed" << endl;
    return 0;
}

bool fun( const string str )
{
    int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char M[] = {'1','0','X','9','8','7','6','5','4','3','2'};
    char Last = str.back();
    int Z = 0;
    for(size_t i=0; i!=str.size()-1; ++i){
        char C = str[i];
        if( !IsDigit( C ) ){
            cout << str << endl;
            return false;
        }else{
            Z += weight[i] * ( C - '0' );
        }
    }
    if ( M[ Z%11 ] != Last ){
        cout << str << endl;
        return false;
    }else{
        return true;
    }
}

inline bool IsDigit( const char C )
{
    return ( C >= '0' and C <= '9' );
}
