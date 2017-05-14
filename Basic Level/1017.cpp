#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    string A;
    int tobeDiv[1000] = {0};
    int B;
    cin >> A >> B;
    for(size_t i=0; i!=A.length(); ++i){
        tobeDiv[i] = A[i] - '0';
    }
    int Divided[1000] = {0};
    int tmp = 0;
    for(size_t i=0; i!=A.length(); ++i){
        Divided[i] = (tobeDiv[i] + 10*tmp) / B;
        tmp = (tobeDiv[i] + 10*tmp) % B;
    }
    size_t i = 0;
    while( i != A.length()-1 ){
        if( Divided[i] != 0 ) break;
        ++i;
    }
    for(; i!=A.length(); ++i){
        cout << Divided[i];
    }cout << " " << tmp << endl;
    return 0;
}
