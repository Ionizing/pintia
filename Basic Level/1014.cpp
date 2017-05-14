#include <iostream>
#include <string>
#include <iomanip>
//#include <fstream>

using namespace std;

inline bool IsAlphabet( const char T, bool Capital = false)
{
    if( Capital ) return (T >= 'A' and T <= 'G');
    else
        return ( (T >= 'A' and T <= 'Z') or (T >= 'a' and T <= 'z') );
}

inline bool CharJudge( const char T )
{
    return ( (T >= 'A' and T <= 'N') or ( T >= '0' and T <= '9' ) );
}

void PrintDay( const char T )
{
    string Day[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int ind = T - 'A';
    cout << Day[ind] << " ";
}

void PrintHour( const char T )
{
    int tmp;
    if ( T >= '0' and T <= '9' ){
        tmp = T - '0';
    }else {
        tmp = 10 + T - 'A';
    }
    cout << setfill('0') << setw(2) << tmp << ":";
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf(in.rdbuf());
    string str1, str2, str3, str4;
    cin >> str1 >> str2 >> str3 >> str4;
    auto length = ( str1.length() > str2.length() ) ? str2.length() : str1.length() ;
    size_t i;
    for(i=0; i!=length; ++i){
        char tmp1 = str1[i];
        char tmp2 = str2[i];
        if ( !IsAlphabet(tmp1,true) or !IsAlphabet(tmp2,true) ) continue;
        if ( tmp1 == tmp2 ){
            char Data = tmp1;
            PrintDay( Data );
            break;
        }
    }
    for(++i; i!=length; ++i){
        char tmp1 = str1[i];
        char tmp2 = str2[i];
        if( !CharJudge(tmp1) or !CharJudge(tmp2) ) continue;
        if ( tmp1 == tmp2 ){
            char Data = tmp1;
            PrintHour( Data );
            break;
        }
    }
    length = ( str3.length() > str4.length() ) ? str4.length() : str3.length();
    for(i=0; i!=length; ++i){
        char tmp1 = str3[i];
        char tmp2 = str4[i];
        if ( !IsAlphabet(tmp1) or !IsAlphabet(tmp2) ) continue;
        if ( tmp1 == tmp2 ){
            cout << setfill('0') << setw(2) << i << endl;
            break;
        }
    }
    return 0;
}
