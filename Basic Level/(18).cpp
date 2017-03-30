#include <iostream>
//#include <fstream>

using namespace std;

struct Player
{
    int WTL[3] = {0};
    int BCJ[3] = {0};
};

void Judge(const char A, const char B, Player &pA, Player &pB);
int Convert( const char C );
char Convert( const int i );

int main()
{
//    ifstream in("in.txt");
//    cin.rdbuf( in.rdbuf() );
    Player A, B;
    int n;
    cin >> n;
    for(int i=0; i!=n; ++i){
        char tmpA, tmpB;
        cin >> tmpA >> tmpB;
        Judge(tmpA, tmpB, A, B);
    }
    cout << A.WTL[0] << " " << A.WTL[1] << " " << A.WTL[2] << endl;
    cout << B.WTL[0] << " " << B.WTL[1] << " " << B.WTL[2] << endl;

    int ind = 0, Max = 0;
    for(int i=0; i!=3; ++i){
        if( Max < A.BCJ[i] ){
            Max = A.BCJ[i];
            ind = i;
        }
    }cout << Convert(ind) << " ";

    ind = 0; Max = 0;
    for(int i=0; i!=3; ++i){
        if( Max < B.BCJ[i] ){
            Max = B.BCJ[i];
            ind = i;
        }
    }cout << Convert(ind) << endl;
    return 0;
}

// Define J=0,B=1,C=2;
void Judge( const char A, const char B, Player &pA, Player &pB)
{
    char Table[3][3] = {{'T','W','L'},{'L','T','W'},{'W','L','T'}};
    int a, b;
    a = Convert( A ); b = Convert( B );
    switch (Table[a][b])
    {
        case 'T':
            ++(pA.WTL[1]);
            ++(pB.WTL[1]);
            break;
        case 'W':
            ++(pA.WTL[0]);
            ++(pB.WTL[2]);
            ++(pA.BCJ[a]);
            break;
        case 'L':
            ++(pA.WTL[2]);
            ++(pB.WTL[0]);
            ++(pB.BCJ[b]);
            break;
    }
}

int Convert( char C )
{
    if (C == 'B') return 0;
    else if (C == 'C') return 1;
    else if (C == 'J') return 2;
}

char Convert( const int i )
{
    if ( i == 0 ) return 'B';
    else if ( i == 1 ) return 'C';
    else if ( i == 2 ) return 'J';
}
