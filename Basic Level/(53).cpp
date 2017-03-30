#include <cstdio>

int main()
{
//    freopen("in.txt", "r", stdin);
    int N, D;
    double e;
    scanf("%d%lf%d", &N, &e, &D);
    int Maybe(0), Empty(0);
    for(int i=0; i!=N; ++i){
        int num;
        scanf("%d", &num);
        int MaybeEmpty(0);
        for(int j=0; j!=num; ++j){
            double tmp;
            scanf("%lf", &tmp);
            if( tmp < e ) ++MaybeEmpty;
        }
        if( MaybeEmpty > 0.5*num ){
            if( num > D ) ++Empty;
            else ++Maybe;
        }
    }
    double a = ( Maybe + .0 ) / N * 100;
    double b = ( Empty + .0 ) / N * 100;
    printf("%.1f%% %.1f%%\n", a, b);
    return 0;
}
