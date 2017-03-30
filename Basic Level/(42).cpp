#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    string str;
    int Sta[26] = {0};
    getline(cin, str);
    for(int i=0; i!=str.length(); ++i){
        if( str[i] >= 'a' and str[i] <= 'z' ){
            ++Sta[ str[i] - 'a' ];
        }
        if( str[i] >= 'A' and str[i] <= 'Z' ){
            ++Sta[ str[i] - 'A' ];
        }
    }
    int ind = 0, Max = 0;
    for(int i=0; i!=26; ++i){
        if( Max < Sta[i] ){
            Max = Sta[i];
            ind = i;
        }
    }
    cout << char( ind + 'a' ) << " " << Max << endl;
    return 0;
}
