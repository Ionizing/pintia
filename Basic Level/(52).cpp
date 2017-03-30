#include <iostream>
#include <vector>
#include <string>
//#include <fstream>

using namespace std;

void Extract( const string str, vector<string> &S )
{
    for(size_t i=0; i!=str.length(); ++i){
        if( str[i] == '[' ){
            ++i;
            string tmp;
            while( str[i] != ']' ){
                tmp.push_back( str[i] );
                ++i;
            }
            S.push_back( tmp );
            --i;
        }
    }
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    vector<string> Hand;
    vector<string> Eye;
    vector<string> Mouth;
    string str;

    getline(cin, str);
    Extract(str, Hand);
//    for( auto i : Hand ) cout << i << " ";
//    cout << endl;

    getline(cin, str);
    Extract(str, Eye);
//    for( auto i : Eye ) cout << i << " ";
//    cout << endl;

    getline(cin, str);
    Extract(str, Mouth);
//    for( auto i : Mouth ) cout << i << " ";
//    cout << endl;

    int n;
    cin >> n;
    for(int i=0; i!=n; ++i){
        string tmpstr;
        size_t hl, el, mo, er, hr;
        cin >> hl >> el >> mo >> er >> hr;
        bool flag = ( hl > Hand.size() or hr > Hand.size() );
        flag = ( flag or ( el > Eye.size() or er > Eye.size() ) );
        flag = ( flag or ( mo > Mouth.size() ) );
        flag = ( flag or ( hl <1 or el <1 or mo < 1 or er <1 or hr <1 ) );
        if( flag == true ){
            cout << "Are you kidding me? @\\/@" << endl;
        }else{
            cout << Hand[hl-1] << "(" << Eye[el-1] << Mouth[mo-1]
                << Eye[er-1] << ")" << Hand[hr-1] << endl;
        }
    }
    return 0;
}
