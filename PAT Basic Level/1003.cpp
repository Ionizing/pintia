#include<iostream>
#include<string>
//#include<fstream>

using namespace std;

bool fun(string str);
void print( bool flag );

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n; cin >> n;
    for(int i=0; i<n; ++i){
        string str;
        cin >> str;
        print( fun(str) );
    }
    return 0;
}

bool fun(string str)
{
    int A1 = 0,A2 = 0,A3 = 0,P = 0,T = 0;
    for(int i=0; i<str.length(); ++i){
        switch (str[i])
        {
        case 'P': ++P; break;
        case 'T': ++T; break;
        case 'A':
            {
                if ( P==0 && T==0 ) ++A1;
                else if( P!=0 && T==0 ) ++A2;
                else ++A3;
                break;
            }
        default: return false;
        }
        if(P>=2 || T>=2) return false;
    }
    if ( P==0 || T==0 || (A1 + A2 + A3 == 0) ) return false;
    if ( (A1*A2-A3 != 0) || A2 == 0 ) return false;
    return true;
}

void print( bool flag )
{
    if( flag == true ){
        cout << "YES" << endl;
        return;
    }else{
        cout << "NO" << endl;
        return;
    }
}