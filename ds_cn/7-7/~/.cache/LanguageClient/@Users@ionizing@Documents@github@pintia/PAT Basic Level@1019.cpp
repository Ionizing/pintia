#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string int2str( int A );
int str2int( const string A );
bool cmp( const char a, const char b );
void Sort( string &A, bool Ascend );
int Calculate( const string S );

int main()
{
    int A;
    cin >> A;
    if( A % 1111 == 0 ){
        cout << int2str(A) << " - " << int2str(A) << " = " << "0000" << endl;
        return 0;
    }
    string strA = int2str(A);
    int res = 0;
    while( res != 6174 ){
        res = Calculate(strA);
        strA = int2str( res );
        cout << strA << endl;
    }
    return 0;
}

string int2str( int A )
{
    string strA("0000");
    for(int i=3; i!=-1; --i){
        strA[i] = A%10 + '0';
        A /= 10;
    }
    return strA;
}

int str2int( const string A )
{
    int res = 0;
    for(size_t i=0; i!=A.length(); ++i){
        res = 10*res + A[i] - '0';
    }
    return res;
}

bool cmp( const char a, const char b )
{
    return ( a > b );
}

void Sort( string &A, bool Ascend )
{
    if( Ascend == true )
        sort(A.begin(), A.end());
    else
        sort(A.begin(), A.end(), cmp);
    return;
}

int Calculate( const string S )
{
    string A=S, B=S;
    Sort(A,false); Sort(B,true);
    cout << A << " - " << B << " = ";
    return str2int(A) - str2int(B);
}
