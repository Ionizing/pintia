#include <iostream>
#include <string>
//#include <fstream>

using namespace std;


const string Low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
        "jly", "aug", "sep", "oct", "nov", "dec"};

const string High[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei",
        "elo", "syy", "lok", "mer", "jou"};

int Decrypt( const string str, const string type )
{
    if( type == "Low" ){
        for( size_t i=0; i!=13; ++i ){
            if( str == Low[i] ) return i;
        }
        return 0;
    }else{
        for( size_t i=0; i!=13; ++i ){
            if( str == High[i] ) return i;
        }
        return 0;
    }
}

void Judge( const string str )
{
    if( str[0] >= '0' and str[0] <= '9' ){
        int sum = 0;
        for(size_t i(0); i!=str.length(); ++i){
            sum = sum*10 + str[i] - '0';
        }
        if( sum < 13 ){
            cout << Low[sum] << endl;
        }else{
            if( sum % 13 == 0 ) cout << High[sum/13] << endl;
            else cout << High[sum/13] << " " << Low[sum%13] << endl;
        }
        return;
    }else{;
        string high, low;
        size_t i;
        for(i=0; i<str.length(); ++i){
            if( str[i] == ' ' ) break;
            high.push_back( str[i] );
        }
        for(++i ; i<str.length(); ++i){
            low.push_back( str[i] );
        }
//        cout << "high:" << high << endl << "low:" << low << endl;
        if( low.length() > 0 ){
            cout << Decrypt(high, "High")*13 + Decrypt(low, "Low") << endl;
            return;
        }else{
            cout << Decrypt(high, "Low") + Decrypt(high, "High")*13 << endl;
            return;
        }
    }
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n;
    cin >> n;
    string str;
    getline(cin, str);
    for(int i=0; i<n; ++i){
        getline(cin, str);
//        cout << "str:" << str << endl;
        Judge( str );
    }
    return 0;
}
