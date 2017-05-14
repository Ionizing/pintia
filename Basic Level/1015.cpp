#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student
{
    int ID = 0;
    int Moral = 0;
    int Skill = 0;
    int Sum = 0;
    int Priority = 0;
};

int GetPriority( Student& , const int L, const int H );
//void Sort( vector<Student> &S);
inline bool Compare( const Student S1, const Student S2 );
void Print( vector<Student> S );

int main()
{
//    freopen("in.txt","r",stdin);
    int N = 0, L = 0, H = 0;
    scanf("%d%d%d", &N, &L, &H);
    vector<Student> S1, S2, S3, S4;
    for(int i=0; i!=N; ++i){
        Student tmp;
        scanf("%d%d%d", &(tmp.ID), &(tmp.Moral), &(tmp.Skill));
        tmp.Sum = tmp.Moral + tmp.Skill;
        switch ( GetPriority( tmp, L, H ) )
        {
        case 0: continue;
        case 1: S1.push_back(tmp); break;
        case 2: S2.push_back(tmp); break;
        case 3: S3.push_back(tmp); break;
        case 4: S4.push_back(tmp); break;
        }
    }
    size_t M = S1.size() + S2.size() + S3.size() + S4.size();
    printf("%d\n",M);
//    Sort(S1); Sort(S2); Sort(S3); Sort(S4);
    sort(S1.begin(),S1.end(),Compare);
    sort(S2.begin(),S2.end(),Compare);
    sort(S3.begin(),S3.end(),Compare);
    sort(S4.begin(),S4.end(),Compare);

    Print(S4); Print(S3); Print(S2); Print(S1);
    return 0;
}

int GetPriority( Student &T, const int L, const int H)
{
    int M, S;
    M = T.Moral; S = T.Skill;
    if( M < L or S < L ) T.Priority = 0;
// The following conditions ensure that M and S must greater than L
    else if( M >= H and S >= H ) T.Priority = 4;
    else if( M >= H and S < H ) T.Priority = 3;
    else if( (M < H and S < H) and M >= S ) T.Priority = 2;
    else T.Priority = 1;

    return T.Priority;
}

//void Sort( vector<Student> &S )
//{
//    size_t L = S.size();
//    if( L == 0 ) return;
//    for(size_t i=0; i!=L; ++i){
//        auto Max = S[i];
//        size_t ind = i;
//        for(size_t j=i; j!=L; ++j){
//            if ( Compare(S[j], Max) ){
//                Max = S[j];
//                ind = j;
//            }
//        }
//        auto tmp = S[ind];
//        S[ind] = S[i];
//        S[i] = tmp;
//    }
//}

inline bool Compare(const Student S1, const Student S2)
{
    if( S1.Sum != S2.Sum ){
        return ( S1.Sum > S2.Sum );
    }else{
        if( S1.Moral != S2.Moral )
            return ( S1.Moral > S2.Moral );
    }return ( S1.ID < S2.ID );
}

void Print( vector<Student> S )
{
    size_t L = S.size();
    if ( L == 0 ) return;
    else{
        for(size_t i=0; i!=L; ++i){
            printf("%d %d %d\n",S[i].ID, S[i].Moral, S[i].Skill);
        }
    }
}
