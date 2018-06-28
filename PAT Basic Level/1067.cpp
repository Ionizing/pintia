#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in( "in.txt" );
//    cin.rdbuf( in.rdbuf() );
    string TruePw;
    int Num;
    cin >> TruePw >> Num;
    int N = 0;
    string tmp;
    getline(cin, tmp);
    while( true ){
        getline(cin, tmp);
        if( "#" == tmp ) break;
        if( TruePw == tmp ){
            ++N;
            cout << "Welcome in" << endl;
            break;
        }else{
            ++N;
            cout << "Wrong password: " << tmp << endl;
            if( N >= Num ){
                cout << "Account locked" << endl;
                break;
            }
        }
    }
    return 0;
}
