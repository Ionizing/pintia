#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

bool IsDigit( const char C ) { return (C >= '0' and C <= '9'); }
void Print( const char PreSign, const string Body, const char ProSign, const size_t Index );

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    string str;
    cin >> str;
    char PreSign = str[0]; //取出符号
    string Body;
    size_t i;
    for(i=1; i!=str.length(); ++i){
        if( IsDigit(str[i]) ){
            Body.push_back( str[i] );
        }
        if( !IsDigit( str[i] ) and str[i] != '.' )
            break;
    } // 取出主要数值部分。
    ++i;
    char ProSign = str[i++];
    size_t Index = 0;
    for( ; i!=str.length(); ++i ){
        Index = Index*10 + str[i] - '0';
    }
    Print(PreSign, Body, ProSign, Index);
    return 0;
}

void Print( const char PreSign, const string Body, const char ProSign, const size_t Index )
{
    if( PreSign == '-' ) cout << "-";
        if( ProSign == '-' ){
            cout << "0.";
            for(size_t i=1; i!=Index; ++i){
                cout << "0";
            }
            cout << Body << endl;
            return;
        }else{
            int Diff = Index - Body.length();
            if ( Diff+1 > 0 ){
                cout << Body;
                for(int i=0; i<Diff+1; ++i){
                    cout << 0;
                }
                cout << endl;
                return;
            }else if ( Diff+1 < 0 ){
                Diff = -Diff;
                for(size_t i=0; i!=Body.length(); ++i){
                    if( i == Diff ){
                        cout << Body[i] << '.';
                    }else{
                        cout << Body[i];
                    }
                }
                cout << endl;
                return;
            }else{
                cout << Body << endl;
                return;
            }
        }
}
