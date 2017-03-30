#include <cstdio>
#include <vector>

using namespace std;

inline bool unExceed(const int A, const int B, const int Boundary)
{
    int ABS = ( (A-B) < 0 ) ? (B-A) : (A-B);
    return ( ABS <= Boundary );
}

struct Color
{
    int C;
    int x;
    int y;
};

bool IsUnique( const int Color, int Arr[], const int Size )
{
    int flag = false;
    for(int i=0; i!=Size; ++i){
        if( true == flag and Color == Arr[i] ) return false;
        else if( Color == Arr[i] ) flag = true;
    }
    return true;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int Width, Height, Boundary;
    scanf("%d%d%d", &Width, &Height, &Boundary);
    vector< vector<int> > Arr(Height);
    int *ColorLib = new int [Width*Height];
    int t=0;
    for(int i=0; i!=Height; ++i){
        Arr[i].resize(Width);
        for(int j=0; j!=Width; ++j){
            scanf("%d", &Arr[i][j]);
            ColorLib[t++] = Arr[i][j];
        }
    }

    int cnt(0);
    vector<struct Color> Possible;
    for(int i=0; i!=Height; ++i){
        for(int j=0; j!=Width; ++j){
            int curr = Arr[i][j];
            bool flag = false;
            int around[8];
            int l, r, u, d;
            l =        ( 0 == j ) ? j : j-1;
            r =  ( Width-1 == j ) ? j : j+1;
            u =        ( 0 == i ) ? i : i-1;
            d = ( Height-1 == i ) ? i : i+1;
            around[0] = Arr[u][l];
            around[1] = Arr[u][j];
            around[2] = Arr[u][r];
            around[3] = Arr[i][l];
            around[4] = Arr[i][r];
            around[5] = Arr[d][l];
            around[6] = Arr[d][j];
            around[7] = Arr[d][r];
            for(int k=0; k!=8; ++k){
                if( 0 == j ){
                    if ( 0==k or 3==k or 5==k ) continue;
                }
                if( Width-1 == j ){
                    if ( 2==k or 4==k or 7==k ) continue;
                }
                if( 0 == i ){
                    if( k<=2 ) continue;
                }
                if( Height-1 == i ){
                    if( k>=5 ) continue;
                }
                flag = ( flag or unExceed(curr, around[k], Boundary) );
            }
//            printf("(%d, %d): %d, flag:%d\n", j+1, i+1, curr, flag);
            if( flag == false ){
                ++cnt;
                Color tmp;
                tmp.C = curr, tmp.x = j+1, tmp.y = i+1;
                Possible.push_back( tmp );
            }
        }
    }

    if( 0 == cnt ) printf("Not Exist\n");
    else if( 1 == cnt ) printf("(%d, %d): %d\n", Possible[0].x, Possible[0].y, Possible[0].C);
    else{
        int posunique = 0; // Possible unique
        int posind = 0; // index of Possible unique
        for(int i=0; i!=cnt; ++i){
            if( IsUnique(Possible[i].C, ColorLib, Width*Height) ){
                ++posunique;
                posind = i;
            }
        }
        if( posunique != 1 )
            printf("Not Unique\n");
        else{
            printf("(%d, %d): %d\n", Possible[posind].x, Possible[posind].y,Possible[posind].C);
        }
    }
    return 0;
}
