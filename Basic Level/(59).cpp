#include <cstdio>
#include <cmath>

const int MAXSIZE = 10000;

struct Person
{
    int Rank = 0;
    bool flag = false;
};

bool IsPrime( const int n );
void Search(Person P[], const int ID);

int main()
{
//    freopen("in.txt", "r", stdin);
    struct Person P[MAXSIZE];
    int N;
    scanf("%d", &N);
    for(int i=0; i!=N; ++i){
        int ID;
        scanf("%d", &ID);
        P[ID].Rank = i + 1;
    }
    scanf("%d", &N);
    for(int i=0; i!=N; ++i){
        int ID;
        scanf("%d", &ID);;
        Search(P, ID);
    }
//    for(int i=2; i!=100; ++i){
//        printf("%d %d\n", i, IsPrime(i));
//    }
    return 0;
}

void Search(Person P[], const int ID)
{
    if( 0 == P[ID].Rank ){
        printf("%04d: Are you kidding?\n", ID);
    }else if( true == P[ID].flag ){
        printf("%04d: Checked\n", ID);
    }else if( 1 == P[ID].Rank ){
        printf("%04d: Mystery Award\n", ID);
    }else{
        if( IsPrime( P[ID].Rank ) ){
            printf("%04d: Minion\n", ID);
        }else{
            printf("%04d: Chocolate\n", ID);
        }
    }
    P[ID].flag = true;
}

bool IsPrime( const int n )
{
    if( n == 2 ) return true;
    if( n%2 == 0 ) return false;
    int k = sqrt(n);
    int i = 0;
    for(i=3; i<=k; i+=2){
        if( n%i == 0 ) break;
    }
    if( i>k ) return true;
    else return false;
}
