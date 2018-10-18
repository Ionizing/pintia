#include <iostream>
#include <algorithm>
//#include <fstream>

const int MAXSIZE = 1000000; // Max size of structures

using std::cin;
using std::cout;
using std::endl;

struct Account
{
    int Cpro = -1;
    int Math = -1;
    int Eng = -1;
    int Avg = -1;
};

bool cmp( const int a, const int b ){ return a > b; }
void GetBestRank(const int N, const Account Person,
                const int Cpro_rank[], const int Math_rank[],
                const int Eng_rank[], const int Avg_rank[] );
int GetRank( const int N, const int item, const int Arr[] );

int main()
{
//    std::ifstream cin("in.txt");
    Account* Arr = new Account[MAXSIZE];
    int N, M;
    cin >> N >> M;
    int *Cpro_rank = new int[N];
    int *Math_rank = new int[N];
    int *Eng_rank = new int[N];
    int *Avg_rank = new int[N];

    for(int i=0; i!=N; ++i){ // Data Input
        int ID;
        cin >> ID;
//        cout << "@39\n";
        cin >> Arr[ID].Cpro >> Arr[ID].Math >> Arr[ID].Eng;
        Arr[ID].Avg = (Arr[ID].Cpro + Arr[ID].Eng + Arr[ID].Math) / 3;
//        cout << "@41\n";
        Cpro_rank[i] = Arr[ID].Cpro;
        Math_rank[i] = Arr[ID].Math;
        Eng_rank[i] = Arr[ID].Eng;
        Avg_rank[i] = Arr[ID].Avg;
//        cout << "@46\n";
    }

    std::sort( Cpro_rank, Cpro_rank+N, cmp );
    std::sort( Math_rank, Math_rank+N, cmp );
    std::sort( Eng_rank, Eng_rank+N, cmp );
    std::sort( Avg_rank, Avg_rank+N, cmp );

//    for(int i=0; i!=N; ++i){
//        cout << Avg_rank[i] << endl;
//    }

    for(int i=0; i!=M; ++i){
        int ID;
        cin >> ID;
        if( -1 == Arr[ID].Avg ){
            cout << "N/A" << endl;
        }else{
            GetBestRank(N, Arr[ID], Cpro_rank, Math_rank, Eng_rank, Avg_rank);
        }
    }

    return 0;
}

void GetBestRank(const int N, const Account Person,
                const int Cpro_rank[], const int Math_rank[],
                const int Eng_rank[], const int Avg_rank[] )
{
    int C, M, E, A;
    int res_rank;
    char res_subject;

    A = GetRank(N, Person.Avg, Avg_rank);
    res_rank = A, res_subject = 'A';
    C = GetRank(N, Person.Cpro, Cpro_rank);
    if( C < res_rank ){
        res_rank = C, res_subject = 'C';
    }

    M = GetRank(N, Person.Math, Math_rank);
    if( M < res_rank ){
        res_rank = M, res_subject = 'M';
    }

    E = GetRank(N, Person.Eng, Eng_rank);
    if( E < res_rank ){
        res_rank = E, res_subject = 'E';
    }

    cout << res_rank << " " << res_subject << endl;
}

int GetRank( const int N, const int item, const int Arr[] )
{
    for(int i=0; i!=N; ++i){
        if( item == Arr[i] ) return i+1;
    }
    return -1;
}
