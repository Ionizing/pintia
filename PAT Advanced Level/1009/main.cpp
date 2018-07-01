#include <iostream>
#include <iomanip>
#include <vector>
//#include <fstream>
const int MAXSIZE = 2001;

using namespace std;

struct Node
{
    int Index = 0;
    double Coeff = .0;
};

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N;
    cin >> N;
    Node *A = new Node[N];
    for(int i=0; i!=N; ++i){
        cin >> A[i].Index >> A[i].Coeff;
    }
    double Result[MAXSIZE] = {.0};
    int N2;
    cin >> N2;
    for(int i=0; i!=N2; ++i){
        int ind;
        double coeff;
        cin >> ind >> coeff;
        for(int j=0; j!=N; ++j){
            int tmpind = ind + A[j].Index;
            Result[tmpind] += coeff * A[j].Coeff;
        }
    }
    vector<struct Node> Res;
    for(int i=MAXSIZE-1; i>=0; --i){
        if( Result[i] > .05 or Result[i] < -.05 ){
            Node tmp;
            tmp.Coeff = Result[i], tmp.Index = i;
            Res.push_back( tmp );
        }
    }
    cout << Res.size();
    for(size_t i=0; i!=Res.size(); ++i){
        cout << " " << Res[i].Index << " " << setiosflags(ios::fixed) << setprecision(1) << Res[i].Coeff;
    }
    return 0;
}
