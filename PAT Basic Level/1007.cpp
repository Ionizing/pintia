#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool IsPrime( const int n )
{
    if( n == 2){
        return true;
    }
    if( n%2 == 0 ) {
        return false;
    }
    int i;
    for(i=3; i<=sqrt(n); i+=2){
        if ( n%i == 0 ) break;
    }
    if ( i>sqrt(n) ) return true;
    else return false;
}

int main()
{
    int N;
    cin >> N;
//    for(int i=2; i<=N; ++i){
//        cout << i << " " << IsPrime(i) << endl;
//    }
    vector<int> Primes;
    for(int i=2; i<=N; ++i){
        if ( IsPrime(i) ){
            Primes.push_back( i );
        }
    }
    int num = 0;
    for(int i=0; i<Primes.size()-1; ++i){
        if( Primes[i+1] - Primes[i] == 2 ){
            ++num;
        }
    }
    cout << num << endl;
    return 0;
}
