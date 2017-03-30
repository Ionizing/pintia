#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num = 0;
    while ( n != 1 ){
        if( n%2 == 0 ){
            n /= 2;
            ++num;
        }else{
            n = (3*n+1)/2;
            ++num;
        }
    }
    cout << num << endl;
}
