#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int B=0, S=0, G=0;
    if( n/100 != 0 ){
        B = n/100;
        n %= 100;
        S = n/10;
        G = n%10;
    }else if ( n/10 != 0 ){
        S = n/10;
        G = n%10;
    }else{
        G = n;
    }
    for(int i=0; i<B; ++i){
        cout << "B";
    }
    for(int i=0; i<S; ++i){
        cout << "S";
    }
    for(int i=0; i<G; ++i){
        cout << i+1;
    }
    cout << endl;
    return 0;
}
