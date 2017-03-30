#include <cstdio>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
    size_t N;
    scanf("%d", &N);
    size_t* School = new size_t[N+1];
    for(size_t i=0; i!=N+1; ++i){
        School[i] = 0;
    }
    size_t Index = 1;
    for(size_t i=0; i!=N; ++i){
        size_t ind, points;
        scanf("%d%d", &ind, &points);
        School[ind] += points;
        Index = ( ind > Index ) ? ind : Index;
    }
    size_t MaxScore = 0;
    size_t MaxIndex = 1;
    for(size_t i=1; i!=Index+1; ++i){
        if( MaxScore < School[i] ){
            MaxScore = School[i];
            MaxIndex = i;
        }
    }
    printf("%d %d\n", MaxIndex, MaxScore);
    return 0;
}
