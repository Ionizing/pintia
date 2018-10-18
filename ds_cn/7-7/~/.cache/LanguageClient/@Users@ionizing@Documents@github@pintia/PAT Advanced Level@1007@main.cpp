#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int n;
    cin >> n;
    int *A = new int[n];
    bool IsAllNeg = true;
    for(int i=0; i!=n; ++i){
        cin >> A[i];
        if( A[i] >= 0 ) IsAllNeg = false;
    }
    int left(0), right(0), Sum(0), Max(-1);
    int s(0);
    for(int i=0; i!=n; ++i){
        Sum += A[i];
        if( Sum > Max or ( Sum == Max and Max == 0 ) ){
            Max = Sum;
            right = i;
            left = s;
        }
        if( Sum < 0 ){
            Sum = 0;
            s = i + 1;
        }
    }
    if( true == IsAllNeg ){
        cout << "0 " << A[0] << " " << A[n-1] << endl;
    }else{
        cout << Max << " " << A[left] << " " << A[right] << endl;
    }
    return 0;
}
