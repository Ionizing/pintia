#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N0;
    char Sign;
    cin >> N0 >> Sign;
    if ( N0 == 1 ) {
        cout << Sign << endl;
        cout << 0 << endl;
        return 0;
    }
    int lines, N;
    for(lines=3, N=1; N<=N0; lines+=2){
        N += 2*lines;
    }
    lines -= 2;
    N -= 2*lines;
    lines -= 2;

    for(int i=0; i<lines; ++i){
        if( i <= lines/2 ){
            for(int j=0; j!=i; ++j){
                cout << " ";
            }
            for(int j=i; j!=lines-i; ++j){
                cout << Sign;
            }
        }
        if( i > lines/2 ){
            for(int j=lines-i; j!=1; --j){
                cout << " ";
            }
            for(int j=0; j!=2*i-lines+2; ++j){
                cout << Sign;
            }
        }
        cout << endl;
    }
    cout << N0 - N ;
    return 0;
}
