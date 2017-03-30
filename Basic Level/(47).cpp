#include <cstdio>

const int MAXSIZE = 1001;

int main()
{
//    freopen("in.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    int Teams[MAXSIZE] = {0};
    for(int i=0; i!=N; ++i){
        int TeamID, Member, Score;
        scanf("%d-%d %d", &TeamID, &Member, &Score);
        Teams[TeamID] += Score;
    }
    int MaxScore = 0, MaxInd = 0;
    for(int i=0; i!=MAXSIZE; ++i){
        if( MaxScore < Teams[i] ){
            MaxScore = Teams[i];
            MaxInd = i;
        }
    }
    printf("%d %d\n", MaxInd, MaxScore);
    return 0;
}
