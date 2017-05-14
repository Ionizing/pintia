#include <iostream>

using namespace std;

int main()
{
    int n;
    char a;
    cin >> n >> a;
    int lines = int((n+.0)/2 + 0.5 );
    for(int i=0; i!=lines; ++i){
        if(i == 0 or i == lines-1){
            for(int j=0; j!=n; ++j){
                cout << a;
            }cout << endl;
        }else{
            for(int j=0; j!=n; ++j){
                if( j==0 or j==n-1 ) cout << a;
                else cout << " ";
            }cout << endl;
        }
    }
    return 0;
}
