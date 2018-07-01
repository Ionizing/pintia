#include <iostream>
#include <vector>
//#include <fstream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
//    std::ifstream cin("in.txt");
    int N, Radix;
    cin >> N >> Radix;

    std::vector<int> S;
    if( 0 == N ){
        cout << "Yes" << endl;
        cout << "0" << endl;
        return 0;
    }
    while( N != 0 ){
        int tmp = N % Radix;
        S.push_back( tmp );
        N /= Radix;
    }

    int end = S.size()-1;
    int beg = 0;
    bool flag = true;
    while( beg < end ){
        if( S[beg] != S[end] ){
            flag = false;
            break;
        }

        ++beg; --end;
    }
    if( flag ){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    end = S.size()-1;
    for(int i=end; i>=0; --i){
        if ( 0 == i ){
            cout << S[i] << endl;
        } else {
            cout << S[i] << " ";
        }
    }
    return 0;
}
