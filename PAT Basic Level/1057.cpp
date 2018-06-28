#include<cstdio>

int main()
{
//    freopen("in.txt", "r", stdin);
    char C;
    int sum=0;
    while( ( C=getchar() ) != '\n' )
    {
        if( C >= 'a' and C <='z' ) sum += C - 'a' + 1;
        if( C >= 'A' and C <='Z' ) sum += C - 'A' + 1;
    }
    int cnt0 = 0, cnt1 = 0;
    while( sum )
    {
        if( sum%2 == 0 ) ++cnt0;
        else ++cnt1;
        sum /= 2;
    }
    printf("%d %d", cnt0, cnt1);
}
