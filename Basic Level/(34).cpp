#include <cstdio>

long long gcd( long long a, long long b )
{// Make sure that a > 0 and b > 0
    long long r = 0;
    while( 0 != b ){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void Simplify( long long &a, long long &b )
{
    if( 0 == b ){
        a = 1;
        return;
    }
    if( 0 == a ){
        b = 1;
        return;
    }
    bool IsMinus = ( a < 0 );
    IsMinus ^= ( b < 0 );
    a = ( a < 0 ) ? -a : a;
    b = ( b < 0 ) ? -b : b;
    long long GCD = gcd(a, b);
    a /= GCD, b /= GCD;
    if( IsMinus ) a = -a;
}

void Print( long long a, long long b )
{
    if( 0 == b ){
        printf("Inf");
        return;
    }
    if( 0 == a ){
        printf("0");
        return;
    }
    Simplify(a, b);
    bool IsMinus = ( a < 0 );
    a = ( a < 0 ) ? -a : a;
    if( 1 == b ){
        if( IsMinus ) printf("(-%lld)", a);
        else printf("%lld", a);
    }else if( a < b ){
        if( IsMinus ) printf("(-%lld/%lld)", a, b);
        else printf("%lld/%lld", a, b);
    }else if( a % b == 0 ){
        if( IsMinus ) printf("(-%lld)", a%b);
        else printf("%lld", a%b);
    }else{
        if( IsMinus ) printf("(-%lld %lld/%lld)", a/b, a%b, b);
        else printf("%lld %lld/%lld", a/b, a%b, b);
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);
    long long a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    Simplify(a1, b1), Simplify(a2, b2);
    // addition
    Print(a1, b1), printf(" + "), Print(a2, b2), printf(" = ");
    Print(a1*b2 + a2*b1, b1*b2), printf("\n");

    // substraction
    Print(a1, b1), printf(" - "), Print(a2, b2), printf(" = ");
    Print(a1*b2 - a2*b1, b1*b2), printf("\n");

    // addition
    Print(a1, b1), printf(" * "), Print(a2, b2), printf(" = ");
    Print(a1*a2, b1*b2), printf("\n");

    // addition
    Print(a1, b1), printf(" / "), Print(a2, b2), printf(" = ");
    Print(a1*b2, b1*a2), printf("\n");
    return 0;
}
