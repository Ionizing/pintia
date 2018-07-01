// PAT-A 1010
#include <iostream>
#include <string>
//#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

long long Evaluate( const string str, const long long radix );
long long BinSearch( const long long low_radix, const long long high_radix,
               const string str, const long long Target );
int FindMinRadix( const string &str );
void Swap(string &A, string &B);
int cmp( const string &str, const long long radix, const long long Target );

int main()
{
//    std::ifstream cin("in.txt");
    string A, B;
    long long tag, radix;
    cin >> A >> B >> tag >> radix;

    long long Target;
    long long low_radix;
    long long high_radix;
    if( 2 == tag ) Swap( A, B );

    Target = Evaluate( A, radix );
//    cout << "@30 " << Target << endl;
    low_radix = FindMinRadix( B );
    high_radix = ( Target > low_radix ) ? Target + 1 : low_radix + 1;
    long long res = BinSearch(low_radix, high_radix, B, Target);
    if( -1 == res ){
        cout << "Impossible" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}

long long Evaluate( const string str, const long long radix )
{
    long long Res = 0;
    long long len = str.length();
    for(int i=0; i!=len; ++i){
        if( str[i] >= 'a' and str[i] <='z' )
            Res = Res*radix + ( str[i]-'a' + 10 );
        else
            Res = Res*radix + str[i] - '0';
    }
    return Res;
}

long long BinSearch( const long long low_radix, const long long high_radix,
                     const string str, const long long Target )
{
    long long mid = low_radix;
    long long low = low_radix, high = high_radix;
    while( low <= high ){
        int flag = cmp(str, mid, Target);
        if( 1 == flag ){
            high = mid -1;
        }else if ( -1 == flag ){
            low = mid + 1;
        }else {
            return mid;
        }
        mid = ( low + high ) / 2;
    }
    return -1;
}

int FindMinRadix( const string &str )
{
    long long radix = 1;
    const long long len = str.length();
    for(int i=0; i!=len; ++i){
        int tmp;
        if( str[i] >= 'a' and str[i] <= 'z' ){
            tmp = str[i] - 'a' + 10;
        }else{
            tmp = str[i] - '0';
        }
        radix = ( radix < tmp ) ? tmp : radix;
    }
    ++radix;
    return radix;
}

void Swap(string &A, string &B)
{
    string tmp;
    tmp = A;
    A = B;
    B = tmp;
    return;
}

int cmp( const string &str, const long long radix, const long long Target )
{
    int len = str.length();
    long long tmp = 1;
    long long sum = 0;
    for(int i=len-1; i>=0; --i){
        if( str[i] >= 'a' and str[i] <= 'z' ){
            sum += tmp*(str[i] - 'a' + 10);
        }else{
            sum += tmp*(str[i] - '0');
        }
        if( sum > Target ) return 1;
        tmp *= radix;
    }
    if( sum < Target ) return -1;
    else if( sum > Target ) return 1;
    else return 0;
}
