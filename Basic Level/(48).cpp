#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

void StrRev( string &S )
{
    const size_t len = S.length();
    size_t beg = 0, end = len-1;
    while( beg < end ){
        char tmp = S[beg];
        S[beg] = S[end];
        S[end] = tmp;
        ++beg, --end;
    }
}

void Encrypt( string A, string B )
{
    StrRev(A), StrRev(B);
    size_t lenA = A.length(), lenB = B.length();
    if( lenA < lenB ){
        for(size_t i=lenA; i<lenB; ++i){
            A.push_back('0');
        }
    }else{
        for(size_t i=lenB; i<lenA; ++i){
            B.push_back('0');
        }
    }
//    cout << A << " " << B << endl;
    string C;
    for(size_t i=0; i!=A.length(); ++i){
        size_t curr = i+1;
        if( curr % 2 != 0 ){
            char tmp = ( A[i] + B[i] - '0'*2 ) % 13 + '0';
            if( '0' + 10 == tmp ) tmp = 'J';
            if( '0' + 11 == tmp ) tmp = 'Q';
            if( '0' + 12 == tmp ) tmp = 'K';
            C.push_back(tmp);
        }else{
            int tmp = B[i] - A[i];
            char Tmp = ( tmp >= 0 ) ? tmp + '0' : tmp + '0' + 10;
            C.push_back(Tmp);
        }
    }
    StrRev(C);
    cout << C << endl;
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    string A, B;
    cin >> A >> B;
    Encrypt(A, B);
    return 0;
}
