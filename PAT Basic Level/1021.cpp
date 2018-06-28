#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int arr[10] = {0};
    string str;
    cin >> str;
    for(size_t i=0; i!=str.length(); ++i){
        ++arr[ str[i]-'0' ];
    }
    for(int i=0; i!=10; ++i){
        if(arr[i] == 0) continue;
        cout << i << ":" << arr[i] << endl;
    }
}
