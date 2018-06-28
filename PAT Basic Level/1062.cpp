#include <cstdio>

int gcd( int a, int b )
{
    int r(0);
    while( b != 0 ){
        r = a%b;
        a = b;
        b =r;
    }
    return a;
}

void Simplify( int &a, int &b )
{
    int r = gcd(a, b);
    a /= r; b /= r;
}

void Swap( int &a, int &b )
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int a1, a2, b1, b2, k;
    scanf("%d/%d %d/%d %d", &a1, &b1, &a2, &b2, &k);
    Simplify(a1, b1); Simplify(a2, b2);
    if( a1 * b2 > a2 * b1 ){
        Swap(a1,a2);
        Swap(b1,b2);
    }
    int n(1);
    bool flag = false;
    while( a1 * k >= b1 * n ) ++n;
    while( a2 * k > b2 * n ){
        if( gcd(n, k) == 1 ){
            if( !flag )
                flag = true;
            else
                printf(" ");
            printf("%d/%d", n, k);
        }
        ++n;
    }
    printf("\n");
    return 0;
}
