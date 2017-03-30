#include <iostream>
//#include <fstream>

using namespace std;

int fun( const int A, const int Da );

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int A, B, Da, Db;
    cin >> A >> Da >> B >> Db;
    int Pa, Pb;
    Pa = fun(A, Da);
    Pb = fun(B, Db);
    cout << Pa + Pb;
    return 0;
}

int fun( const int A, const int Da )
{
    int Result = 0;
    int Atmp = A;
    while( Atmp/10 ){
        if( Atmp%10 == Da )
            Result = Result*10 + Atmp%10;
        Atmp /= 10;
    }
    if( Atmp == Da )
        Result = Result*10 + Atmp;
    return Result;
}
