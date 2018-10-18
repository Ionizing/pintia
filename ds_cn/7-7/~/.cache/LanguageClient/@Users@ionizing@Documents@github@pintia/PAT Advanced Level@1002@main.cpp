#include <cstdio>

const int MAXSIZE = 1001;

inline bool Judge( const double A )
{
    return ( A >= .05 or A <= -.05 );
}

int main()
{
//    freopen("in.txt", "r", stdin);
    double PolyNom[MAXSIZE] = {.0};
    int K;
    scanf("%d", &K);
    for(int i=0; i!=K; ++i){
        int ind; double coeff;
        scanf("%d%lf", &ind, &coeff);
        PolyNom[ind] += coeff;
    }
    scanf("%d", &K);
    for(int i=0; i!=K; ++i){
        int ind; double coeff;
        scanf("%d%lf", &ind, &coeff);
        PolyNom[ind] += coeff;
    }
    int k=0;
    for(int i=0; i!=MAXSIZE; ++i){
        if( Judge( PolyNom[i] ) ) ++k;
    }
    if( 0 == k ){
        printf("0\n");
        return 0;
    }else printf("%d", k);
    int i;
    for(i=MAXSIZE-1; i>=0 and k!=0; --i){
        if( Judge(PolyNom[i]) ){
            printf(" %d %.1f", i, PolyNom[i]);
            --k;
        }
    }
    printf("\n");
    return 0;
}
