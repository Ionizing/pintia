#include <iostream>
#include <string>
#include <algorithm>
//#include <fstream>

using namespace std;

struct Student
{
    string Name = "";
    int Height = 0;
};

bool cmp( const Student A, const Student B )
{
//    cout << "@16" << endl;
    if( A.Height != B.Height ) return ( A.Height > B.Height );
    else return ( A.Name < B.Name );
}

void Arrange( Student A[], const int left, const int right ) // [left, right)
{
    string Result = "";
    for(int i=0; left+i < right; ++i){
        if( 0 == i ) Result = A[left+i].Name;
        else if( i%2 == 1 ) Result = A[left+i].Name + " " + Result;
        else Result = Result + " " + A[left+i].Name;
//        cout << "@28" << endl;
    }
    cout << Result << endl;
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N, K;
    cin >> N >> K;
    struct Student *A = new Student[N];
    for(int i=0; i!=N; ++i){
        cin >> A[i].Name >> A[i].Height;
    }
    sort(A, A+N, cmp);
//    Arrange(A, 0, N);
    int Rest = N % K;
    if( Rest != 0 ){
        Arrange(A, 0, N/K+Rest);
        for(int i=1; i!=K; ++i){
            Arrange(A, Rest+N/K*i, Rest+N/K*i+N/K);
        }
    }else{
        for(int i=0; i!=K; ++i){
            Arrange(A, N/K*i, N/K*i+N/K);
        }
    }
    delete[] A;
    return 0;
}
