#include <cstdio>

int main()
{
//    freopen("in.txt", "r", stdin);
    int G0, S0, K0;
    scanf("%d.%d.%d", &G0, &S0, &K0);
    int G1, S1, K1;
    scanf("%d.%d.%d", &G1, &S1, &K1);
    int sum = (G1-G0)*29*17 + (S1-S0)*29 + (K1-K0);
    if( sum < 0 ){
        printf("-");
        sum = -sum;
    }
    printf("%d.%d.%d\n", sum/(29*17), sum%(29*17)/29, sum%(29*17)%29 );
}
