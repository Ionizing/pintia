#include <iostream>
//#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N;
    cin >> N;
    int *Arr = new int[N];
    for(int i=0; i!=N; ++i){
        cin >> Arr[i];
    }
    sort(Arr, Arr+N);
    double sum = Arr[0];
    for(int i=1; i!=N; ++i){
        sum = ( sum + Arr[i] ) / 2;
    }
    cout << int(sum) << endl;
    delete[] Arr;
    return 0;
}
