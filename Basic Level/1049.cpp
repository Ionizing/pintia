#include <cstdio>

using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    double Res = 0;
    for(int i=0; i!=N; ++i){
        double tmp;
        scanf("%lf", &tmp);
        Res += tmp * (i+1) * (N-i);
    }
    printf("%.2f\n", Res);
    return 0;
}
