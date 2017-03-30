#include <iostream>
#include <iomanip>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n;
    cin >> n;
    int Data[5][2] = {0};
    int flag = 1;
    for(int i=0; i<n; ++i){
        int tmp;
        cin >> tmp;
        switch ( tmp % 5 )
        {
        case 0:
            if( tmp%2 == 0 ){
                ++Data[0][0];
                Data[0][1] += tmp;
            }
            break;
        case 1: ++Data[1][0];
            Data[1][1] += tmp*flag;
            flag *= -1;
            break;
        case 2: ++Data[2][0];
            ++Data[2][1];
            break;
        case 3: ++Data[3][0];
            Data[3][1] += tmp;
            break;
        case 4: ++Data[4][0];
            Data[4][1] = ( tmp > Data[4][1] ) ? tmp : Data[4][1];
            break;
        }
    }
    for(int i=0; i<5; ++i){
        double tmp;
        if ( Data[i][0] == 0 ){
            if ( i == 4 ) cout << "N" << endl;
            else cout << "N ";
            continue;
        }
        switch (i)
        {
        case 0: ;
        case 1: ;
        case 2: cout << Data[i][1] << " "; break;
        case 3: tmp = Data[i][1]/( Data[i][0] + .0 );
            cout << setiosflags(ios::fixed) << setprecision(1) << tmp << " ";
            break;
        case 4: cout << Data[i][1] << endl;
            break;
        default: break;
        }
    }
    return 0;
}
