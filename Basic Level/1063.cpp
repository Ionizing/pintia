#include <cstdio>
#include <cmath>

int main()
{
//    freopen("in.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    double Max = 0.0;
    for(int i=0; i!=N; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        double Res = sqrt( a*a + b*b );
        Max = ( Res > Max ) ? Res : Max;
    }
    printf("%.2f\n", Max);
    return 0;
}
