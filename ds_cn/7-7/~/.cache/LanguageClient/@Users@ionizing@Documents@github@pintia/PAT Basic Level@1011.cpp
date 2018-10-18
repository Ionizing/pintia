#include<iostream>
//#include<fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n;
    cin >> n;
    long int A,B,C;
    for(int i=1; i<=n; ++i){
        cin >> A >> B >> C;
        cout << "Case #" << i << ": ";
        if( A+B > C ) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}
