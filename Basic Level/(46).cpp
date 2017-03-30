#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n;
    cin >> n;
    int Asay, Ashow, Bsay, Bshow;
    int Adrink = 0, Bdrink = 0;
    for(int i=0; i!=n; ++i){
        cin >> Asay >> Ashow >> Bsay >> Bshow;
        int sum = Asay + Bsay;
        if( Ashow == sum and Bshow != sum ) ++Bdrink;
        else if ( Ashow != sum and Bshow == sum ) ++Adrink;
        else continue;
    }
    cout << Adrink << " " << Bdrink << endl;
    return 0;
}
