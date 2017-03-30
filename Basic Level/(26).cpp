#include <iostream>
#include <iomanip>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int t1, t2;
    cin >> t1 >> t2;
    int interval = (t2 - t1 + 50) / 100;
    int Hour = interval / 3600;
    interval %= 3600;
    int Minute = interval / 60;
    interval %= 60;
    int Second = interval;
    cout << setfill('0') << setw(2)
         << Hour << ":" << setfill('0') << setw(2)
         << Minute << ":" << setfill('0') << setw(2)
         << Second << endl;
    return 0;
}
