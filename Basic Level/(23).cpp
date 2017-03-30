#include <iostream>
#include <stack>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int num[10];
    for(int i=0; i!=10; ++i){
        cin >> num[i];
    }
    stack<int> S;
    for(int i=9; i!=0; --i){
        for(int j=0; j!=num[i]; ++j){
            S.push( i );
        }
    }
    cout << S.top();
    S.pop();
    for(int i=0; i!=num[0]; ++i){
        S.push(0);
    }

    while( !S.empty() ){
        cout << S.top();
        S.pop();
    }
    cout << endl;
    return 0;
}
