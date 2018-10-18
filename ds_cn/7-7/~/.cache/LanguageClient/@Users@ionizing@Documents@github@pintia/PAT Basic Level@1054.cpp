#include <iostream>
#include <string>
//#include <fstream>
#include <iomanip>

using namespace std;

bool Judge( const string str, double &ResA )
{
    size_t len = str.length();
    int DotOccured = 1;
    bool IsMinus = ( '-' == str[0] );
    double Sum = .0;
    for(size_t i=0; i!=len; ++i){
//        cout << "str == " << str << " ,IsMinus = " << IsMinus << endl;
        if( IsMinus and 0 == i and 1 != len ) continue;
        if( IsMinus and 1 == len ){
            cout << "ERROR: " << str << " is not a legal number" << endl;
            return false;
        }
        if( str[i] == '.' or ( str[i] >= '0' and str[i] <= '9' ) ){
            if( str[i] == '.' and 1 == DotOccured ){
                DotOccured *= 10;
            }else if( DotOccured > 1 and '.' == str[i] ){
                cout << "ERROR: " << str << " is not a legal number" << endl;
                return false;
            }else{
                if( DotOccured > 100 ){
                    cout << "ERROR: " << str << " is not a legal number" << endl;
                    return false;
                }
                if( 1 == DotOccured ){
                    Sum = 10*Sum + str[i] - '0';
                }
                else{
                    Sum += (str[i] - '0' + .0)/(DotOccured);
                    DotOccured *= 10;
                }
            }
            if( Sum > 1000 or Sum < -1000 ){
                cout << "ERROR: " << str << " is not a legal number" << endl;
                return false;
            }
        }else{
            cout << "ERROR: " << str << " is not a legal number" << endl;
            return false;
        }
    }
    Sum = ( IsMinus ) ? -Sum : Sum;
    ResA += Sum;
    return true;
//    cout << Sum << " ";
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N;
    cin >> N;
    double ResA = .0;
    int ResB = 0;
    for(int i=0; i!=N; ++i){
        string tmp;
        cin >> tmp;
//        cout << "tmp.length() == " << tmp.length() << endl;
        ResB += Judge( tmp, ResA ) ? 1 : 0;
    }
    if( 0 == ResB ) cout << "The average of 0 numbers is Undefined" << endl;
    else if ( 1 == ResB ) cout << "The average of " << ResB << " number is " << setiosflags(ios::fixed) << setprecision(2) << ResA/ResB << endl;
    else cout << "The average of " << ResB << " numbers is " << setiosflags(ios::fixed) << setprecision(2) << ResA/ResB << endl;
    return 0;
}
