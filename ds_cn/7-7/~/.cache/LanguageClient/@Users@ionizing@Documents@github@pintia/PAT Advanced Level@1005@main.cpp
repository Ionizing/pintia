#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string N;
    cin >> N;
    int Res(0);
    for(size_t i(0); i!=N.length(); ++i){
        Res += N[i] - '0';
    }
    if( 0 == Res ){
        cout << "zero" << endl;
        return 0;
    }
    vector<string> Interpret = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    string Result("");
    while( Res != 0 ){
        Result = Interpret[ Res%10 ] + Result;
        if( Res / 10 != 0 ) Result = " " + Result;
        Res /= 10;
    }
    cout << Result << endl;
    return 0;
}
