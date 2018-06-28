#include <cstdio>

using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
    int M, N, A, B, C;
    scanf("%d%d%d%d%d", &M, &N, &A, &B, &C);
    int tmp;
    for(int i=0; i!=M; ++i){
        for(int j=0; j!=N; ++j){
            scanf("%d", &tmp);
            if( tmp >= A and tmp <= B ){
                tmp = C;
            }
            printf("%03d", tmp);
            if( j!= N-1 ) printf(" ");
        }
        printf("\n");
    }
    return 0;
}