#include <iostream>
//#include <fstream>

const int null = -1;
const int MAXSIZE = 100;
using namespace std;

typedef int Tree;
struct TreeNode
{
    Tree Child = null;
    Tree Brother = null;
};

void BuildTree( const Tree Root, TreeNode A[] );
void PreOrder( const Tree Root, const TreeNode A[], int *Level );

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N, M;
    cin >> N >> M;
    int *Leaves = new int[N];
    for(int i=0; i!=N; ++i) Leaves[i] = 0;
    struct TreeNode A[MAXSIZE];
    for(int i=0; i!=M; ++i){
        int ID;
        cin >> ID;
        BuildTree(ID, A);
//        cout << "@31 " << ID << endl;
    }
    PreOrder( 1, A, Leaves );
//    cout << "=================" << endl;
    int Max;
    for(int i=N-1; i>=0; --i){
        if( Leaves[i] != 0 ){
            Max = i;
            break;
        }
    }

    for(int i=0; i!=Max+1; ++i){
        if( i != Max ) cout << Leaves[i] << " ";
        else cout << Leaves[i] << endl;
    }
    return 0;
}

void BuildTree( const Tree Root, TreeNode A[] )
{
    int N;
    cin >> N;
    if( 0 == N ) return;
    int ind = Root;
    for(int i=0; i!=N; ++i){
        int ID;
        cin >> ID;
        if( 0 == i ){
            A[ind].Child = ID;
        }else{
            A[ind].Brother = ID;
        }
        ind = ID;
    }
}

void PreOrder( const Tree Root, const TreeNode A[], int* Level )
{
    if( null == Root ) return;
//    cout << Root << " ";
    if( null == A[Root].Child ) ++(*Level);
    PreOrder( A[Root].Brother, A, Level );
    PreOrder( A[Root].Child, A, Level + 1 );
}
