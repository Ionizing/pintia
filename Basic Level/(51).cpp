#include <cstdio>
#include <cmath>

int main()
{
//    freopen("in.txt", "r", stdin);
    double R1, P1, R2, P2;
    scanf("%lf%lf%lf%lf", &R1, &P1, &R2, &P2);
    double P, R;
    P = P1 + P2;
    R = R1 * R2;
    double A = R*cos(P);
    double B = R*sin(P);
    if( fabs(A) < .01 ) { printf("0.00"); }
    else { printf("%.2f", A); }
    if( fabs(B) < .01 ) { printf("+0.00i"); }
    else if ( B < 0 ) { printf("%.2fi", B); }
    else { printf("+%.2fi", B); }
    return 0;
}
