#include <iostream>
#include <queue>
#include <vector>
//#include <fstream>

using namespace std;

typedef int ElementType;
typedef struct TreeNode *Tree;
struct TreeNode
{
    ElementType Data = -1;
    Tree lChild = nullptr;
    Tree rChild = nullptr;
};

Tree BuildTree(const int InLeft, const int InRight,
               const int PoLeft, const int PoRight,
               const ElementType In[], const ElementType Post[])
{
    if( PoLeft > PoRight ) return nullptr;
    Tree Root = new TreeNode;
    Root->Data = Post[PoRight];
    int ind;
    for(ind=InLeft; ind<=InRight; ++ind){
        if( In[ind] == Post[PoRight] ) break;
    }
    int NumOfShift = InRight - ind;
    Root->lChild = BuildTree(InLeft, ind-1, PoLeft, PoRight-NumOfShift-1, In, Post);
    Root->rChild = BuildTree(ind+1, InRight, PoRight-NumOfShift, PoRight-1, In, Post);
    return Root;
}

//
//void PreOrder( const Tree Root )
//{
//    if( nullptr != Root ){
//        cout << Root->Data << " ";
//        PreOrder( Root->lChild );
//        PreOrder( Root->rChild );
//    }
//}

vector<int> LevelOrder( const Tree Root )
{
    vector<int> Res;
    if( nullptr == Root ) return Res;
    queue<Tree> Q;
    Q.push( Root );
    while( !Q.empty() ){
        Tree tmp = Q.front();
//        cout << tmp->Data << " ";
        Res.push_back( tmp->Data );
        Q.pop();
        if( nullptr != tmp->lChild ) Q.push( tmp->lChild );
        if( nullptr != tmp->rChild ) Q.push( tmp->rChild );
    }
    return Res;
}

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    int N;
    cin >> N;
    ElementType *Post = new ElementType[N];
    for(int i=0; i!=N; ++i){
        cin >> Post[i];
    }
    ElementType *In = new ElementType[N];
    for(int i=0; i!=N; ++i){
        cin >> In[i];
    }
    Tree Root = BuildTree(0, N-1, 0, N-1, In, Post);
    vector<int> Res = LevelOrder( Root );
    for(size_t i=0; i!=Res.size(); ++i){
        if( 0 == i ) cout << Res[i];
        else cout << " " << Res[i];
    }cout << endl;
    return 0;
}
