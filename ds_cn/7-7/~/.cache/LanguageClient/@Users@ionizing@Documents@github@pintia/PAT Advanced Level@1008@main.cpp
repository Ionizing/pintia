#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int Last = 0;
    int Time = 0;
    for(int i=0; i!=N; ++i){
        int This;
        cin >> This;
        Time += ( This - Last > 0 ) ? 6*(This - Last) : 4*(Last - This);
        Time += 5;
        Last = This;
    }
    cout << Time;
    return 0;
}
