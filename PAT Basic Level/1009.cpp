#include<iostream>
#include<string>
//#include<fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
//    ofstream out("out.txt");
//    cout.rdbuf( out.rdbuf() );
    string Input[20];
    int i;
    for(i=0; !cin.eof(); ++i){
        cin >> Input[i];
    }
    for(i-=2; i>0; --i){
        cout << Input[i] << " ";
    }cout << Input[0] << endl;
    return 0;
}
