#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N;
    cin >> N;
    int sum = 0;
    for(int i=0; i!=N; ++i){
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    sum = sum*11*(N-1);
    cout << sum;
    return 0;
}
