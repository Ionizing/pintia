#include <iostream>
#include <iomanip>
#include <string>
//#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

double FindMax( const double W, const double T, const double L, char &ind )
{
    double Max;
    Max = ( W > T ) ? W : T;
    ind = ( W > T ) ? 'W' : 'T';
    Max = ( Max > L ) ? Max : L;
    ind = ( Max > L ) ? ind : 'L';
    return Max;
}

int main()
{
//    std::ifstream cin("in.txt");
    int N = 3;
    double Profit = 1;
    double W, T, L;
    string Res;
    char ind;
    for(int i=0; i!=N; ++i){
        cin >> W >> T >> L;
        Profit *= FindMax(W, T, L, ind);
        Res.push_back(ind);
    }
    for(int i=0; i!=N; ++i){
        cout << Res[i] << " ";
    }
    Profit = (Profit*0.65 - 1) * 2;
//    Profit = Profit + .005;
    cout << std::setiosflags(std::ios::fixed) << std::setprecision(2)
        << Profit << endl;
    return 0;
}
