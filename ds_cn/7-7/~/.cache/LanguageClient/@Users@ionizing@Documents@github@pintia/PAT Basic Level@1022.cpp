#include <iostream>
#include <stack>
//#include <fstream>

using namespace std;
void ConvPrint( const int i, const int D );

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int A,B,C,D;
    cin >> A >> B >> D;
    C = A + B;
//    cout << C << endl;
    ConvPrint( C, D );
    return 0;
}

void ConvPrint( const int I, const int D )
{
    stack<int> S;
    int tmp = I;
    while( tmp/D != 0 ){
        S.push( tmp%D );
        tmp /= D;
    }S.push(tmp);
    while( !S.empty() ){
        cout << S.top();
        S.pop();
    }
    cout << endl;
    return ;
}
