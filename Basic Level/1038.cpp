#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int Score[100] = {0};
    int n, tmp;
    cin >> n;
    for(int i=0; i!=n; ++i){
        cin >> tmp;
        ++Score[tmp];
    }
    cin >> n;
    for(int i=0; i!=n; ++i){
        cin >> tmp;
        if( i != n-1 ) cout << Score[tmp] << " ";
        else cout << Score[tmp] << endl;
    }
    return 0;
}
