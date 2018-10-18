#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
//#include <fstream>

using namespace std;

struct MoonCake
{
    double Amount = 0;
    double TotalPrice = 0;
    double Price = 0;
};

bool cmp( const MoonCake A, const MoonCake B )
{
    return ( A.Price > B.Price );
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n, Total;
    cin >> n >> Total;
    vector<MoonCake> Type;
    for(int i=0; i!=n; ++i){
        MoonCake tmp;
        cin >> tmp.Amount;
        Type.push_back(tmp);
    }
    for(int i=0; i!=n; ++i){
        cin >> Type[i].TotalPrice;
        if( Type[i].Amount != 0)
            Type[i].Price = Type[i].TotalPrice / Type[i].Amount;
    }
    sort(Type.begin(), Type.end(), cmp);
    double amnt = 0, Profit = 0;
    for(int i=0; i<n; ++i){
        auto tmp = Type[i];
        if( tmp.Amount < Total - amnt ){
            Profit += tmp.TotalPrice;
            amnt += tmp.Amount;
            continue;
        }
        else{
            Profit += tmp.Price * ( Total - amnt  );
            break;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << Profit << endl;
    return 0;
}
