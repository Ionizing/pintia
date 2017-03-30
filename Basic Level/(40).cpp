#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    string str;
    cin >> str;
    int sum = 0;
    int sumT = 0, sumAT = 0;
    for(int i=str.length()-1; i>=0; --i){
//        cout << i << " ";
        if( str[i] == 'T' ) ++sumT;
        else if ( str[i] == 'A' ) sumAT += sumT;
        else{
            sum += sumAT;
            sum = ( sum > 1000000007 ) ? sum%1000000007 : sum;
        }
    }
    cout << sum%1000000007 << endl;
    return 0;
}
