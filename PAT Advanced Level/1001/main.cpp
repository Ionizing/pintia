#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int a, b;
    cin >> a >> b;
    int c = a + b;
    if( 0 == c ){
        cout << "0" << endl;
        return 0;
    }
    bool IsMinus = false;
    if( c < 0 ){
        IsMinus = true;
        c = -c;
    }
    string Stack;
    for(int i=1; c!=0; ++i, c/=10 ){
        Stack.push_back( c % 10 + '0' );
        if( i%3 == 0 and c/10 != 0 ) Stack.push_back( ',' );
    }
    if( IsMinus ) Stack.push_back('-');
    int l = 0, r = Stack.length() - 1;
    while( l < r ){
        auto tmp = Stack[l];
        Stack[l] = Stack[r];
        Stack[r] = tmp;
        ++l, --r;
    }
    cout << Stack << endl;
    retur