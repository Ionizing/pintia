#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N, M;
    cin >> N >> M;
    int (*Correct)[2] = new int[M][2];
    for(int i=0; i!=M; ++i){
        cin >> Correct[i][0];
    }
    for(int i=0; i!=M; ++i){
        cin >> Correct[i][1];
    }
    int Sum;
    for(int i=0; i!=N; ++i){
        Sum = 0;
        for(int j=0; j!=M; ++j){
            int tmp; cin >> tmp;
            Sum += ( tmp == Correct[j][1] ) * Correct[j][0];
        }
        cout << Sum << endl;
    }
    return 0;
}
