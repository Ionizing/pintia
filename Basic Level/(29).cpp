#include <iostream>
#include <string>
//#include <fstream>

using namespace std;
void Fun( string &A )
{
    for(auto i=A.begin(); i!=A.end(); ++i){
        if( *i <= 'z' && *i >= 'a' )
            *i = *i - 'a' + 'A';
    }
    for(size_t i=0; i<A.size(); ++i){
        for(size_t j=i+1; j<A.size(); ++j){
            if( A[i] == A[j] ){
                A.erase( A.begin()+j );
                --j;
            }
        }
    }
}

void Print( string A, string B )
{
    for( auto i : A ){
        bool Occured = false;
        for( auto j : B ){
            if( i == j )
                Occured = true;
        }
        if( Occured == true ) continue;
        else cout << i;
    }
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    string A, B;
    cin >> A >> B;
    Fun(A); Fun(B);
//    cout << A << endl << B << endl;
    Print(A, B);
    return 0;
}
